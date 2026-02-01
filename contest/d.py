import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    
    pref = [0] * n
    suf = [0] * n
    
    pref[0] = arr[0]
    for i in range(1, n):
        pref[i] = min(pref[i-1], arr[i])
    #print(pref)

    suf[n-1] = arr[n-1]
    for i in range(n-2, -1, -1):
        suf[i] = max(suf[i+1], arr[i])
    #print(suf)

    out = True
    for k in range(n-1):
        if pref[k] > suf[k+1]:
            out = False
            break
    
    if out:
        print('Yes')

    else:
        print("No")

