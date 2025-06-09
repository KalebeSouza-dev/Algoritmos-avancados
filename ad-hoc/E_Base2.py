seq = input().split()
soma = 0
for i in range(64):
    if seq[i] == "1":
        soma += 2 ** i

print(soma)