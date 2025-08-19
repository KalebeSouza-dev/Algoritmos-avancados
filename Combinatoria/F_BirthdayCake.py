t = int(input())
if t == 1: 
    print(0)
    exit()
fact = [1] * (t+1)
for i in range(1, len(fact)):
    fact[i] = i * fact[i - 1]
m = []
cc = 0
for _ in range(t):
    s = input()
    m.append(s)

    contl = 0
    for i in s:
        if i == 'C': contl += 1
    cc += (fact[contl] // (fact[contl -2] * fact[2]))

for j in range(t):
    contc = 0
    for i in range(t):
        if m[i][j] == 'C': contc += 1
    cc += (fact[contc] // (fact[contc -2] * fact[2]))

print(cc)