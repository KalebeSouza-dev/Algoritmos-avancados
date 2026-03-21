n, q = map(int, input().split())
array = list(map(int, input().split()))

# comparação entre O(n^2) e O(n) 
somas = [0] * (n - q + 1)
for i in range(n - q + 1):
    soma = 0
    for j in range(q):
        soma += array[i + j]
    somas[i] = soma
print("for", somas.index(min(somas)) + 1)