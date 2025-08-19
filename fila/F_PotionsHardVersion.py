import heapq

n = int(input())
array = [int(i) for i in input().split()]
soma = cont = 0

heap = []
for i in range(n):
    soma += array[i]
    cont += 1
    if array[i] < 0:
        heapq.heappush(heap, array[i])
    if soma < 0:
        soma -= heapq.heappop(heap)
        cont -= 1
print(cont)
