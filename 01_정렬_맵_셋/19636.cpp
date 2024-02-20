#include <iostream>
#include <cmath>
using namespace std;

// 다이어트 후 체중과 일일 기초 대사량을 계산하는 함수
void cal(int w, int basic, int t, int day, int d_input, int d_output) {
    int w1 = w;
    int w2 = w;
    int basic2 = basic;

    for (int i = 0; i < day; i++) {
        w1 += d_input - (basic + d_output);
        w2 += d_input - (basic2 + d_output);

        if (abs(d_input - (basic2 + d_output)) > t)
            basic2 += floor((d_input - (basic2 + d_output)) / 2.0);
    }

    // 출력 01. 일일 기초대사량의 변화 반영 X
    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << basic << "\n";

    // 출력 02. 일일 기초대사량의 변화 반영 O
    if (w2 <= 0 || basic2 <= 0)
        cout << "Danger Diet\n";
    else {
        cout << w2 << " " << basic2 << " ";
        if (basic - basic2 > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}

int main() {
    int w, basic, t, day, d_input, d_output;

    // 입력
    cin >> w >> basic >> t;
    cin >> day >> d_input >> d_output;

    // 함수 호출
    cal(w, basic, t, day, d_input, d_output);

    return 0;
}
