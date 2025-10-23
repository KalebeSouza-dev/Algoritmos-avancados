from collections import deque

n = int(input())
grafo = [[] for _ in range(n+1)]

for _ in range(n - 1):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)

array = list(map(int, input().split()))

if array[0] != 1:
    print("No")
    exit()

visitado = [False] * (n+1)
visitado[1] = True

q = deque([1])
idx = 1

while q:
    v = q.popleft()
    filhos = [u for u in grafo[v] if not visitado[u]]
    k = len(filhos)

    if k == 0:
        continue

    prox = array[idx:idx+k]
    if set(prox) != set(filhos):
        print("No")
        exit()

    for u in prox:
        visitado[u] = True
        q.append(u)

    idx += k

print("Yes")
