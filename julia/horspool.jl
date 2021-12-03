using DataStructures

function prewash(pattern)
    lookup = DefaultDict{Char, Int}(5)
    n = length(pattern)
    for (i, c) in enumerate(pattern[1:end-1])
        lookup[c] = n - i
    end
    lookup[pattern[end]] = n
    return lookup
end

function horspool(src, pattern)
    lookup = prewash(pattern)
    m, n = length(src), length(pattern)
    
    matches = [] # pattern matches
    j = n 
    while j <= m
        jd = 1
        # check right to left
        for (i, k) in zip(j:-1:j-n+1, n:-1:1)
            # no match
            if src[i] != pattern[k]
                jd = get(lookup, src[i], n)
                break
            end
            if k == 1 push!(matches, i) end
        end
        j += jd
    end
    return matches
end

function main()
    s = "mary had a little lamb"
    p = "lamb"
    o = horspool(s, p)
    println("Total matches: ", length(o))
    print("Found matches at: ")
    for v in o print(v, " ") end # print matches 
end

main()