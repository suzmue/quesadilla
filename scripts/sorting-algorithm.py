
def pretty_print_order(prop, data, order):
    for m in order:
        out = str(m) + ": "
        for p in data[m - 1]:
            out += prop + "(" +  str(p) + "),"
        print out


def generate(order, sorting):
    sortedness = [[] for i in range(len(order))]
    for i in range(len(order)):
        if sorting[i] == False:
            continue
        sortedness[order[i]-1] = [set([])]
        for j in range(i):
            sortedness[order[i]-1][0].add(order[j])
    return sortedness

def compare_conditions(a, b):
    if len(b) == 0:
        return True

    # We can only have one packability constraint for b.
    b_cond = b[0]

    for p in a:
        if p.issubset(b_cond):
            return True # one of our conditions matched!
    return False

def compare_lists(got, want):
    for i in range(len(got)):
        if compare_conditions(got[i], want[i]) == False:
            return False
    return True

def check(sorted_in, grouped_in, sorted_out, grouped_out, schedule, output):
    if DEBUG:
        print "input:"
        print "sorted:"
        pretty_print_order("sorted", sorted_in, output)
        print "grouped:"
        pretty_print_order("grouped", grouped_in, output)
        print "start sort"    
    # run a step
    for step in schedule:
        if DEBUG:
            print
            print "sort:", step, "=>"
        do_sort(sorted_in, grouped_in, step[0], step[1]),
        if DEBUG:
            print "sorted:"
            pretty_print_order("sorted", sorted_in, output)
            print "grouped:"
            pretty_print_order("grouped", grouped_in, output)


    if DEBUG:
        print
        print "done."

    if DEBUG:
        print "sorted"
        print "got:"
        pretty_print_order("sorted", sorted_in, output)
        print
        print "want:"
        pretty_print_order("sorted", sorted_out, output)
        print "grouped"
        print "got:"
        pretty_print_order("grouped", grouped_in, output)
        print
        print "want:"
        pretty_print_order("grouped", grouped_out, output)


    return compare_lists(sorted_in, sorted_out) and compare_lists(grouped_in, grouped_out) 



# sortedness is a list of list of pair of (bool, []int), if True, the list is the values that need to be fixed to make sorted True.
def do_sort(sortedness, groupedness, sort_mode, fixed_modes):
    # Create a set of the unfixed modes.
    modes = set([i+1 for i in range(0, len(sortedness))])
    unfixed = modes - fixed_modes

    # If any of the fixed values groupedness depends on the unfixed, get rid of all sorted information.
    for f in fixed_modes:
        if len(groupedness[f-1]) == 0:
            print "UNWANTED SORTING OPERATION:"
            print f, "is fixed but not grouped"
            pretty_print_order("sorted", sortedness, [i+1 for i in range(len(groupedness))])
            pretty_print_order("grouped", groupedness, [i+1 for i in range(len(groupedness))])
            print sort_mode
            print fixed_modes
            print 
            exit()
        for i in range(0, len(groupedness[f-1])):
            p = groupedness[f-1][i]
            for d in p:
                for m in unfixed:
                    if m == d: 
                        print ("UNWANTED SORTING OPERATION")
                        pretty_print_order("grouped", groupedness, [i+1 for i in range(len(groupedness))])
                        print sort_mode
                        print fixed_modes
                        exit()



    # Add connections from all unfixed to sort_mode.
    for m in unfixed:
        for p in sortedness[m-1]:
            p.add(sort_mode)
        for p in groupedness[m-1]:
            p.add(sort_mode)



    # Remove connections from 
    sortedness[sort_mode - 1] = [set([])]
    groupedness[sort_mode - 1] = [set([])]

    # Add connections from all unfixed to all fixed.
    for m in unfixed:
        for p in sortedness[m-1]:
            for f in fixed_modes:
                    p.add(f)
        for p in groupedness[m-1]:
            for f in fixed_modes:
                    p.add(f)



    # If any of the fixed values depended on the unfixed, get rid of all sorted information.
    for f in fixed_modes:
        bad = False
        for i in range(0, len(groupedness[f-1])):
            p = groupedness[f-1][i]
            for d in p:
                for m in unfixed:
                    if m == d: 
                       bad = True
        if bad:
            groupedness[f-1] = []

        bad = False
        for i in range(0, len(sortedness[f-1])):
            p = sortedness[f-1][i]
            for d in p:
                for m in unfixed:
                    if m == d: 
                       bad = True
        if bad:
            sortedness[f-1] = []


def getschedule(sorted_in, grouped_in, sorted_out, grouped_out, order):
    # Linearize the sorted / grouped levels of the output order.
    # Has to be linearizable. Order is our linearized order.

    # Iterate from top down.
    current = []
    fix = set([])
    schedule = []
    need = 0
    if DEBUG:
        print
        print "Sorting schedule:"

    for i in range(len(order)):
        m = order[i]
        # Check if the input order already satisfies.
        needs_sort = False
        if len(grouped_out[m-1]) > 0:
            # TODO: split this out if we want to add a grouping function.
            needs_sort = True
            for p in grouped_in[m-1]:
                if p.issubset(grouped_out[m-1][0]):
                    needs_sort = False

        if len(sorted_out[m-1]) > 0:
            needs_sort = True
            for p in sorted_in[m-1]:
                if p.issubset(sorted_out[m-1][0]):
                    needs_sort = False

        # No sorting required, just continue.
        if len(grouped_out[m-1]) == 0 and len(sorted_out[m-1]) == 0:
            continue
        
        # Add it to the list to be sorted.
        if needs_sort:
            current.append(m)
            need += 1
            continue
        
        # Sort from lower to top and fix those values.
        for i in range(1, len(current)+1):
            if DEBUG:
                print "sort(", current[len(current) - i], "|", fix, ")"
            schedule.append( (current[len(current) - i], fix.copy()) )

        for c in current:
            fix.add(c)

        fix.add(m)

        # Check if the reason we decided to sort depends on a level 
        # that is not currently fixed.
        # Note: For being efficient this depends on the input being
        # grouped if we have that kind of dependency.
        for p in sorted_in[m-1]:
            for c in p:
                fix.add(c)

        for p in grouped_in[m-1]:
            for c in p:
                fix.add(c)

        current = []

    # Sort from lower to top and fix those values.
    for i in range(1, len(current)+1):
        if DEBUG:
            print 
            print "sort(", current[len(current) - i], "|", fix, ")"

        schedule.append( (current[len(current) - i], fix.copy()) )

    if need > len(schedule):
        print "NOT OPTIMAL"
        exit()

    return schedule

def process(sorting_in, grouping_in, order, sorting_reqs, grouping_reqs):
    if DEBUG:
        print "from: ", [i+1 for i in range(len(order))]
        print "sorting_in: ", sorting_in
        print "grouping_in: ", grouping_in

        print "to: ", order
        print "sorting_out: ", sorting_reqs
        print "grouping_out: ", grouping_reqs

    
    # Get a schedule
    input_order = [i+1 for i in range(len(order))]
    all_sorted = [True for i in range(len(order))]
    sorted_in = generate(input_order, sorting_in)
    grouped_in = generate(input_order, grouping_in)
    sorted_out = generate(order, sorting_reqs)
    grouped_out = generate(order, grouping_reqs)


    schedule = getschedule(sorted_in, grouped_in, sorted_out, grouped_out, order)
    # Check the schedule we have created.
    return schedule, check(sorted_in, grouped_in, sorted_out, grouped_out, schedule, order)


def main():
    modes = input("How many modes? ")
    order = []
    print ("Enter desired order of output:")
    for i in range(0,modes):
        order.append(input(str(i+1) + ": "))

    print ("Enter sortedness of each input level (0 for unsorted 1 for grouped 2 for sorted):")
    sorting_in = []
    grouping_in = []
    for i in range(0,modes):
        f = input(str(i+1) + ": ")
        if f == 0:
            sorting_in.append(False)
            grouping_in.append(False)
        elif f == 1:
            sorting_in.append(False)
            grouping_in.append(True)
        else:
            sorting_in.append(True)
            grouping_in.append(True)


    sorting_reqs = []
    grouping_reqs = []
    print ("Enter format of each output level (0 for dense 1 for unsorted compressed 2 for sorted compressed):")
    for i in range(0,modes):
        f = input(str(i+1) + ": ")
        if f == 0:
            sorting_reqs.append(False)
            grouping_reqs.append(False)
        elif f == 1:
            sorting_reqs.append(False)
            grouping_reqs.append(True)
        else:
            sorting_reqs.append(True)
            grouping_reqs.append(True)


    _, res = process(sorting_in, grouping_in, order, sorting_reqs, grouping_reqs)
    if res:
        print "SUCCESS"
    else:
        print "BAD SORT SEQUENCE"

def try_all():
    MAX_MODES = 6
    for num_modes in range(1,MAX_MODES + 1):
        print "# modes =", num_modes
        from itertools import permutations
        order = [i+1 for i in range(num_modes)]
        perms = permutations(order)
        seqs = getallsequences(num_modes)
        for perm in list(perms):
            total = 0
            iters = 0
            for sorting_in in seqs:
                for grouping_in in seqs:
                    # Basically make sure that this order could be obtained by some sequence
                    # of GROUP() and SORT() calls that we allow in this file.
                    # make sure we have compatible output requirements
                    bad = False
                    for i in range (len(sorting_in)):
                        if sorting_in[i] == True and grouping_in != True:
                            bad = True
                            break
                    if bad:
                        continue

                    # make sure we have compatible output requirements
                    bad = False
                    for i in range (len(grouping_in)):
                        if grouping_in[i] == False:
                            continue
                        for j in range(i):
                            # TODO: doesn't make sense for inputs to be grouped on something that is not grouped.
                            if grouping_in[j] == False:
                                bad = True
                                break
                    if bad:
                        continue

                    for sorting_out in seqs:
                        for grouping_out in seqs:
                            sched, res = process(sorting_in, grouping_in, list(perm), sorting_out, grouping_out)
                            if not res:
                                print list(perm)
                                print sorting_in
                                print grouping_in

                                print sorting_out
                                print grouping_out
                                print "BAD SORT SEQUENCE"
                                exit()
                            total += len(sched)
                            iters += 1


def getallsequences(size):
    seqs = []
    res = [False for i in range(size)]
    while res != [True for i in range(size)]:
        seqs.append(res[:])
        for i in range(0, size):
            if res[i] == False:
                res[i] = True
                break
            res[i] = False
    seqs.append(res[:])
    return seqs


DEBUG = False 

if __name__ == "__main__": 
    main()
    #try_all()