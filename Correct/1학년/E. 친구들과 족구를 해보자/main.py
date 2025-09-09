from collections import deque

H, W = 10, 20
grid = [input().strip() for _ in range(H)]

dist = [[-1] * W for _ in range(H)]
q = deque()

people = {}

for i in range(H):
    for j in range(W):
        char = grid[i][j]
        if char == 'x':
            sx, sy = i, j
        elif 'A' <= char <= 'Z':
            people[char] = (i, j)

q.append((sx, sy))
dist[sx][sy] = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while q:
    x, y = q.popleft()
    for dir in range(4):
        nx, ny = x + dx[dir], y + dy[dir]
        if 0 <= nx < H and 0 <= ny < W and dist[nx][ny] == -1 and grid[nx][ny] != '#':
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))

min_dist = float('inf')
min_person = ''

for name in people:
    x, y = people[name]
    d = dist[x][y]
    if d != -1 and d < min_dist:
        min_dist = d
        min_person = name

print(f"{min_person} {min_dist}")