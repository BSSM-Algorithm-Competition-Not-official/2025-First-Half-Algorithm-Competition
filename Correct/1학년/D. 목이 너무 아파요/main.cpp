#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int X, Y, C;
    cin >> X >> Y >> C;

    vector<vector<int>> pain(N, vector<int>(M));
    vector<vector<int>> reduced(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> pain[i][j];
            reduced[i][j] = min(pain[i][j], C);
        }

    vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            prefix[i][j] = reduced[i-1][j-1]
                         + prefix[i-1][j]
                         + prefix[i][j-1]
                         - prefix[i-1][j-1];

    long long max_reduction = -1;
    int best_r = -1, best_c = -1;

    for (int i = X; i <= N; ++i) {
        for (int j = Y; j <= M; ++j) {
            long long sum = prefix[i][j]
                          - prefix[i - X][j]
                          - prefix[i][j - Y]
                          + prefix[i - X][j - Y];
            if (sum > max_reduction) {
                max_reduction = sum;
                best_r = i - X + 1;
                best_c = j - Y + 1;
            }
        }
    }

    cout << best_r << ' ' << best_c << '\n';
    cout << max_reduction << '\n';
    return 0;
}