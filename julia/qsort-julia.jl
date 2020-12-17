arr = rand(1:100, 50) |> collect

function partition!(arr, l, r)
    pivot = arr[r]
    slow = l - 1
    fast = l
    for _ in l:r-1
        if arr[fast] <= pivot
            slow += 1
            arr[slow], arr[fast] = arr[fast], arr[slow]
        end
        fast += 1
    end
    slow += 1
    arr[slow], arr[fast] = arr[fast], arr[slow]
    return slow
end

function quicksort!(arr, l = 1, r = length(arr))
    if(r <= l)
        return
    end
    p_i = partition!(arr, l, r)

    # quicksort left half
    quicksort!(arr, l, p_i - 1)
    #quicksort right half
    quicksort!(arr, p_i + 1, r)
    arr
end

quicksort!(arr)