from collections import deque

n, m = map(int, input().split())
grafo = [[] for _ in range(n+1)]
array = [int(i) for i in input().split()] # gatos

# recebe grafo
for _ in range(n - 1):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)


dis = [-1] * (n + 1)
def bfs(raiz):
    fila = deque([(raiz, array[raiz-1])])
    dis[raiz] = 0
    result = 0

    while fila:
        v, cont = fila.popleft()

        if cont > m: # muitos gatos
            continue

        if v != 1 and len(grafo[v]) == 1: #chegou na folha sem cair no if de cima
            result += 1
            continue

        for vizinho in grafo[v]:
            if dis[vizinho] == -1: # n visitado
                dis[vizinho] = dis[v] + 1

                if array[vizinho-1] == 1: # com gato
                    fila.append((vizinho, cont + 1))
                else: # sem gato
                    fila.append((vizinho, 0))

    return result

result = bfs(1)
print(result)
