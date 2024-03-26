#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    // 배열 입력 받기
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long result = arr[n - 1]; // 결과 값 초기화

    // 역순으로 배열을 탐색하며 계산
    for (int i = n - 2; i >= 0; --i) {
        if (result % arr[i] == 0) // 현재 결과 값이 현재 배열 값으로 나누어 떨어지면 다음 배열 값으로 넘어감
            continue;
        long long multiplier = result / arr[i] + 1; // 현재 배열 값으로 나눈 몫에 1을 더한 값
        result = arr[i] * multiplier; // 새로운 결과 값 계산
    }

    std::cout << result << std::endl;

    return 0;
}
