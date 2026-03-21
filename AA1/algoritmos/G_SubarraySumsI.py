n, x = map(int, input().split())
nums = list(map(int, input().split()))

l = 0
r = 0
soma = nums[0]
cont = 0

while l < n:
    if soma == x:
        cont += 1
    if r == n - 1 or soma > x:
        soma -= nums[l]
        l += 1
    else:
        r += 1
        soma += nums[r]

print(cont)