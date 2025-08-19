#agr vai, tentar agrupar paridades iguais para gcd == 2
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    q = n - 1

    par = []
    impar = []
    for i in range(n*2):
        # lista de indices
        if a[i] % 2 == 0:
            par.append(i)
        else:
            impar.append(i)

    if len(par) % 2 == 0:
        maxPar = len(par)
    else:
        maxPar = len(par) - 1
    for i in range(0, maxPar, 2):
        if q == 0: break
        print(par[i] + 1, par[i + 1] + 1)
        q -= 1

    if q > 0:
        for i in range(0, len(impar), 2):
            if q == 0: break
            print(impar[i] + 1, impar[i + 1] + 1)
            q -= 1
    