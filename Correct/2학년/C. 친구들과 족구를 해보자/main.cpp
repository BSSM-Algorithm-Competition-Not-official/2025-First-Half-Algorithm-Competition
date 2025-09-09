#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int H = 10, W = 20;
char grid[H][W];
int dist[H][W];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    pair<int, int> ball;
    map<char, pair<int, int>> people;

    // 입력
    for (int i = 0; i < H; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < W; ++j) {
            grid[i][j] = line[j];
            dist[i][j] = -1;
            if (grid[i][j] == 'x') {
                ball = {i, j};
            } else if (isupper(grid[i][j])) {
                people[grid[i][j]] = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(ball);
    dist[ball.first][ball.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W
                && dist[nx][ny] == -1 && grid[nx][ny] != '#') {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int min_dist = 1e9;
    char answer = 0;

    for (auto& [name, pos] : people) {
        int px = pos.first, py = pos.second;
        int d = dist[px][py];
        if (d != -1 && d < min_dist) {
            min_dist = d;
            answer = name;
        }
    }

    if (answer == 0) {
        cout << "Ouch!\n";
    } else {
        cout << answer << '\n' << min_dist << '\n';
    }

    return 0;
}