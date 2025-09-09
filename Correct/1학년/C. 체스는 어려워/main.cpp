#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> score = {
        {'Q', 9}, {'R', 5}, {'B', 3}, {'N', 3}, {'P', 1},
        {'q', 9}, {'r', 5}, {'b', 3}, {'n', 3}, {'p', 1}
    };

    int white = 0, black = 0;
    string row;

    for (int i = 0; i < 8; ++i) {
        cin >> row;
        for (char ch : row) {
            if (ch == '.') continue;
            if (score.find(ch) == score.end()) continue;
            if (isupper(ch))
                black += score[ch];
            else
                white += score[ch];
        }
    }

    if (white > black)
        cout << "White" << endl;
    else if (black > white)
        cout << "Black" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}