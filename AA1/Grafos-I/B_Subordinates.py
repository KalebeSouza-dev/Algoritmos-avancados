import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
saida = [0] * (n+1)
array = [int(i) for i in input().split()]

# criando grafo
grafo = [[] for _ in range(n+1)]
for i in range(len(array)):
    # grafo[i + 2].append(array[i])
    grafo[array[i]].append(i + 2)

# dfs
dp = [-1] * (n + 1)

def dfs(v):
    if dp[v] != -1:
        return dp[v]

    total = 0
    for vizinho in grafo[v]:
       total += 1 + dfs(vizinho)

    dp[v] = total
    return total
dfs(1)
print(*dp[1:])