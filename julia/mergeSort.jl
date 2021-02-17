arr = [2, 1, 3, 7, 6, 4, 9, 11]

function merge!(arr, l1, r1, l2, r2)
    merged = []
    start = l1
    while l1 <= r1 || l2 <= r2 
        if l1 > r1
            push!(merged, arr[l2])
            l2 += 1
        elseif l2 > r2 
            push!(merged, arr[l1])
            l1 += 1 
        elseif arr[l1] < arr[l2]
            l1 += 1
        else
            push!(merged, arr[l2])
            l2 += 1
        end
    end
    for i in eachindex(merged)
        arr[start] = merged[i]
        start += 1
    end
end

function mergesort!(arr, l, r)
    # base case
    r <= l && return

    mp = div(l+r, 2) 
    # 1 2 3 4
    # mergesort left half 
    mergesort!(arr, l, mp) # include midpoint in left half (arbitrary)
    # mergesort right half 
    mergesort!(arr, mp+1, r)

    # now merge the two halves
    merge!(arr, l, mp, mp+1, r)

    arr
end

n = length(arr)
mergesort!(arr, 1, n) |> println
