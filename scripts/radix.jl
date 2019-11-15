# radix.jl
#
# an example lsd (least significant digit) and msd (most significant digit)
# radix sort code for eventually transposing COO sparse tensors
#
# note that all passes run in linear time with respect to the input length and
# the number of buckets, and the code specializes on the index integer types
# 
# Peter Ahrens

Base.getindex(tup::Tuple, ind::Tuple) = ntuple(n->tup[ind[n]], length(ind))

struct COOElem{N, Ind<:Tuple{Vararg{Integer, N}}, Val}
    i::Ind
    v::Val
end

function lsd(input::Vector{<:COOElem{N}}, I_n, ::Val{n}) where {N, n}
    output = copy(input)
    buckets = zeros(Int, I_n + 1)
    for elem in input
        buckets[elem.i[n] + 1] += 1
    end
    for i in 2:I_n
        buckets[i] += buckets[i - 1]
    end
    for elem in input 
        output[buckets[elem.i[n]] += 1] = elem
    end
    return output
end

function lsdperm(input::Vector{<:COOElem{N}}, I_n, ::Val{n}) where {N, T, n}
    perm = zeros(Int, length(input))
    buckets = zeros(Int, I_n + 1)
    for elem in input
        buckets[elem.i[n] + 1] += 1
    end
    for i in 2:I_n
        buckets[i] += buckets[i - 1]
    end
    for j in 1:length(input)
        perm[buckets[input[j].i[n]] += 1] = j
    end
    return perm
end

function msd(input::Vector{<:COOElem{N}}, I_n, ::Val{n}, ::Val{f}) where {N, T, n, f}
    output = copy(input)
    quotients = zeros(Int, length(input))
    buckets = zeros(Int, length(input))
    quotients[1] = 1
    buckets[1] = 0
    for j in 2:length(input)
        if input[j].i[f] == input[quotients[j - 1]].i[f]
            quotients[j] = quotients[j - 1]
        else
            quotients[j] = j
            buckets[j] = j - 1
        end
    end

    for p in lsdperm(input, I_n, Val(n))
        output[(buckets[quotients[p]] += 1)] = input[p]
    end

    return output
end

function msdperm(input::Vector{<:COOElem{N}}, I_n, ::Val{n}, ::Val{f}) where {N, T, n, f}
    perm = zeros(Int, length(input))
    quotients = zeros(Int, length(input))
    buckets = zeros(Int, length(input))
    quotients[1] = 1
    buckets[1] = 0
    for j in 2:length(input)
        if input.i[j][f] == input.i[quotients[j - 1]][f]
            quotients[j] = quotients[j - 1]
        else
            quotients[j] = j
            buckets[j] = j - 1
        end
    end

    for p in lsdperm(input, I_n, Val(n))
        perm[(buckets[quotients[p]] += 1)] = p
    end

    return perm
end

example = [COOElem((Int64(7), Int8(2), Int32(2)), Float64(3.14)),
           COOElem((Int64(1), Int8(2), Int32(1)), Float64(6.28)),
           COOElem((Int64(2), Int8(6), Int32(9)), Float64(2.67)),
           COOElem((Int64(2), Int8(1), Int32(9)), Float64(1.41)),
           COOElem((Int64(4), Int8(2), Int32(3)), Float64(1.23)),
           COOElem((Int64(1), Int8(4), Int32(2)), Float64(3.44)),
           COOElem((Int64(9), Int8(4), Int32(2)), Float64(0.50)),
           COOElem((Int64(7), Int8(3), Int32(3)), Float64(1.00)),
           COOElem((Int64(7), Int8(3), Int32(2)), Float64(1.11)),
           COOElem((Int64(3), Int8(3), Int32(4)), Float64(2.22))]

pretty(x) = (display(hcat(map(elem->[elem.i...], x)...)); println())

println("input:")
pretty(example)
println()

println("lsd(2):")
example = lsd(example, 10, Val(2))
pretty(example)
println()

println("lsd(1):")
example = lsd(example, 10, Val(1))
pretty(example)
println()

println("msd(3, (1, 2))):")
example = msd(example, 10, Val(3), Val((1, 2)))
pretty(example)
println()

println("msd(3, (1))):")
example = msd(example, 10, Val(3), Val((1, 2)))
pretty(example)
println()
