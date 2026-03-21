n, x = map(int, input().split())
numeros = [int(i) for i in input().split()]

mapa = {}
if x <= 1:
    print("IMPOSSIBLE")
    exit(0)  

for i in range(n):
    complemento = x - numeros[i]
    if complemento in mapa:
        print(mapa[complemento] + 1, i + 1)
        exit(0)
        
    else:
        mapa[numeros[i]] = i 

print("IMPOSSIBLE")

