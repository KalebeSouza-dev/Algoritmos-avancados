n = int(input())
xx = list(map(int, input().split()))
yy = list(map(int, input().split()))
x = set(xx[1:])

y = set(yy[1:])
x.update(y)

if len(x) == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
