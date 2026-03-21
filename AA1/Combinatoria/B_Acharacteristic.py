t = int(input())

fact = [1] * (101)
for i in range(1, len(fact)):
    fact[i] = i * fact[i - 1]

for _ in range(t):
    n, k = map(int , input().split())
    for i in range(n + 1):
        ff = (fact[n - i] // (fact[n - i - 2] * fact[2])) + (fact[i] // (fact[i - 2] * fact[2]))
        if ff == k:
            print("YES")
            array = [1] * (n - i) + [-1] * (i)
            print(*array)
            break
    else:
        print("NO")