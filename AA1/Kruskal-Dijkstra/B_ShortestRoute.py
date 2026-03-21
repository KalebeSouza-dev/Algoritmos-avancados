import heapq
import math
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
grafo = [[] for i in range(n + 1)]
 
for _ in range(m):
    u, v, w = map(int, input().split())
    grafo[u].append((v, w))
 
def dijkstra(g, s, n):
    N = len(g) - 1
    dis = [math.inf] * (N + 1)
    dis[s] = 0
 
    pq = [(0, s)]
    while pq:
        d, v = heapq.heappop(pq)
        if d > dis[v]:
            continue
        for u, w in g[v]:
            if d + w < dis[u]:
                dis[u] = d + w
                heapq.heappush(pq, (dis[u], u))

    return dis
 
dis = dijkstra(grafo, 1, n)
sys.stdout.write(" ".join(map(str, dis[1:])))