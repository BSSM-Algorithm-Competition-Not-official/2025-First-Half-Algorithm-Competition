#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N - 1);
    int sumA = 0, sumB = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    int diff = sumA - sumB;

    if (diff < 0)
        cout << "easy\n";
    else if (diff >= 100)
        cout << "impossible\n";
    else
        cout << diff + 1 << '\n';

    return 0;
}