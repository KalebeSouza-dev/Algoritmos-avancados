a, b = map(int, input().split())
cont = 0
for i in range(a, b + 1, 1):
    if str(i) == str(i)[::-1]:
        cont += 1
print(cont)