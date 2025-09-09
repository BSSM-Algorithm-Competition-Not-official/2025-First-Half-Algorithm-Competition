N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

sumA = sum(A)
sumB = sum(B)

diff = sumA - sumB

if diff < 0:
    print("easy")
elif diff >= 100:
    print("impossible")
else:
    print(diff + 1)