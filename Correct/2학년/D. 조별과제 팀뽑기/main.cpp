#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i)
        cin >> scores[i];

    sort(scores.begin(), scores.end());

    int left = 0, right = N - 1, count = 0;

    while (left < right) {
        long long sum = (long long)scores[left] + scores[right];
        if (sum == X) {
            ++count;
            ++left;
            --right;
        } else if (sum < X) {
            ++left;
        } else {
            --right;
        }
    }

    cout << count << '\n';
    return 0;
}