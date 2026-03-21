n, q = map(int, input().split())
times = [int(i) for i in input().split()]

def prod(mid):
    total = 0
    for t in times:
        total += mid // t
        if total >= q:
            break
    return total

l = 0
r = q * max(times)

resultado = -1
while l <= r:
    mid = (l + r) // 2 
    if prod(mid) >= q:
        resultado = mid
        r = mid - 1
    else:
        l = mid + 1

print(resultado)
