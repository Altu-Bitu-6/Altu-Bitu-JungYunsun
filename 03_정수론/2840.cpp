#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<pair<int, char>> pan(N, make_pair(-1, '?')); // pair<카운트, 문자>

    int index = 0;
    for (int i = 0; i < K; ++i) {
        int count;
        char tmpc;
        cin >> count >> tmpc;
        
        index = (index + count) % N;
        
        if (pan[index].first != -1 && pan[index].second != tmpc) {
            cout << "!";
            return 0;
        } else {
            pan[index] = make_pair(i, tmpc);
        }
    }

    // 중복 체크
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (pan[i].second != '?' && pan[i].second == pan[j].second) {
                cout << "!";
                return 0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << pan[index].second;
        index = (index == 0) ? N - 1 : index - 1;
    }

    return 0;
}
