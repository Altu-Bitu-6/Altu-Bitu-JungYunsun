#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string name;
    std::cin >> name;

    int length = name.length();
    std::vector<char> array(length);
    std::vector<char> stack;
    std::vector<char> popped;

    // 입력 문자열을 배열로 바꾸기
    for (int i = 0; i < length; ++i) {
        array[i] = name[i];
    }

    std::sort(array.begin(), array.end());

    for (int i = 0; i < length; ++i) {
        // 스택이 비어있으면
        if (stack.empty()) {
            stack.push_back(array[i]);
        } else {
            if (stack.back() == array[i]) {
                char a = stack.back();
                stack.pop_back();
                popped.push_back(a);
            } else {
                stack.push_back(array[i]);
            }
        }
    }

    if (stack.empty() || stack.size() == 1) {
        for (char i : popped) {
            std::cout << i;
        }
        if (!stack.empty()) {
            std::cout << stack.back();
        }
        std::reverse(popped.begin(), popped.end());
        for (char i : popped) {
            std::cout << i;
        }
    } else {
        std::cout << "I'm Sorry Hansoo";
    }

    return 0;
}
