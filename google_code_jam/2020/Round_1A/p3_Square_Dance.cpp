#include <iostream>
#include <cmath>
using namespace std;

bool lt(double a, double b)
{
    double epsilon = 0.00001;
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main()
{
    int T, R, C;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        int sq[R+2][C+2] = {};
        int sum = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> sq[i][j];
                sum += sq[i][j]; // first round
            }
        }

        int last_sum = 0;
        int cur_sum = 0;
        while (true) {
            bool change = false;
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    if (R>1&&C>1 &&(i == 1 || j == 1 || i==R || j==C))
                        continue;
                    int cut = 0;
                    // int inc = 0;
                    cur_sum = 0;
                    int num = 0;
                    if (sq[i][j]   != 0) {num++;}
                    if (sq[i-1][j] != 0) {num++;}
                    if (sq[i+1][j] != 0) {num++;}
                    if (sq[i][j-1] != 0) {num++;}
                    if (sq[i][j+1] != 0) {num++;}
                    // inc += sq[i][j]; // other round
                    if (num <= 1)
                        continue;
                    double avg = (sq[i][j] + sq[i-1][j] + sq[i+1][j] + sq[i][j-1] + sq[i][j+1])/double(num);
                    // cout << avg << " " << num << endl;
                    if (lt(double(sq[i][j])   , avg) )   { sq[i][j] = 0;  }
                    if (lt(double(sq[i-1][j]) , avg) ) { sq[i-1][j] = 0;}
                    if (lt(double(sq[i+1][j]) , avg) ) { sq[i+1][j] = 0;}
                    if (lt(double(sq[i][j-1]) , avg) ) { sq[i][j-1] = 0;}
                    if (lt(double(sq[i][j+1]) , avg) ) { sq[i][j+1] = 0;}
                    change = true;
                    // cout << "inc " << inc << endl;
                    // cout << "sum " << sum << endl;
                    for (int i = 1; i <= R; i++) {
                        for (int j = 1; j <= C; j++) {
                            cur_sum += sq[i][j];
                            // cout << "> " << sq[i][j] << " ";
                        }
                        // cout << endl;
                    }
                    // cout << "csum " << cur_sum << endl;
                    // cout << "lsum " << last_sum << endl;
                    if (last_sum == cur_sum) {
                        goto output;
                    }
                    sum += cur_sum;
                    last_sum = cur_sum;
                }
            }
            if (!change)
                break;
            // sum += inc;
            // sum -= cut;
            // cout << "tmp " << sum << endl;
        }
        output:
        cout << "Case #" << t << ": " << sum << endl;
    }
}
