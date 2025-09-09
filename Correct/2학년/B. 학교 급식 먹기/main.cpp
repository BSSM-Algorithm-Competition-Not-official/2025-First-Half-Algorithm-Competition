#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> score(N);
    for (int i = 0; i < N; ++i)
        cin >> score[i];

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> dp(N);
    dp[0] = max(0, score[0]);

    if (N >= 2)
        dp[1] = max(dp[0], score[1]);

    for (int i = 2; i < N; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2] + score[i]);

    cout << dp[N - 1] << '\n';
    return 0;
}