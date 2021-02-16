arr = rand(1:50,20)

function selectionsort!(arr) # in-place with 'bang' operator
    n = length(arr)
    for i in 1:n
        # find the index of min in the range i:n-1
        m = argmin(arr[i:n])[1] + i - 1
        # swap arr[i] and arr[m]
        arr[i], arr[m] = arr[m], arr[i]
    end
    arr
end

selectionsort!(arr) |> println
