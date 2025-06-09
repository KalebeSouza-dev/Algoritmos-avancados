n, k = map(int, input().split())
array = sorted(list(map(int, input().split())))

l = 0
r = n - k - 1
resposta = array[r] - array[l]

for i in range(k + 1):
    if r + i > n - 1: break
    if array[r + i] - array[l + i] < resposta:
        resposta = array[r + i]  - array[l + i]
        
print(resposta)