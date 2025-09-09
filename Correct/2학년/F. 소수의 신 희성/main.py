from itertools import permutations

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

N, M = map(int, input().split())
V = list(map(int, input().split()))

seen = set()
count = 0

for k in range(1, M+1):
    for p in permutations(V, k):
        num = int(''.join(map(str, p)))
        if num not in seen:
            seen.add(num)
            if is_prime(num):
                count += 1

print(count)