#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    vector<pair<int, long long>> ops;
    long long result = 0;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            result += x;
            ops.emplace_back(1, x);
        } else if (type == 2) {
            long long x;
            cin >> x;
            result -= x;
            ops.emplace_back(2, x);
        } else if (type == 3) {
            int j;
            cin >> j;
            while (j--) {
                auto [op, x] = ops.back();
                ops.pop_back();
                if (op == 1) result -= x;
                else result += x;
            }
        } else if (type == 4) {
            cout << result << '\n';
        } else if (type == 5) {
            cout << ops.size() << '\n';
        }
    }

    return 0;
}