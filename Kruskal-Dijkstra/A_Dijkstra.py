import heapq
import math

n, m = map(int, input().split())
grafo = [[] for i in range(n + 1)]
for i in range(m):
    u, v, w = map(int, input().split())
    grafo[u].append((v,w))

def dijkstra(g, s, n):
    """
    g: lista de adjacência, onde g[v] = [(u, w), ...]
       sendo u o vizinho e w o peso da aresta (v --w--> u)
    s: vértice inicial (source)
    n: vértice destino
    """

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
        return -1

    caminho = []
    atual = n
    while atual != -1:
        caminho.append(atual)
        atual = pai[atual]
    caminho.reverse()

    return caminho

print(*dijkstra(grafo, 1, n))