
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

def get_splits(permutation):
    splits = []
    current_split = []
    last = 0
    for i in range (0, len(permutation)):
        current_split.append(permutation[i])
        last = max(permutation[i], last)
        if i == last:
            splits.append(current_split.copy())
            current_split = []
    return splits

def needs_coords(split, schedule):
    for mode in split:
        for srt in schedule:
            if mode == srt[0]:
                return True
    return False


def generate_header():
    print ("#include <stdint.h>\n#include <cstdlib>\n#include <cstdio>\n#include <iostream>\n#include <vector>\n")

    print ("// Include the taco tensor type.")
    print ("typedef struct taco_tensor_t {\n\
\tint32_t\t\torder;         // tensor order (number of modes)\n\
\tint32_t*\tdimensions;    // tensor dimensions\n\
\tuint8_t***\tindices;       // tensor index data (per mode)\n \
\tuint8_t*\tvals;          // tensor values\n\
\tint32_t\t\tvals_size;     // values array size\n\
} taco_tensor_t;\n")

def generate_split_type(split, datatypes):
    # TODO: we don't need to do permutation for all.
    name = "coo_"
    for mode in split:
        name += str(mode)
    name += "_t"

    print("\nstruct " + name + "\n{")
    for mode in split:
        print("\t" + datatypes[mode] + "\tidx" + str(mode) + ";")
        
    print("\tint32_t\tperm;")
    print("};\n\n")
    return name

def generate_function_preamble(order, datatypes, dimensions):
    # TODO(suzmue): Do not need to make the sizes of the dimensions as big.
    for i in range(order):
        print ("\tint32_t B" + str(i) + "_size = B->dimensions[" + str(i) + "];")

    print("\n")
    for i in range(order):
        print ("\tint *A" + str(i) + "_pos_arr = (int *)A->indices[" + str(i) + "][0];")
        print ("\tint *A" + str(i) + "_idx_arr = (int *)A->indices[" + str(i) + "][1];")
    print("\n")
    for i in range(order):
        print ("\tint *B" + str(i) + "_pos_arr = (int *)B->indices[" + str(i) + "][0];")
        print ("\tint *B" + str(i) + "_idx_arr = (int *)B->indices[" + str(i) + "][1];")
    print("\n")

def generate_unpack_loop(mode, order, end, datatypes, splits, split_names, schedule):
    if mode == order:
        return #TODO add more here.
    
    prefix = "\t"*(mode + 1)
    print(prefix + "for (int32_t B" + str(mode)+ "_pos = B" + str(mode)+ "_pos_arr[0]; B" + str(mode)+ "_pos < B" + str(mode)+ "_pos_arr[" + str(end) + "]; B" + str(mode)+ "_pos++)")
    print(prefix + "{")
    print(prefix + "\tint B"+ str(mode) + "_end = B" + str(mode) + "_pos + 1;")
    # TODO: we don't necessarily need all of the idx.
    print(prefix + "\t" + datatypes[mode] + " idx" + str(mode) + " = B" + str(mode) + "_idx_arr[B" + str(mode) + "_pos];")

    # TODO: cut off some of the loops if necessary.
    generate_unpack_loop(mode + 1, order, "B" + str(mode) + "_end", datatypes, splits, split_names, schedule)
    
    # TODO: if we are the last mode in a split, add coordinate to the list, increase the size.
    for i in range(len(splits)):
        split = splits[i]
        if not needs_coords(split, schedule):
            continue
        larger = True
        contains = False
        for m in split:
            if m == mode:
                contains = True
                continue
            if mode < m:
                larger = False
        if contains and larger:
            print()
            print(prefix + "\t// Store into coordinates list.")
            # TODO: check capacity
            print(prefix + "\tif (C_" + str(i) + "_capacity <= (c_" + str(i) + "_size + 1))")
            print(prefix + "\t{")
            print(prefix + "\t\tint32_t C_capacity_new = 2 * (c_" + str(i) + "_size + 1);")
            print(prefix + "\t\tC_" + str(i) + "_coords = (struct" + split_names[i] + " *)realloc(C_" + str(i) + "_coords, sizeof(struct " + split_names[i] + ") * C_capacity_new);")
            print(prefix + "\t\tC_" + str(i) + "_capacity = C_capacity_new;")
            print(prefix + "\t}")
            # TODO: add item
            tprefix = prefix + "\t"
            for m in split:
                # TODO
                idx = "idx" + str(m)
                print(tprefix + "C_"+ str(i) + "_coords[c_" + str(i)+ "_size]." + idx + " = " + idx + ";")
                continue
            # TODO: add permutation.
            print(tprefix + "C_"+ str(i) + "_coords[c_" + str(i)+ "_size].perm = B" + str(mode) + "_pos;")
            print(tprefix + "c_" + str(i)+ "_size++;")
            continue

    print(prefix + "}")

def generate_unpack(permutation, order, datatypes, dimensions, splits, split_names, schedule):
    print ("\t// Unpack B into the COO types")

    # TODO(suzmue): we don't need this many, we can already see how much we would have.
    print("\tint32_t init_alloc_size = 1048576;\n")

    # Create arrays to store values for all of the splits.
    for i in range(len(splits)):
        if needs_coords(splits[i], schedule):
            cap_name = "C_" + str(i) + "_capacity"
            name = split_names[i]
            print("\tint " + cap_name + " = init_alloc_size;")
            print("\tstruct " + name + "* C_" + str(i) + "_coords = (struct " + name + " *)malloc(sizeof(struct " + name +") * "+ cap_name + ");")
            print("\tint c_"+str(i)+ "_size= 0;")
            print()

    # TODO: generate subtree size loop.
    pos_length_needed = []
    for i in range(len(splits)):
        split = split[i]
        if needs_coords(splits[i], schedule):
            min_mode = split[i][0]
            for m in split[i]:
                if m < min_mode:
                    min_mode = m
            pos_length_needed.append(min_mode)
    if len(pos_length_needed) > 0:
        print()

    # Iterate over and store into splits.
    generate_unpack_loop(0, order, 1, datatypes, splits, split_names, schedule)
    print()

def generate_scratch_space(permutation, order, datatypes, dimensions, splits, split_names, schedule):
    for i in range(len(splits)):
        if needs_coords(splits[i], schedule):
            name = split_names[i]
            print("\tstruct " + name + "* C_" + str(i) + "_coords_scratch = (struct " + name + " *)malloc(sizeof(struct " + name +") * c_"+ str(i) + "_size);")
            print()


def generate_hist_sort(mode, splitI, split_names, datatypes):
    print()
    print("\t// Histogram sort on mode " + str(mode))
    print("\tint32_t *B" + str(mode) + "_count = (int32_t *)calloc(B" + str(mode) + "_size, sizeof(int32_t));")
    print("\tfor( int i = 0; i < c_"+ str(splitI) + "_size; i++)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_" + str(splitI) + "_coords[i].idx" + str(mode) + ";")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]++;")
    print("\t}")
    print("\n\t// Prefix sum over B" + str(mode) + "_count")
    print("\tfor(int idx" + str(mode) + " = 1; idx" + str(mode) + " < B" + str(mode) + "_size; idx" + str(mode) + " ++)")
    print("\t{")
    print("\t\tB"+ str(mode) + "_count[idx" + str(mode) + "] += B"+ str(mode) + "_count[idx" + str(mode) + " - 1];" )
    print("\t}")
    print("\tfor( int i = 0; i < c_"+ str(splitI) + "_size; i++)")
    print("\t{")
    print("\t\t"+ datatypes[mode] + " idx" + str(mode) + " = C_" + str(splitI) + "_coords[i].idx" + str(mode) + ";")
    print("\t\tint idx = B" + str(mode) + "_count[idx" + str(mode) + "] - 1;")
    print("\t\tC_"+ str(splitI) + "_coords_scratch[idx] = C_"+ str(splitI) + "_coords[i];")
    print("\t\tB" + str(mode) + "_count[idx" + str(mode) + "]--;")
    print("\t}")
    print("\n\tmemcpy(C_" + str(splitI) + "_coords, C_" + str(splitI) + "_coords_scratch, c_" + str(splitI) + "_size*sizeof(struct " + split_names[splitI] + "));\n")


def generate_fix_and_sort(mode, fixed, splits, splitI, split_names, datatypes):
    print("\tFix and sort on " + str(fixed))
    local_fix = []
    for fix in fixed: 
        for sp in splits[splitI]:
            if fix == sp:
                local_fix.append(fix)

    # TODO: Iterate over and create buckets.
    

    generate_hist_sort(mode, splitI, split_names, datatypes)

    # TODO: Move them back to their buckets.

def generate_sort(splitI, sort_item, split_names, datatypes):
    generate_hist_sort(sort_item[0], splitI, split_names,  datatypes)
    
def generate_sorts(permutation, order, datatypes, dimensions, splits, split_names, schedule):
    print("\t// Sort the coordinates to be in " + str(permutation))
    for sort_item in schedule:
        for i in range(len(splits)):
            for m in splits[i]:
                if m == sort_item[0]:
                    generate_sort(i, sort_item, split_names, datatypes)
    print("\t// TODO(suzmue): implement this.")

def generate_function(permutation, order, datatypes, dimensions, splits, split_names, schedule):
    print("// transpose permutes the modes of tensor B into tensor A as: " + str(permutation))
    print("int transpose(struct taco_tensor_t *A, struct taco_tensor_t *B) {")
    generate_function_preamble(order, datatypes, dimensions)
    # TODO: create the subtree arrays for each coordinate list.
    generate_unpack(permutation, order, datatypes, dimensions, splits, split_names, schedule)
    generate_scratch_space(permutation, order, datatypes, dimensions, splits, split_names, schedule)

    # TODO: generate sorts
    generate_sorts(permutation, order, datatypes, dimensions, splits, split_names, schedule)
    # TODO: generate pack

    # TODO: generate post pack.

    print("\treturn 0;")
    print("}")


def generate(permutation, order, datatypes, dimensions, splits, schedule):
    generate_header()

    split_names = {}
    for i in range (len(splits)):
        split = splits[i]
        if needs_coords(split, schedule):
            name = generate_split_type(split, datatypes)
            split_names[i] = name

    generate_function(permutation, order, datatypes, dimensions, splits, split_names, schedule)



def main():
    ORDER = 5
    from itertools import permutations
    order = [i for i in range(ORDER)]
    # perms = permutations(order)
    # for perm in perms:
    #     print (get_splits(perm))
    #     print (get_schedule(perm))
    # perm = [0,1,2,4,3]
    # splits = get_splits(perm)
    # schedule = get_schedule(perm)
    # generate(perm, 5, ["int32_t", "int8_t", "int32_t","int8_t", "int32_t"], [25,25,10,100,10],splits, schedule)
    # perm = [1,0,3,2]
    # splits = get_splits(perm)
    # schedule = get_schedule(perm)
    # generate(perm, 4, ["int32_t", "int8_t", "int32_t","int8_t"], [25,25,10,100],splits, schedule)
    perm = [2, 1, 0]
    splits = get_splits(perm)
    schedule = get_schedule(perm)
    generate(perm, 3, ["int32_t", "int8_t", "int32_t"], [25,25,10],splits, schedule)





if __name__ == "__main__": main()