cont = 0
for i in range(1, 6):
    l = list(map(int, input().split()))
    if 1 in l:
        cont += abs(3 - i)
        for j in range(5):
            if l[j] == 1:
                cont += abs(3 - (j + 1))
print(cont)
                