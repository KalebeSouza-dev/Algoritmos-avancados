from math import gcd, isqrt

n = int(input())
array = list(map(int, input().split()))

resultado = array[0]
for i in range(1, n):
    resultado = gcd(resultado, array[i])

cont = 0
for i in range(1, isqrt(resultado) + 1):
    if resultado % i == 0:
        cont += 1
        if i != resultado // i:
            cont += 1
print(cont)