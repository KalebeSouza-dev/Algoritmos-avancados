a, b, c = map(int, input().split())
for k in range(1, b+1):
    if (a * k) % b == c:
        print("YES")
        break
else:
    print("NO")