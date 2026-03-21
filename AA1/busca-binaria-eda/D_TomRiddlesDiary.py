n = int(input())
s = set()
for i in range(n):
    l = input()
    if l in s:
        print("YES")
    else:
        print("NO")
    s.add(l)