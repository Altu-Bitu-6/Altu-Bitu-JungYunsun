#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<int, bool> setBits;
    int M;
    cin >> M;
    while (M--) {
        string op;
        cin >> op;
        int num;
        if (op == "add" || op == "remove" || op == "check" || op == "toggle") {
            cin >> num;
        }
        if (op == "add") {
            setBits[num] = true;
        } else if (op == "remove") {
            setBits.erase(num);
        } else if (op == "check") {
            cout << (setBits.count(num) ? 1 : 0) << "\n";
        } else if (op == "toggle") {
            if (setBits.count(num)) {
                setBits.erase(num);
            } else {
                setBits[num] = true;
            }
        } else if (op == "all") {
            for (int i = 1; i <= 20; ++i) {
                setBits[i] = true;
            }
        } else if (op == "empty") {
            setBits.clear();
        }
    }

    return 0;
}
