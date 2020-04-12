#include <iostream>
#include <bitset>
using namespace std;

// algorithm ref: https://www.youtube.com/watch?v=OlpC2d1Odrs

int main()
{
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << endl;
        if (N <= 30) {
            for (int i = 1; i < N+1; i++) {
                cout << i << " " << 1 << endl;
            }
            continue;
        }
        string bin = bitset<30>(N-30).to_string();
        // cout << bin << endl;
        bool is_left = true;
        int one_cnt = 0;
        for (int i = 1; i <= 30; i++) {
            cout << i << " " << (is_left ? 1 : i) << endl;
            if (bin[30-i] == '1') {
                if (is_left) {
                    for (int j = 2; j <= i; j++) {
                        cout << i << " " << j << endl;
                    }
                } else {
                    for (int j = i-1; j >= 1; j--) {
                        cout << i << " " << j << endl;
                    }
                }
                is_left = !is_left;
                one_cnt++;
            }
        }
        for (int i = 31; i < 31+one_cnt; i++) {
            cout << i << " " << (is_left ? 1 : i) << endl;
        }
    }
}
