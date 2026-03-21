n = int(input())
for _ in range(n):
    q = int(input())
    seg = 1
    result = []
    for i in range(q):
        ll, rr = map(int, input().split())
        seg = max(seg, ll)
        if seg <= rr:
            result.append(seg)
            seg += 1
        else:
            result.append(0)
    print(*result)
