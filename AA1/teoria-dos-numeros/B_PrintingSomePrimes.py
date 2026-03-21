num = 10**8

print(2)
nums = bytearray([1]) * (num + 1)
cont = 1
for i in range(3, num + 1, 2):
    if not nums[i]: continue
    cont += 1
    if cont % 100 == 1:
        print(i)
    for j in range(i*i, num + 1, 2 * i):
        if j > num: break
        nums[j] = 0
