#include <iostream>
using namespace std;

int main()
{
    int t, b;
    char ok;
    cin >> t >> b;
    for (int tt = 1; tt < t+1; tt++) {
        char arr[b+1] = {0};
        bool fir[3] = {true, true, true};
        for (int i = 1; i <= 5; i++) {
            cout << i << endl;
            cin >> arr[i-1];
            cout << b-i+1 << endl;
            cin >> arr[b-i];
        }
        if (b == 10) {
            goto output;
        }

output:
        cout << string(arr) << endl;
        cin >> ok;
        if (ok == 'N') {
            exit(0);
        }
    }
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
// int flipbit(int x) {
//     return 1 - x;
//     // if (x == 0) {
//     //     return 1;
//     // } else {
//     //     return 0;
//     // }
// }
//
// void print_v(vector<int>& a) {
//     for (int i = 0; i < a.size(); i++) {
//         cerr << a[i];
//     }
//     cerr << endl;
// }
//
// bool check_and_change(vector<int>& a, vector<int>& b, int len) {
//     // print_v(a);
//     // cerr << a[0] << a[1] << a[2] << endl;
//     // cerr << a[len-1] << a[len-2] << a[len-3] << endl;
//     // cerr << b[0] << b[1] << b[2] << endl;
//     if (a[1] == b[1] && a[2] == b[2] && a[0] == b[0]) {
//         cerr << "N\n";
//         return false;
//     }
//     if (a[1] != b[1] && a[2] != b[2] && a[0] != b[0]) { // complemented
//         cerr << "C\n";
//         print_v(a);
//         transform(a.begin(), a.end(), a.begin(), flipbit);
//         print_v(a);
//         return false;
//     }
//     if (a[len-1] == b[0] && a[len-2] == b[1] && a[len-3] == b[2]) { // reversed
//         cerr << "R\n";
//         print_v(a);
//         reverse(std::begin(a), std::end(a));
//         print_v(a);
//         return true;
//     } else {
//         cerr << "B\n";
//         print_v(a);
//         reverse(std::begin(a), std::end(a));
//         transform(a.begin(), a.end(), a.begin(), flipbit);
//         print_v(a);
//         return true;
//     }
// }
//
// int main()
// {
//     int t, b;
//     char ok;
//     cin >> t >> b;
//     int qu = 1;
//     for (int tt = 1; tt < t+1; tt++) {
//         vector<int> arr(b);
//         // bool tmp;
//         fill(arr.begin(), arr.end(), 0);
//         for (int i = 0; i < 5; i++) {
//             cout << i+1 << endl;
//             cerr << "q" << qu++ << endl;
//             cerr << i << endl;
//             cin >> arr[i];
//             cout << b-i << endl;
//             // cerr << "q" << qu++ << endl;
//             cerr << b-i-1 << endl;
//             cin >> arr[b-i-1];
//         }
//         int remain_idx[2] = {6, b-5};
//         bool order = false;
//         while(true) {
//             // char for_check[3] = {0};
//             vector<int> for_check(3);
//             for (int i = 0; i < 3; i++) {
//                 cout << i+1 << endl;
//                 // cerr << "q" << qu++ << endl;
//                 cin >> for_check[i];
//             }
//             print_v(arr);
//             print_v(for_check);
//             bool is_r = check_and_change(arr, for_check, b);
//             // order = is_r ? !order : order;
//             // cerr << for_check << endl;
//             if (is_r) {
//                 // reverse(std::begin(arr), std::end(arr));
//                 for (int i = 0; i < 7; i++) {
//                     if (remain_idx[1]-i < remain_idx[0]) {
//                         goto output;
//                     }
//                     cout << b-(remain_idx[1]-i) << endl;
//                     // cerr << "q" << qu++ << endl;
//                     cerr << b-(remain_idx[1]-i-1) << endl;
//                     cin >> arr[b-(remain_idx[1]-i)-1];
//                 }
//                 remain_idx[1] -= 7;
//             } else {
//                 for (int i = 0; i < 7; i++) {
//                     if (remain_idx[0]+i > remain_idx[1]) {
//                         goto output;
//                     }
//                     cout << remain_idx[0]+i << endl;
//                     // cerr << "q" << qu++ << endl;
//                     cerr << remain_idx[0]+i-1 << endl;
//                     cin >> arr[remain_idx[0]+i-1];
//                 }
//                 remain_idx[0] += 7;
//             }
//         }
//         output:
//         string ou = "";
//         for (int i = 0; i < b; i++) {
//             ou.push_back(arr[i]==0 ? '0' : '1');
//         }
//         cout << ou << endl;
//         cin >> ok;
//         if (ok == 'N') {
//             exit(0);
//         }
//     }
//     return 0;
// }
