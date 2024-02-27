#include <iostream>
#include <queue>

using namespace std;

void question(int N, int K) {
  queue<int> q;

  for (int i = 1; i <= N; ++i) {
    q.push(i);
  }

  cout << "<";

  while (q.size() > 1) {
    for (int i = 0; i < K - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }

  cout << q.front() << ">";
}

int main() {
  int N, K;
  cin >> N >> K;

  question(N, K);

  return 0;
}