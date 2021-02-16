arr = rand(1:50, 20)

function insertionsort!(arr)
    n = length(arr)

    for i in 2:n
        for j in i:-1:2
            if arr[j] < arr[j - 1]
                arr[j], arr[j - 1] = arr[j - 1], arr[j] # swap
            end
        end
    end
    arr
end
# 4 3 5 1

insertionsort!(arr) |> println
