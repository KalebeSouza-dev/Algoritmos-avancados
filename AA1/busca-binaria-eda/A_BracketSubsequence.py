n, q = map(int, input().split())
entrada = input()

qmet= q//2
contA = 0
contB = 0
result = []

for i in range(n):
    if entrada[i] == '(' and contA < qmet: 
        result.append('(')
        contA += 1
    elif entrada[i] == ')' and contB < qmet:
        result.append(')')
        contB += 1

print(''.join(result))