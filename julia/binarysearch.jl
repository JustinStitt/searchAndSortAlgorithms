
arr = [1,2,3,4,5,7,9,11,14]
sort!(arr)

"""
Iterative binary search
"""
function binarysearch(arr, f)
    l = 1; r = length(arr)
    mp(_l, _r) = (_l + _r) ÷ 2
    while(true)
        m = mp(l, r)
        arr[m] == f && return m
        l == r && return -1
        if f > arr[m]
            l = m + 1
        else
            r = m - 1
        end
    end
    return -1
end
println("arr: ", arr, "\n")
binarysearch(arr, 2) |> println