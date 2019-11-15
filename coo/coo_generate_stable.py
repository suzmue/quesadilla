def generate_merge_sort(mode):
    print("// merge_" + str(mode) + "_sort performs a merge sort comparing on " + str(mode))
    print("void merge_"+ str(mode) + "_sort(struct coo_t* C, struct coo_t* C_scratch, int start, int end)")
    print("{")
    print("\tif(end > start + 1)")
    print("\t{")
    print("\t\tint m = start + (end - start) / 2;")
    print("\t\tmerge_" + str(mode) + "_sort(C, C_scratch, start, m);")
    print("\t\tmerge_" + str(mode) + "_sort(C, C_scratch, m, end);")
    print("\t\t// Copy to scratch space")
    print("\t\tmemcpy(&C_scratch[start], &C[start], sizeof(struct coo_t)*(end-start));")
    print("\t\tint i = start;")
    print("\t\tint s_i = start;")
    print("\t\tint e_i = m;")
    print("\t\twhile(s_i < m && e_i < end)")
    print("\t\t{")
    print("\t\t\tif(C_scratch[s_i].idx" + str(mode) + " <=  C_scratch[e_i].idx" + str(mode) + ")")
    print("\t\t\t{")
    print("\t\t\t\tC[i] = C_scratch[s_i];")
    print("\t\t\t\ts_i ++;")
    print("\t\t\t} else {")
    print("\t\t\t\tC[i] = C_scratch[e_i];")
    print("\t\t\t\te_i ++;")
    print("\t\t\t}")
    print("\t\t\ti++;")
    print("\t\t}")
    print("\t\t// Add any remaining s_i")
    print("\t\twhile(s_i < m)")
    print("\t\t{")
    print("\t\t\tC[i] = C_scratch[s_i];")
    print("\t\t\ts_i ++;")
    print("\t\t\ti++;")
    print("\t\t}")
    print("\t\t// Add any remaining e_i")
    print("\t\twhile(e_i < end)")
    print("\t\t{")
    print("\t\t\tC[i] = C_scratch[e_i];")
    print("\t\t\te_i ++;")
    print("\t\t\ti++;")
    print("\t\t}")
    print("\t}")
    print("}")
    print()

def generate_merge_sorts(order):
    for m in range(order):
        generate_merge_sort(m)


def generate_header(order, datatypes):
    # TODO: check which of this I need.
    print ("#include <cstdio>\n#include <cstdlib>\n")

    print("\nstruct coo_t\n{")
    for mode in range(order):
        print("\t" + datatypes[mode] + "\tidx" + str(mode) + ";")
        
    print("\t" + datatypes[order] + "\tval;")
    print("};\n\n")

def generate_function(permutation, order, datatypes, dimensions, schedule):
    perm_str = ""
    for m in permutation:
        perm_str += str(m)
    print("// transpose permutes the modes of the coordinates to be " + str(permutation))
    print("int transpose_coo_" + perm_str + "(struct coo_t *C_coords, int c_size, int order, int *dimensions) {")
    print("\tstruct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);")
    print("\tint* perm = (int *)malloc(sizeof(int) * c_size);")
    print()

    # TODO: generate sorts
    generate_sorts(permutation, order, datatypes, dimensions, schedule)

    # TODO: free things.
    print("\t// Free the scratch space.")
    print("\tfree(C_coords_scratch);")
    print("\tfree(perm);")


    print("\treturn 0;")
    print("}")



def generate(permutation, order, datatypes, dimensions, schedule):
    generate_header(order, datatypes)

    generate_merge_sorts(order)

    generate_function(permutation, order, datatypes, dimensions, schedule)

def generate_fix(mode, fixed, datatypes):
    ident = ""
    for f in fixed:
        ident += str(f)

    print("\t// Create buckets and quotient")
    print("\tint start_" + ident + " = 0;")
    print("\tfor(int j = 1; j < c_size; j ++)")
    print("\t{")
    for m in fixed:
        print("\t\tif(C_coords[j].idx" + str(m) + " != C_coords[j - 1].idx" + str(m) + ") {")
        print("\t\t\tmerge_" + str(mode) + "_sort(C_coords, C_coords_scratch, start_" + ident+ ", j);")
        print("\t\t\tstart_" + ident + " = j;")
        print("\t\t\tcontinue;")
        print("\t\t}")
    print("\t}")


def generate_fix_and_sort(sort_item, datatypes):
    mode, fixed = sort_item[0], sort_item[1]
    if len(fixed) == 0:
        print("\t// Sort on " + str(mode))
        print ("\tmerge_" + str(mode) + "_sort(C_coords, C_coords_scratch, 0, c_size);")
        return

    print("\t// Fix and sort on " + str(fixed))
    generate_fix(mode, fixed, datatypes)
    


def generate_sorts(permutation, order, datatypes, dimensions, schedule):
    print("\t// Sort the coordinates to be in " + str(permutation))
    for sort_item in schedule:
        generate_fix_and_sort(sort_item,  datatypes)


def get_schedule(permutation):
    schedule = []
    current = []
    fixed = []
    for i in range(len(permutation)):
        # Check if it needs to be sorted.
        needs_sort = False
        for j in range(i + 1, len(permutation)):
            if permutation[j] < permutation[i]:
                needs_sort = True

        if needs_sort:
            current.append(permutation[i])
            continue

        for j in range(len(current) - 1, -1, -1):
            schedule.append( (current[j], fixed.copy()))

        for mode in current:
            fixed.append(mode)

        fixed.append(permutation[i])

        current = []

    return schedule



def main():
    ORDER = 5
    from itertools import permutations
    order = [i for i in range(ORDER)]
    # perms = permutations(order)
    # for perm in perms:
    #     print (get_schedule(perm))
    # perm = [0,1,2,4,3]
    # schedule = get_schedule(perm)
    # generate(perm, 5, ["int32_t", "int8_t", "int32_t","int8_t", "int32_t", "double"], [25,25,10,100,10],schedule)
    # perm = [1,0,3,2]
    # schedule = get_schedule(perm)
    # generate(perm, 4, ["int32_t", "int8_t", "int32_t","int8_t", "double"], [25,25,10,100], schedule)
    perm = [ 1,0,2]
    schedule = get_schedule(perm)
    generate(perm, 3, ["int32_t", "int32_t", "int32_t", "double"], [25,25,10], schedule)





if __name__ == "__main__": main()