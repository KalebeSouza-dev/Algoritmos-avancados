n = int(input())
profs = list(map(int, input().split()))
alunos = list(map(int, input().split()))

soma = [profs[i] - alunos[i] for i in range(n)]
soma.sort()

l = 0
r = n - 1

cont = 0
while l < r:
    if soma[l] + soma[r] > 0:
        cont += (r - l)
        r -= 1
    else:
        l += 1

print(cont)