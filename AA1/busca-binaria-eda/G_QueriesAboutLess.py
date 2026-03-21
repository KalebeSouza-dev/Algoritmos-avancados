n, q = map(int, input().split())

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
a.sort()

saida = []
for k in b:
    left = 0
    right = n - 1
    resultado = 0
    
    while left <= right:
        mid = (left + right) // 2
        if a[mid] <= k:
            resultado = mid + 1
            left = mid + 1
        else:
            right = mid - 1
    saida.append(resultado)

print(*saida)