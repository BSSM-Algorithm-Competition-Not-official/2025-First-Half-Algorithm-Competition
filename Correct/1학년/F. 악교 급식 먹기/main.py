N = int(input())
score = list(map(int, input().split()))

dp = [0] * N
dp[0] = max(0, score[0])

if N >= 2:
    dp[1] = max(dp[0], score[1])

for i in range(2, N):
    dp[i] = max(dp[i - 1], dp[i - 2] + score[i])

print(dp[N - 1])