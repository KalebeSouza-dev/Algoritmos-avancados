import sys
input = sys.stdin.readline

# SOS DOUG
tl, tr, t = map(int, input().split())
n = int(input())
if n == 0: 
    print(tl)
    exit()
array = [int(i) for i in input().split()]

cont = tl
menor = menorp = idx = tr
TchegarAntes = tl - (array[0] - 1)

flag = True
# verifica caso tempo de espera = 0
for num in range(n):
    if array[num] - 1 >= 0:
        menorp = (tl + num*t) - (array[num] - 1 )
    if menorp < menor:
        menor = menorp
        idx = array[num] - 1
    if cont + t >= tr:
        flag = False
        break

    if array[num] <= cont:
        cont += t
    else: #te = 0
        print(cont)
        exit(0)
if cont + t <= tr and flag:
    #te =0
    print(cont)
    exit(0)
# percorreu tudo e foi em busca do menor intervalo
if TchegarAntes <= menor and array[0] - 1 >= 0:
    print(array[0] - 1)
else:
    print(idx)