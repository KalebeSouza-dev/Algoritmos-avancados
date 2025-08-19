num = int(input())
nums = bytearray([1]) * (num + 1)
primos = {2}
for i in range(3, num + 1, 2):
    if not nums[i]: continue
    primos.add(i)
    for j in range(i*i, num + 1, 2 * i):
        if j > num: break
        nums[j] = 0

cont = 0
for i in range(1, num + 1):
    result = set()
    for j in range(1, i):
        if i % j != 0: continue
        if j in primos:
            result.add(j)
        if i // j in primos:
            result.add(i//j)
    if len(result) == 2: cont += 1
print(cont)