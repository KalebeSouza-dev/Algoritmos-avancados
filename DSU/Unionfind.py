import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def punion(u, v):
    u = pfind(u) 
    v = pfind(v) 
    
    if u != v:
        size[v] += size[u]
    parents[u] = v

def pfind(v):
    if v == parents[v]:
        return v
    parents[v] = pfind(parents[v])
    return parents[v] 


N, P = map(int, input().split())
parents = [i for i in range(N)]
size = [1] * N

for _ in range(P):
    t, u, v = map(int, input().split())
    if t == 0:
        punion(u, v)
    else:
        if pfind(u) == pfind(v): print(1)
        else: print(0)
