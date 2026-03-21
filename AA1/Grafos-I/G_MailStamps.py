import sys
sys.setrecursionlimit(10**6)

n = int(input())
grafo = dict()

for _ in range(n):
    u, v = map(int, input().split())
    if not u in grafo:
        grafo[u] = [v]
    else:
        grafo[u].append(v)
    if not v in grafo:
        grafo[v] = [u]
    else:
        grafo[v].append(u)
# print(grafo)

vis = set()
saida = []
def dfs(v):
    if v in vis:
        return
    saida.append(v)
    vis.add(v)
    for vizinho in grafo[v]: 
        dfs(vizinho)

for k, v in grafo.items():
    if len(v) == 1:
        dfs(k)
        print(*saida)
        exit(0)
    