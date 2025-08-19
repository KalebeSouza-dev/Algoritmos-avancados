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
primo = primos(10**7)

MAX = 10**7
eh = [0] * (MAX + 1)
yy = int(MAX**0.25) + 1
for y in range(1, yy):
    y4 = y**4
    if y4 > MAX:
        break
    xx = int((MAX - y4)**0.5) + 1
    for x in range(1, xx):
        val = x**2 + y4
        if val <= MAX:
            eh[val] = 1

soma = [0] * (MAX + 5)
for i in range(1, MAX + 1):
    if eh[i] == 1 and primo[i]:
        soma[i] = soma[i - 1] + 1
    else:
        soma[i] = soma[i - 1]

t = int(input())
for _ in range(t):
    n = int(input())
    print(soma[n])