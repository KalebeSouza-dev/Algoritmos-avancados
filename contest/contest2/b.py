t = int(input())
for i in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    
    out = []
    pref = arr[0]
    suf = arr[-1]
    if pref == -1 and suf == -1:
        print(0)
        for i in range(n):
            if arr[i] == -1:
                out.append(0)
            else:
                out.append(arr[i])
        print(*out)
    elif pref == -1 and suf != -1:
        print(0)
        for i in range(n):
            if arr[i] == -1:
                out.append(0)
            else:
                out.append(arr[i])
        out[0] = suf
        print(*out)
    elif pref != -1 and suf == -1:
        print(0)
        for i in range(n):
            if arr[i] == -1:
                out.append(0)
            else:
                out.append(arr[i])
        out[-1] = pref
        print(*out)
    elif pref != -1 and suf != -1:
        print(abs(suf - pref))
        for i in range(n):
            if arr[i] == -1:
                out.append(0)
            else:
                out.append(arr[i])
        print(*out)