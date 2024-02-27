#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  // 명령의 수
  int n;
  cin >> n;

  // 스택 선언
  stack<int> s;

  string cmd;
  int x;

  while (n--) {
    cin >> cmd;

    // push: 스택에 x 삽입
    if (cmd == "push") {
      cin >> x;
      s.push(x);
    }
    
    // pop: 스택에서 top 원소 삭제하고 출력
    else if (cmd == "pop") {
      // 스택이 비어 있을 시 -1 출력
      if (s.empty()) { 
        cout << "-1\n";
      }
      else {
        cout << s.top() << "\n";
        s.pop();
      }
        }

    // size: 스택의 크기 출력
    else if (cmd == "size") {
      cout << s.size() << "\n";
    }

    // empty: 스택이 비어있는지 확인
    else if (cmd == "empty") {
      cout << s.empty() << "\n";
    }

    //top: 스택의 top 출력
    else if (cmd == "top") {
      if (s.empty()) { //스택이 비어 있을 시 -1 리턴
        cout << "-1\n";
      }
      else {
        cout << s.top() << "\n";
      }
    }
  }

  return 0;
}