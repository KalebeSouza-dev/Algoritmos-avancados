import heapq

n = int(input())
result = []
fila = []

def output(fila, num):
    while fila and fila[0] < num:
        heapq.heappop(fila)
        result.append('removeMin')
    if not fila or fila[0] > num:
        heapq.heappush(fila, num)
        result.append(f'insert {num}')
    result.append(f'getMin {num}')

for _ in range(n):
    string = input().split()
    if string[0] == 'insert':
        heapq.heappush(fila, int(string[1]))
        result.append(f'{string[0]} {string[1]}')
    elif string[0] == 'removeMin':
        if fila:
            heapq.heappop(fila)
            result.append('removeMin')
        else:
            result.append('insert 0')
            result.append('removeMin')
    elif string[0] == 'getMin':
        output(fila, int(string[1]))

print(len(result))
print("\n".join(result))
