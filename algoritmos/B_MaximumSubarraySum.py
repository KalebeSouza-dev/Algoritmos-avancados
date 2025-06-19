n = int(input())
array = [int(i) for i in input().split()]

somaMax = somaAtual = array[0]

for i in range(1, n):
    somaAtual = max(array[i], somaAtual + array[i])

    if somaAtual > somaMax: 
        somaMax = somaAtual
print(somaMax)