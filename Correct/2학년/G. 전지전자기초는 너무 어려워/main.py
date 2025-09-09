import sys
import threading
from collections import defaultdict

def main():
    import sys
    sys.setrecursionlimit(10**6)
    
    N, M = map(int, sys.stdin.readline().split())
    edge_map = defaultdict(list)

    temp_map = defaultdict(list)
    for _ in range(M):
        u, v, r = map(int, sys.stdin.readline().split())
        temp_map[(u, v)].append(r)
        temp_map[(v, u)].append(r)

    for (u, v), resistances in temp_map.items():
        inverse_sum = sum(1 / r for r in resistances)
        equiv = 1 / inverse_sum
        edge_map[u].append((v, equiv))

    visited = [False] * (N + 1)

    def dfs(node):
        visited[node] = True
        total = 0.0
        for neighbor, resistance in edge_map[node]:
            if not visited[neighbor]:
                child_r = dfs(neighbor)
                total += resistance + child_r
        return total

    result = dfs(1)
    print(f"{result:.6f}")

threading.Thread(target=main).start()