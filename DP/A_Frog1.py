n = int(input())
h = [int(i) for i in input().split()]

dp = [10**9] * n
dp[0] = 0
for i in range(1, n):
    dp[i] = dp[i-1] + abs(h[i] - h[i-1])
    if i > 1:
        dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]))

# print(dp)
print(dp[-1])