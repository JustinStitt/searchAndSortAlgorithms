arr = rand(1:50,20)

function bubblesort!(arr)
    n = length(arr)
    for i in 1:n
        for j in 1:n-1
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j] # swap
            end
        end
    end
    arr
end

bubblesort!(arr) |> println
