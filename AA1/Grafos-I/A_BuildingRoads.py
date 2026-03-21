import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())

# recebe o grafo
grafo = [[] for _ in range(n + 1)]
for i in range(m):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)

# dfs
vis = [False] * (n+1)
def dfs(v):
    vis[v] = True
    for vizinho in grafo[v]:
        if vis[vizinho]: continue
        dfs(vizinho)

#separa as ilhas
saida = []
for i in range(1, len(vis)):
    if vis[i] == False:
        dfs(i)
        saida.append(i)


sys.stdout.write(f"{len(saida) - 1}\n")
for i in range(len(saida) - 1):
    sys.stdout.write(f"{saida[i]} {saida[i + 1]}\n")