from collections import deque

n, m = map(int, input().split())
grafo = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)

dist = [-1] * (n + 1)
pai = [-1] * (n + 1)

def bfs(raiz):
    fila = deque([raiz])
    dist[raiz] = 0
    
    while fila:
        v = fila.popleft()
        for vizinho in grafo[v]:
            if dist[vizinho] == -1:
                dist[vizinho] = dist[v] + 1
                pai[vizinho] = v 
                fila.append(vizinho)

bfs(1)

if dist[n] == -1:
    print("IMPOSSIBLE")
else:
    caminho = []
    atual = n
    while atual != -1:
        caminho.append(atual)
        atual = pai[atual]
    caminho.reverse()
    
    print(len(caminho))
    print(*caminho)
