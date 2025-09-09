N, X = map(int, input().split())
scores = list(map(int, input().split()))

scores.sort()

left = 0
right = N - 1
count = 0

while left < right:
    s = scores[left] + scores[right]
    if s == X:
        count += 1
        left += 1
        right -= 1
    elif s < X:
        left += 1
    else:
        right -= 1

print(count)