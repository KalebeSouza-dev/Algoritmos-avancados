n, m = map(int, input().split())
a = [int(i) for i in input().split()]

soma = 0
bus = 1
for grupo in a:
    if soma + grupo <= m:
        soma += grupo
    else:
        bus += 1
        soma = grupo

print(bus)
