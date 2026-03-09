t = int(input())
for _ in range(t):
    n = int(input())
    c = 0
    for g in range(n//2 + 1):
        p2 = g*2
        if p2 > n: break
        falta = n - p2
        if falta % 4 == 0:
            c+= 1
    print(c)
    