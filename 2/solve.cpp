#include <iostream>
#include <algorithm>
using namespace std;

int N; // 상자의 크기
int Box[150][150];

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Box[i][j];
        }
    }
}

int main() {
    long long ans = -1;
    InputData(); // 입력 받는 부분
	

    long long rowSum[150] = {0};
    long long colSum[150] = {0};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rowSum[i] += Box[i][j];
            colSum[j] += Box[i][j];
        }
    }

    long long maxRow = 0, maxCol = 0;
    for (int i = 0; i < N; ++i) maxRow = max(maxRow, rowSum[i]);
    for (int j = 0; j < N; ++j) maxCol = max(maxCol, colSum[j]);

    long long T = max(maxRow, maxCol);

    ans = 0;
    for (int i = 0; i < N; ++i) ans += (T - rowSum[i]);
	

    cout << ans << endl; // 출력하는 부분
    return 0;
}
