#include <iostream>
#include <string>

using namespace std;

string calculate(string A, string B, string &answer) {
  // 올림수
  int carry = 0;
  // 각 숫자의 자릿수
  int A_size = A.size();
  int B_size = B.size();

  while (A_size > 0 || B_size > 0) {
    // A, B의 자릿수
    int A_num = 0;
    int B_num = 0;
    // 각 자릿수의 합
    int sum = 0;
    // 각 자릿수를 문자로 변환한 값
    char sum_to_char;

    // A, B의 자릿수를 일의 자리부터 하나씩 넣음
    if (A_size > 0) {
      A_num = A[--A_size] - '0';   // A_num = 2 (십만의 자리 숫자)
    }
    if (B_size > 0) {
      B_num = B[--B_size] - '0';  // B_num = 0 (만의 자리 숫자)
    }

    sum = A_num + B_num + carry;

    // 올림수와 남은 수 변경
    carry = sum / 10;
    sum %= 10;

    sum_to_char = sum + '0';

    // 결과값에 일의 자리부터 추가
    answer += sum_to_char;
  }

  // 올림수가 마지막까지 남아있다면
  if (carry > 0) {
    answer += carry + '0';
  }

  return answer;
}

int main() {
  // 문자열
  string A, B, answer;

  // 입력 받기
  cin >> A >> B;

  // 연산
  calculate(A, B, answer);

  // 출력
  for (int i = answer.length() - 1; i >= 0; i--) {
    cout << answer[i];
  }

  return 0;
}