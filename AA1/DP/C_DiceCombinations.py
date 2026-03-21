n = int(input())
MOD = 10**9 + 7

dp = [0] * (n + 1)
dp[0] = 1

soma = dp[0]
for i in range(1, n + 1):
    dp[i] = soma % MOD
    soma += dp[i]
    if i >= 6:
        soma -= dp[i - 6]

print(dp[n] % MOD)
