#include <iostream>

using namespace std;

int euclideanAlgorithm(int a, int b) {
    while (b != 0) {
        int remainder = b;
        b = a % b;
        a = remainder;
    }
    return a;
}

pair<int, int> simplifyFraction(int numerator, int denominator) {
    int common_divisor = euclideanAlgorithm(numerator, denominator);
    return {numerator / common_divisor, denominator / common_divisor};
}

pair<int, int> addFractions(int num1, int deno1, int num2, int deno2) {
    int common_deno = deno1 * deno2;
    int new_num1 = num1 * deno2;
    int new_num2 = num2 * deno1;
    int result_num = new_num1 + new_num2;
    return simplifyFraction(result_num, common_deno);
}

int main() {
    int num1, deno1, num2, deno2;
    cin >> num1 >> deno1 >> num2 >> deno2;

    auto result = addFractions(num1, deno1, num2, deno2);

    cout << result.first << " " << result.second << endl;

    return 0;
}

