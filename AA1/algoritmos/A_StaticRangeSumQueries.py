n, q = map(int, input().split())
ent = list(map(int, input().split()))

soma = [0] * (n + 1)
soma[1] = ent[0]

for e in range(2, n + 1):
    soma[e] = soma[e - 1] + ent[e - 1]

for i in range(q):
    l, r = map(int, input().split())
    if l == 1:
        print(soma[r])
    else:
        print(soma[r] - soma[l - 1])