#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

void primeSieve(vector<bool> &isPrime) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> isPrime(MAX + 1, true);
    primeSieve(isPrime);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        bool conjectureValid = false;
        for (int a = 2; a <= n / 2; ++a) {
            if (isPrime[a] && isPrime[n - a]) {
                cout << n << " = " << a << " + " << n - a << "\n";
                conjectureValid = true;
                break;
            }
        }

        if (!conjectureValid) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}

