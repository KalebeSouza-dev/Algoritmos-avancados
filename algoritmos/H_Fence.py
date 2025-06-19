n, q = map(int, input().split())
array = list(map(int, input().split()))

soma = 0
for i in range(q):
    soma += array[i]
menor = soma

l = 0
r = q
idx = 0
while r < n:
    soma = soma - array[l] + array[r]
    if soma < menor:
        menor = soma
        idx = l + 1
    l += 1
    r += 1

print(idx + 1)
