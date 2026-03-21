n = int(input())
a = [int(i) for i in input().split()]
b = sorted(a[1:])
votos = a[0]
cont = 0

if votos > b[-1]:
    print(0)   
else:
    while votos <= b[-1]:
        b[-1] -= 1
        cont += 1
        votos += 1
        b.sort()
    print(cont)
