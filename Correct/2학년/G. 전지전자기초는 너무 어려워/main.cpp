#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
map<pair<int, int>, vector<double>> raw_edges;
vector<vector<pair<int, double>>> adj;
vector<bool> visited;

double combine_parallel(const vector<double>& resistances) {
    double sum_inv = 0.0;
    for (double r : resistances)
        sum_inv += 1.0 / r;
    return 1.0 / sum_inv;
}

double dfs(int node) {
    visited[node] = true;
    double total = 0.0;
    for (auto [neighbor, resistance] : adj[node]) {
        if (!visited[neighbor]) {
            double child_r = dfs(neighbor);
            total += resistance + child_r;
        }
    }
    return total;
}

int main() {
    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        double r;
        cin >> u >> v >> r;
        raw_edges[{u, v}].push_back(r);
        raw_edges[{v, u}].push_back(r);
    }

    for (auto& [uv, rlist] : raw_edges) {
        int u = uv.first, v = uv.second;
        double equiv = combine_parallel(rlist);
        adj[u].emplace_back(v, equiv);
    }

    double result = dfs(1);
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}