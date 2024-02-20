#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  // 입출력 속도 향상
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  string input;
  map<string, int> s;
  int total = 0;

  // 입력
  cin >> n >> m;

  while (n--) {
    cin >> input;
    s[input] = 1; // set(집합 S)에 문자열 추가
  }

  // 연산
  while (m--) {
    cin >> input;
    total += s[input];
  }

  // 출력
  cout << total;

  return 0;
}