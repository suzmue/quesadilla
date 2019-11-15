def generate(order, datatypes):
    for mode in range(order):
        print("long idx" + str(mode) + " = strtol(linePtr, &linePtr, 10);")
        print("A[size].idx" + str(mode) + " = ("+ datatypes[mode] + ")idx" + str(mode) + ";")   
        print("dimensions[" + str(mode) + "] = std::max(dimensions[" + str(mode) + "], (int)idx" + str(mode) + ");")
        print()

def main():
    perm = [1,0,3,2]
    generate(3, ["int32_t", "int8_t", "int32_t","int8_t", "double"])
main()