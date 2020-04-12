#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << endl;
        cout << 1 << " " << 1 << endl;
        if (N == 1) {
            continue;
        }
        cout << 2 << " " << 1 << endl;
        if (N > 3) {
            cout << 3 << " " << 2 << endl;
        } else if (N == 3) {
            cout << 3 << " " << 1 << endl;
        }
        for (int i = 3; i < N-1; i++) {
            cout << i << " " << 1 << endl;
        }
    }
}
