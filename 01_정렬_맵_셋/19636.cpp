#include <iostream>
#include <cmath>
using namespace std;

// 다이어트 후 체중과 일일 기초 대사량을 계산하는 함수
// 연산 후 출력해야 하는 값은 참조 매개변수를 사용해서 연산된 값을 반영함.
void cal(int weight, int basic, int t, int day, int d_input, int d_output, int &w1, int &w2, int &basic2) {
    for (int i = 0; i < day; i++) {
        w1 += d_input - (basic + d_output);
        w2 += d_input - (basic2 + d_output);

        if (abs(d_input - (basic2 + d_output)) > t)
            basic2 += floor((d_input - (basic2 + d_output)) / 2.0);
    }
}

int main() {
    int weight, basic, t, day, d_input, d_output;

    // 입력
    cin >> weight >> basic >> t;
    cin >> day >> d_input >> d_output;

    // 연산 후 출력할 값을 담은 변수 미리 선언
    int w1 = weight;
    int w2 = weight;
    int basic2 = basic;

    // 연산
    cal(weight, basic, t, day, d_input, d_output, w1, w2, basic2);

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

    return 0;
}
