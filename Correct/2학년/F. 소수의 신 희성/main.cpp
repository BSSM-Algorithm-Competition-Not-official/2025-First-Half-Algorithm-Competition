#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void backtrack(vector<int>& V, vector<bool>& used, vector<int>& path, int M, set<int>& seen, int& count) {
    if (!path.empty() && path.size() <= M) {
        int num = 0;
        for (int d : path) num = num * 10 + d;
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            if (is_prime(num)) ++count;
        }
    }
    if (path.size() == M) return;

    for (int i = 0; i < V.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            path.push_back(V[i]);
            backtrack(V, used, path, M, seen, count);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) cin >> V[i];

    vector<bool> used(N, false);
    vector<int> path;
    set<int> seen;
    int count = 0;

    backtrack(V, used, path, M, seen, count);
    cout << count << '\n';
    return 0;
}