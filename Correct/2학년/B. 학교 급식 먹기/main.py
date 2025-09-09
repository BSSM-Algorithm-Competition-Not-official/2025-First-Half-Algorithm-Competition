N = int(input())
score = list(map(int, input().split()))

if N == 0:
    print(0)
    exit()

dp = [0] * N
dp[0] = max(0, score[0])

if N >= 2:
    dp[1] = max(dp[0], score[1])

for i in range(2, N):
    dp[i] = max(dp[i - 1], dp[i - 2] + score[i])

print(dp[N - 1])