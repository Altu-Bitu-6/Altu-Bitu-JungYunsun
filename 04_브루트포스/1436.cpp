#include <iostream>
#include <string>
using namespace std;

int findSeriesNumber(int count) {
    int number = 666;
    int seriesCount = 0;
    string numberStr;
    while (true) {
        numberStr = to_string(number);
        for (int i = 0; i < numberStr.length() - 2; i++) {
            if (numberStr[i] == '6' && numberStr[i + 1] == '6' && numberStr[i + 2] == '6') {
                seriesCount++;
                if (seriesCount == count)
                    return number;
                break;
            }
        }
        number++;
    }
}

int main() {
    int N;
    cin >> N;
    cout << findSeriesNumber(N);
    return 0;
}
