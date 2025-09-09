#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int math, science, english;
    int index;
};

int main() {
    int N;
    cin >> N;

    vector<Student> students(N);

    for (int i = 0; i < N; ++i) {
        cin >> students[i].name >> students[i].math >> students[i].science >> students[i].english;
        students[i].index = i;
    }

    string order, subject;
    cin >> order >> subject;

    stable_sort(students.begin(), students.end(), [&](const Student& a, const Student& b) {
        int val_a, val_b;
        if (subject == "math") {
            val_a = a.math;
            val_b = b.math;
        } else if (subject == "science") {
            val_a = a.science;
            val_b = b.science;
        } else { // english
            val_a = a.english;
            val_b = b.english;
        }

        if (order == "asc")
            return val_a < val_b;
        else
            return val_a > val_b;
    });

    for (const auto& student : students) {
        cout << student.name << '\n';
    }

    return 0;
}