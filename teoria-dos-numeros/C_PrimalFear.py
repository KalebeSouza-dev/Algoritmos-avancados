import sys
input = sys.stdin.readline

def primos(num):
    primo = bytearray([1]) * (num + 1)
    primo[0] = primo[1] = 0
    for i in range(2, int(num ** 0.5) + 1):
        if primo[i]:   
            for j in range(i*i, num + 1, i):
                primo[j] = 0
    return primo

def eh_bom(num, primo):
    s = str(num)
    if '0' in s:
        return False
    for i in range(len(s)):
        if not primo[int(s[i:])]:
            return False
    return True

t = int(input())
entrada = []
for _ in range(t):
    num = int(input())
    entrada.append(num)

maior = max(entrada)
primo = primos(maior)

bons = [0] * (maior + 1)
for i in range(1, maior + 1):
    if primo[i] and eh_bom(i, primo):
        bons[i] = bons[i - 1] + 1
    else:
        bons[i] = bons[i - 1]

for i in entrada:
    print(bons[i])
