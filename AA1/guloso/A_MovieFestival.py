# essa ficou elegante 
n = int(input())
filmes = []
for _ in range(n):
    filmes.append(tuple(map(int, input().split())))

ordem = sorted(filmes, key=lambda x: x[1])

cont = 0
atual = 0
for inicio, fim in ordem:
    if inicio >= atual:
        cont += 1
        atual = fim
print(cont)
a, b, c = map(int, input().split())
for k in range(1, b+1):
    if (a * k) % b == c:
        print("YES")
        break
else:
    print("NO")