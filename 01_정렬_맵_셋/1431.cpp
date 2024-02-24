#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 인자로 받은 배열 속 정수들의 합을 계산해주는 함수
int sumOfDigits(const string& s) {
  int sum = 0;
  for (char c : s) {
    if (isdigit(c)) {
      sum += c - '0';
    }
  }
  return sum;
}

bool cmp(const string& s1, const string& s2) {
  // A와 B의 길이가 다르면, 짧은 것이 먼저 온다
  if (s1.size() != s2.size()) {
    return s1.size() < s2.size();
  }

  // 길이가 같다면, 모든 숫자 자리수의 합이 작은 것이 먼저 온다
  else {
    int sum_s1 = sumOfDigits(s1);
    int sum_s2 = sumOfDigits(s2);
    if (sum_s1 != sum_s2)
    {
      return sum_s1 < sum_s2;
    }
    // 자리수도 같다면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
    else {
      return s1 < s2;
    }
  }
}

int main() {
  // 입력
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // 연산
  sort(arr.begin(), arr.end(), cmp);

  // 출력
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\n';
  }

  return 0;
}