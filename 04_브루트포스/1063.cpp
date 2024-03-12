#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[8][8];
// r, l, b, t, rt, lt, rb, lb
int dx[8] = {0, 0, +1, -1, -1, -1, +1, +1};
int dy[8] = {+1, -1, 0, 0, +1, -1, +1, -1};
char inputKy, inputSy;
int inputKx, inputSx, n;
vector<string> moves;

// 말과 돌을 이동시키는 함수
void moveKingAndStone() {
    int kx = 8 - inputKx; 
    int ky = inputKy - 'A';
    int sx = 8 - inputSx; 
    int sy = inputSy - 'A';

    // 주어진 이동 명령에 따라 이동
    for (int m = 0; m < n; m++) {
        string move = moves[m];
        int i = 0;
        if (move == "R") {
            i = 0;
        }
        else if (move == "L") {
            i = 1;
        }
        else if (move == "B") {
            i = 2;
        }
        else if (move == "T") {
            i = 3;
        }
        else if (move == "RT") {
            i = 4;
        }
        else if (move == "LT") {
            i = 5;
        }
        else if (move == "RB") {
            i = 6;
        }
        else {
            i = 7;
        }
        int nx = kx + dx[i];
        int ny = ky + dy[i];
        
        // 말이 이동 가능한지 확인
        if (nx < 0 || nx > 7 || ny < 0 || ny > 7 ) {
            continue;
        }
        
        // 돌이 존재하고 이동 가능한지 확인
        if (nx == sx && ny == sy) {
            int nsx = sx + dx[i];
            int nsy = sy + dy[i];
            if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) {
                continue;
            }
            else {
                sx = nsx; sy = nsy;
            }
        }
        
        // 말 이동
        kx = nx; ky = ny;
    }
    
    // 결과 출력
    printf("%c%d\n", 'A' + ky, 8 - kx);
    printf("%c%d", 'A' + sy, 8 - sx);
}

int main() {
    // 입력 받기
    scanf("%c%d %c%d %d", &inputKy, &inputKx, &inputSy, &inputSx, &n);

    // 이동 명령 저장
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        moves.push_back(str);
    }
    
    // 말과 돌 이동 함수 호출
    moveKingAndStone();
    
    return 0;
}
