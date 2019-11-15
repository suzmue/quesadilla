def generate_header(order, datatypes):
    # TODO: check which of this I need.
    print ("#include <cstdio>\n#include <cstdlib>\n")

    print("\nstruct coo_t\n{")
    for mode in range(order):
        print("\t" + datatypes[mode] + "\tidx" + str(mode) + ";")
        
    print("\t" + datatypes[order] + "\tval;")
    print("};\n\n")

def generate_function(suffix, permutation, order, datatypes, dimensions, schedule):
    perm_str = ""
    for m in permutation:
        perm_str += str(m)
    print("// transpose permutes the modes of the coordinates to be " + str(permutation))
    print("int transpose_coo_" + perm_str + "_" + suffix + "(struct coo_t *C_coords, int c_size, int order, int *dimensions) {")
    print("\tstruct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);")
    print("\tint* perm = (int *)malloc(sizeof(int) * c_size);")
    print()

    # TODO: generate sorts
    generate_sorts(permutation, order, datatypes, dimensions, schedule)

    # TODO: free things.
    print("\t// Free the scratch space.")
    print("\tfree(C_coords_scratch);")
    print("\tfree(perm);")

    for sort_item in schedule:
        mode, fixed = sort_item
        print("\tfree(B" + str(mode) + "_count);")
        if len(fixed) > 0:
            ident = str(mode)
            for f in fixed:
                ident += str(f)
            print("\tfree(bucket_" + ident + ");")
            print("\tfree(quotient_" + ident + ");")



    print("\treturn 0;")
    print("}")


def generate(permutation, order, datatypes, dimensions, schedule):
    generate_header(order, datatypes)

    generate_function("", permutation, order, datatypes, dimensions, schedule)

def generate_hist_sort(mode, datatypes):
    print()
    print("\t// Histogram sort on mode " + str(mode))
    print("\tint B" + str(mode) + "_size = dimensions["+ str(mode) + "];")
    print("\tint32_t *B" + str(mode) + "_count = (int32_t *)calloc(B" + str(mode) + "_size, sizeof(int32_t));")
    print("\tfor( int i = 0; i < c_size; i++)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_coords[i].idx" + str(mode) + ";")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]++;")
    print("\t}")
    print("\n\t// Prefix sum over B" + str(mode) + "_count")
    print("\tfor(int idx" + str(mode) + " = 1; idx" + str(mode) + " <= B" + str(mode) + "_size; idx" + str(mode) + " ++)")
    print("\t{")
    print("\t\tB"+ str(mode) + "_count[idx" + str(mode) + "] += B"+ str(mode) + "_count[idx" + str(mode) + " - 1];" )
    print("\t}")
    print("\tfor( int i = c_size - 1; i >= 0; i--)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_coords[i].idx" + str(mode) + ";")
    print("\t\tint idx = B" + str(mode) + "_count[idx" + str(mode) + "] - 1;")
    print("\t\tC_coords_scratch[idx] = C_coords[i];")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]--;")
    print("\t}")
    print("\n\tmemcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));\n")


def generate_fix(mode, fixed, datatypes):
    ident = str(mode)
    for f in fixed:
        ident += str(f)

    print("\t// Create buckets and quotient")
    print("\tint *bucket_" + ident + " = (int *)malloc(c_size*sizeof(int));")
    print("\tint *quotient_" + ident + " = (int *)malloc(c_size*sizeof(int));")
    print("\tint current_" + ident + " = 0;")
    print("\tbucket_" + ident + "[0] = 0;")
    print("\tquotient_" + ident + "[0] = 0;")
    print("\tfor(int i = 1; i < c_size; i ++)")
    print("\t{")
    for m in fixed:
        print("\t\tif(C_coords[i].idx" + str(m) + " != C_coords[i - 1].idx" + str(m) + ") {")
        print("\t\t\tcurrent_" + ident + "++;")
        print("\t\t\tquotient_" + ident + "[current_" + ident + "] = i;")
        print("\t\t}")
    print("\t\tbucket_" + ident + "[i] = current_" + ident + ";")
    print("\t}")

    print()
    print("\t// Histogram sort on mode " + str(mode) + " into the permutation array")
    print("\tint B" + str(mode) + "_size = dimensions["+ str(mode) + "];")
    print("\tint32_t *B" + str(mode) + "_count = (int32_t *)calloc(B" + str(mode) + "_size, sizeof(int32_t));")
    print("\tfor( int i = 0; i < c_size; i++)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_coords[i].idx" + str(mode) + ";")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]++;")
    print("\t}")
    print("\n\t// Prefix sum over B" + str(mode) + "_count")
    print("\tfor(int idx" + str(mode) + " = 1; idx" + str(mode) + " < B" + str(mode) + "_size; idx" + str(mode) + " ++)")
    print("\t{")
    print("\t\tB"+ str(mode) + "_count[idx" + str(mode) + "] += B"+ str(mode) + "_count[idx" + str(mode) + " - 1];" )
    print("\t}")
    print("\tfor( int i = 0; i < c_size; i++)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_coords[i].idx" + str(mode) + ";")
    print("\t\tint idx = B" + str(mode) + "_count[idx" + str(mode) + "] - 1;")
    print("\t\tC_coords_scratch[idx] = C_coords[i];")
    print("\t\tperm[idx] = bucket_" + ident + "[i];")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]--;")
    print("\t}")


def generate_fix_and_sort(sort_item, datatypes):
    mode, fixed = sort_item[0], sort_item[1]
    if len(fixed) == 0:
        generate_hist_sort(mode, datatypes)
        return

    print("\t// Fix and sort on " + str(fixed))

    generate_fix(mode, fixed, datatypes)

    ident = str(mode)
    for f in fixed:
        ident += str(f)
    print("\n\t// Move the items back to the buckets.")
    print("\tfor (int i = 0; i < c_size; i ++) {")
    print("\t\tC_coords[quotient_" + ident + "[bucket_" + ident + "[perm[i]]]] = C_coords_scratch[perm[i]];")
    print("\t\tquotient_" + ident + "[perm[i]] ++;")
    print("\t}")


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
    order = 3
    perm = [2,0,1]
    datatypes = ["int32_t", "int32_t", "int32_t", "double"]
    dims = [25,25,10]
    generate_header(3,datatypes)
    # 3 schedules

    # Schedule 012
    schedule = [(0,[]), (1,[0]), (2,[])]
    generate_function("012_3",perm, 3, datatypes, dims, schedule)

    # Schedule 021
    schedule = [(0,[]), (2,[]), (1,[0,2])]
    generate_function("021_3", perm, 3, datatypes, dims, schedule)

    # Schedule 102
    schedule = [(1,[]), (0,[]), (2,[])]
    generate_function("102_3", perm, 3, datatypes, dims, schedule)

    # Schedule 120
    schedule = [(1,[]),  (2,[]), (0, [2])]
    generate_function("120_3", perm, 3, datatypes, dims, schedule)

    # Schedule 201
    schedule = [ (2,[]), (0, [2]), (1, [0,2])]
    generate_function("201_3", perm, 3, datatypes, dims, schedule)

    # Schedule 210
    schedule = [(2,[]), (1, [2]), (0, [2])]
    generate_function("210_3", perm, 3, datatypes, dims, schedule)

    # 2 Schedule

    # 01
    # schedule = [(0,[]), (1, []),]
    # generate_function("01_2", perm, 3, datatypes, dims, schedule)
    # 02
    schedule = [(0,[]), (2, []),]
    generate_function("02_2", perm, 3, datatypes, dims, schedule)
    # 10
    # schedule = [(1,[]), (0, [1]),]
    # generate_function("10_2", perm, 3, datatypes, dims, schedule)
    # 12
    schedule = [(1,[0]), (2, []),]
    generate_function("12_2", perm, 3, datatypes, dims, schedule)
    # 20
    schedule = [(2,[]), (0, []),]
    generate_function("20_2", perm, 3, datatypes, dims, schedule)
    # 21
    schedule = [(2,[]), (1, [0,2]),]
    generate_function("21_2", perm, 3, datatypes, dims, schedule)

    # 1 schedule
    # schedule = [(0,[])]
    # generate_function("0_1", perm, 3, datatypes, dims, schedule)

    # schedule = [(1,[])]
    # generate_function("1_1", perm, 3, datatypes, dims, schedule)

    schedule = [(2,[])]
    generate_function("2_1", perm, 3, datatypes, dims, schedule)
    # 0 Schedule
    # schedule = []
    # generate_function("0", perm, 3, datatypes, dims, schedule)


if __name__ == "__main__": main()