n, q = map(int, input().split())
s = list(input())

cont = 0
for i in range(n - 2):
    if s[i:i+3] == ['A','B','C']:
        cont += 1

for i in range(q):
    x, c = input().split()
    x = int(x) - 1

    if s[x] == c:
        print(cont)
    else:
        ini = x - 2
        fim = x + 1

        if x - 2 < 0: ini = 0
        if x == n: fim = n - 1

        temABC = 0
        for i in range(ini, fim):
            if s[i:i+3] == ['A','B','C']:
                temABC += 1

        s[x] = c
        temAinda = 0
        for i in range(ini, fim):
            if s[i:i+3] == ['A','B','C']:
                temAinda += 1

        cont += (temAinda - temABC)

        print(cont)
