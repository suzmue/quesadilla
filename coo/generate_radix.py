def generate_header(order, datatypes):
    print("""
#include <iostream>
#include "taco.h"
#include "taco/util/timers.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

#include "taco/tensor.h"
#include "taco/format.h"
#include "taco/error.h"
#include "taco/util/strings.h"
#include "taco/util/files.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
""")
    print("\nstruct coo_t\n{")
    for mode in range(order):
        print("\t" + datatypes[mode] + "\tidx" + str(mode) + ";")
        
    print("\t" + datatypes[order] + "\tval;")
    print("};\n\n")

    print("using namespace taco;")


def generate_function(suffix, permutation, order, datatypes, dimensions, schedule):
    perm_str = ""
    for m in permutation:
        perm_str += str(m)
    func_header = "int transpose_coo_" + perm_str + "_" + suffix + "(struct coo_t *C_coords, int c_size, int order, int *dimensions)"
    print("// transpose permutes the modes of the coordinates to be " + str(permutation))
    print(func_header + " {")
    # start timer
    if TIME_ALL:
        print("\ttaco::util::Timer timer;")
        print("\ttimer.start();")

    if len(schedule) > 0:
        print("\tstruct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);")
        print("\tint* perm = (int *)malloc(sizeof(int) * c_size);")
    print()

    # Generate the K-sadilla sorts
    generate_sorts(permutation, order, datatypes, dimensions, schedule)

    # Free things.
    if len(schedule) > 0:
        print("\t// Free the scratch space.")
        print("\tfree(C_coords_scratch);")
        print("\tfree(perm);")

    # end timer
    if TIME_ALL:
        print("\ttimer.stop();")
        print("\ttaco::util::TimeResults res = timer.getResult();")  
        print("\tcout << \" |  " + str(schedule) + " \";")
        print("\tcout << \" | \"<< res ;")

    print("\treturn 0;")
    print("}")


def generate(permutation, order, datatypes, dimensions, schedule):
    generate_header(order, datatypes)
    generate_function("", permutation, order, datatypes, dimensions, schedule, len(permutation))

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
    print("\tfor(int idx" + str(mode) + " = 1; idx" + str(mode) + " < B" + str(mode) + "_size; idx" + str(mode) + " ++)")
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

    print("\n\tfree(B" + str(mode) + "_count);")


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
    for i in range (len(fixed)):
        fi = "if"
        if i != 0:
            fi = "else if"
        m = fixed[i]
        print("\t\t" + fi + "(C_coords[i].idx" + str(m) + " != C_coords[i - 1].idx" + str(m) + ") {")
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
    print("\tfree(bucket_" + ident + ");")


# TODO There was a bad bug here
def generate_fix_and_sort(sort_item, datatypes):
    mode, fixed = sort_item[0], sort_item[1]
    ident = str(mode)
    if len(fixed) == 0:
        if TIME_PASS:
            print("\ttaco::util::Timer timer_" + ident + ";")
            print("\ttimer_" + ident + ".start();")

        generate_hist_sort(mode, datatypes)
        if TIME_PASS:
            print("\ttimer_" + ident + ".stop();")
            print("\ttaco::util::TimeResults res_" + ident + " = timer_" + ident + ".getResult();")   
            print("\tcout << \" | " + str(sort_item) + " \";")
            print("\tcout << \" | \"<< res_" + ident + " ;")

        return

    print("\t// Fix and sort on " + str(fixed))
    for f in fixed:
        ident += str(f)
    
    if TIME_PASS:
        print("\ttaco::util::Timer timer_" + ident + ";")
        print("\ttimer_" + ident + ".start();")


    generate_fix(mode, fixed, datatypes)


    print("\n\t// Move the items back to the buckets.")
    print("\tfor (int i = 0; i < c_size; i ++) {")
    print("\t\tC_coords[quotient_" + ident + "[perm[i]]] = C_coords_scratch[i];")
    print("\t\tquotient_" + ident + "[perm[i]] ++;")
    print("\t}")

    print("\tfree(quotient_" + ident + ");")
    if TIME_PASS:
        print("\ttimer_" + ident + ".stop();")
        print("\ttaco::util::TimeResults res_" + ident + " = timer_" + ident + ".getResult();")   
        print("\tcout << \" | " + str(sort_item) + " \";")
        print("\tcout << \" | \"<< res_" + ident + " ;")


def generate_cmp(perm):
    ident = ""
    for j in perm:
        ident += str(j)
    print("int cmp_" + ident + "(const void *p, const void *q)")
    print("{")
    print("\tstruct coo_t * r = (struct coo_t *)p;")
    print("\tstruct coo_t * s = (struct coo_t *)q;")
    for i in perm:
        print("\tif(r->idx" + str(i) + " < s->idx" + str(i) + ") {")
        print("\t\treturn -1;")
        print("\t} else if (r->idx" + str(i) + " > s->idx" + str(i) + ") {")
        print("\t\treturn 1;")
        print("\t}")

    print("\treturn 0;")
    print("}")



def generate_sorts(permutation, order, datatypes, dimensions, schedule):
    print("\t// Sort the coordinates to be in " + str(permutation))
    for sort_item in schedule:
        generate_fix_and_sort(sort_item,  datatypes)


def get_schedule(permutation):
    schedule = []
    for m in permutation:
        schedule = [(m, [])] + schedule
    return schedule

def generate_all_functions(ORDER, datatypes, dims):
    from itertools import permutations
    order = [i for i in range(ORDER)]
    perms = permutations(order)
    for perm in perms:
        schedule = get_schedule(perm)
        generate_function("all", perm, ORDER, datatypes, dims, schedule)

def generate_all_cmp_functions(ORDER, datatypes, dims):
    from itertools import permutations
    order = [i for i in range(ORDER)]
    perms = permutations(order)
    generated = set([])
    for perm in perms:
        kcutoff = 0
        if perm[kcutoff:] not in generated:
            generate_cmp(perm[kcutoff:])
            generated.add(perm[kcutoff:])


def generate_test_func(ORDER, datatypes, filename):
    print("""
int main(int argc, char* argv[]) {
  char *p;
  int SPLIT;
   std::string filename = argv[1];

  long conv = strtol(argv[2], &p, 10);
  SPLIT = conv;


  // Read tensor data  
  int order = """ + str(ORDER) + """;
  int * dimensions = (int*)malloc(sizeof(int)*order);
  memset(dimensions, 0, sizeof(int)*order);
  
  int32_t init_alloc_size = 1048576;
  int32_t A_capacity = init_alloc_size;
  struct coo_t *A = (struct coo_t *)malloc(sizeof(struct coo_t)* A_capacity);

  std::fstream stream;
  util::openStream(stream, filename, fstream::in);

  std::string line;
  if (!std::getline(stream, line)) {
    return -1;
  }


  int size = 0;

  do {
      if(size >= A_capacity){
          int32_t A_capacity_new = 2 * (A_capacity);
          A = (struct coo_t*)realloc(A, sizeof(struct coo_t) * A_capacity_new);
          A_capacity = A_capacity_new;
        }

    char* linePtr = (char*)line.data();

    // Generated by coo/gen_taco_to_list.py
""")
    for i in range(ORDER):
        print("\tlong idx" + str(i) + " = strtol(linePtr, &linePtr, 10);")
        print("\tA[size].idx" + str(i) + " = (int32_t)idx" + str(i) + " - 1;")
        print("\tdimensions[" + str(i) + "] = std::max(dimensions[" + str(i) + "], (int)idx" + str(i) + " - 1);")
    
    print("""
    double val = strtod(linePtr, &linePtr);
    A[size].val = val;
    size ++;

  } while (std::getline(stream, line));

  stream.close();
""")
    total = ""
    for i in range(ORDER):
        total += str(i)
    from itertools import permutations
    order = [i for i in range(ORDER)]
    perms = permutations(order)

    j = 0
    for perm in perms:
        kcutoff = ORDER
        # for kcutoff in range(ORDER + 1):
        print("\t\tif(" + str(j) + " == SPLIT){")
        ident = ""
        for i in perm:
            ident += str(i)
        sched = get_schedule(perm)


        print("\t\t// " + str(perm))
        print("\t\tfor(int i = 0; i < 100; i ++){")
        print("\t\t\tcout << filename << \" | " + ident + " | " + str(kcutoff) + " | " + str(len(sched)) + "\" ;")

        print("\t\t\tqsort(A, size, sizeof(struct coo_t), cmp_" + total + ");")
        print ("\t\t\ttranspose_coo_" + ident + "_all(A, size, order, dimensions);")
        print("\t\t\tcout << endl;")
        print("\t\t}")

        print()
        print("\t\t}")
        j += 1

    print("\tfree(A);")
    print("\tfree(dimensions);")
    print("}")

TIME_ALL = True
TIME_PASS = False

def main():
    ORDER = 3
    datatypes = ["int32_t" for i in range(ORDER)]
    datatypes.append("double")
    dims = [100 for i in range(ORDER)]
    generate_header(ORDER, datatypes)
    generate_all_cmp_functions(ORDER, datatypes, dims)
    generate_all_functions(ORDER, datatypes, dims)
    generate_test_func(ORDER, datatypes, "./3tensor.tns")

if __name__ == "__main__": main()