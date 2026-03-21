n = 1000
fact = [1] * (n + 1)
for i in range(2, n + 1):
    fact[i] = (fact[i-1] * i)

t = int(input())
for i in range(t):
    q = int(input())
    if q % 2 == 0:
        q //= 2
        print((fact[q] * fact[q]) % 998244353)
    else:
        print(0)