import sys
input = sys.stdin.readline

N, M = map(int, input().split())
X, Y, C = map(int, input().split())

pain = [list(map(int, input().split())) for _ in range(N)]

reduced = [[min(pain[i][j], C) for j in range(M)] for i in range(N)]

prefix = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, M + 1):
        prefix[i][j] = (
            reduced[i - 1][j - 1]
            + prefix[i - 1][j]
            + prefix[i][j - 1]
            - prefix[i - 1][j - 1]
        )

max_reduction = -1
best_row = best_col = -1

for i in range(X, N + 1):
    for j in range(Y, M + 1):
        total = (
            prefix[i][j]
            - prefix[i - X][j]
            - prefix[i][j - Y]
            + prefix[i - X][j - Y]
        )
        if total > max_reduction:
            max_reduction = total
            best_row = i - X + 1
            best_col = j - Y + 1

print(f"{best_row} {best_col}")
print(max_reduction)