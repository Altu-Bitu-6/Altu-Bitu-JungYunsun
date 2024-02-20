#include <iostream>
#include <map>
#include <string>

using namespace std;

// 연산
void case1(int w0, int i0, int t, int d, int i, int a) {
  int w;
  int w_change = 0;
  int b = i0;
  string is_YOYO = "";

  while (d--) {
    w_change = i - (b + a);
    w += w_change;
  }

    // 데시가 죽는 경우
    // 체중이 0 이하
    if (w <= 0) {
      cout << "Danger Diet";
      return;
    }
  cout << w << b << '\n';
}

void case2(int w0, int i0, int t, int d, int i, int a) {
  int w;
  int w_change = 0;
  int b = i0;
  string is_YOYO = "";

  while (d--) {
    w_change = i - (b + a);
    w += w_change;
    if (w_change > t)
    {
      b += (w_change / 2);
    }

    // 데시가 죽는 경우
    // 체중이 0 이하
    if (w <= 0) {
      cout << "Danger Diet" << '\n';
      return;
    }
    // 기초대사량이 0 이하
    if (b <= 0) {
      cout << "Dagner Diet" << '\n';
    }
  }

  if ((i0 - (b + a)) > 0) {
    is_YOYO = "YOYO";
  }
  else {
    is_YOYO = "NO";
  }

  cout << w << b << is_YOYO << '\n';
}

int main () {
  // 입출력 속도 향상
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w0, i0, t;
  int d, i, a;
  int w;
  int w_change = 0;
  int b = i0;
  string is_YOYO = "";

  // 입력
  cin >> w0 >> i0 >> t >> d >> i >> a;

  // 출력
  case1(w0, i0, t, d, i, a);
  case2(w0, i0, t, d, i, a);
}