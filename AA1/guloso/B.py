n = int(input())
array = sorted([int(i) for i in input().split()], reverse= True)

a, b = 0, 0

for peso in array:
    if a <= b:
        a += peso
    else:
        b += peso

print(abs(a - b))
