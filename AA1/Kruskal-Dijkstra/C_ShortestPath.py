import heapq
import math
 
n, m, s, t = map(int, input().split())
grafo = [[] for i in range(n + 1)]
 
for _ in range(m):
    u, v, w = map(int, input().split())
    grafo[u].append((v, w))
    grafo[v].append((u, w))
 
def dijkstra(g, s, n):
    N = len(g) - 1
    dis = [math.inf] * (N + 1)
    pai = [-1] * (N + 1)
    dis[s] = 0
 
    pq = [(0, s)]
    while pq:
        d, v = heapq.heappop(pq)
        if d > dis[v]:
            continue
        for u, w in g[v]:
            if d + w < dis[u]:
                dis[u] = d + w
                pai[u] = v
                heapq.heappush(pq, (dis[u], u))
 
    if dis[n] == math.inf:
        return None
    caminho = []
    atual = n
    while atual != -1:
        caminho.append(atual)
        atual = pai[atual]
    caminho.reverse()
 
    return caminho, dis
 
caminho, dis = dijkstra(grafo, s, t)
print(dis)
if caminho is None:
    print(-1)
else:
    print(*caminho)