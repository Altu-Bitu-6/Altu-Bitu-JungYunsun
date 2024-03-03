#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void josephus(int N, int K, vector<int> &v) {
  queue<int> q;

  // enqueue
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  // dequeue
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < K; j++) {
      q.push(q.front());
      q.pop();
    }
    int temp = q.front();
    v.push_back(temp);
    q.pop();
  }
}

int main() {
  int N, K;
  vector<int> v;

  // 입력
  cin >> N >> K;

  // 연산
  josephus(N, K, v);

  // 출력
  cout << '<';
  for (int i = 0; i < N - 1; i++) {
    cout << v[i] << ", ";
  }
  cout << v[N - 1];
  cout << ">\n";

  return 0;
}
