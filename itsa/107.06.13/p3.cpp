#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string o[4];
    o[0] = "Hi";
    o[1] = "Hello";
    o[2] = "How do you do";
    o[3] = "How are you";

    string input;
    int count = 0;

    while (getline(cin, input)) {
        if (input == o[0] || input == o[1] || input == o[2] || input == o[3]) {
            cout << o[count] << endl;
            count++;
            if (count == 4) count = 0;
        } else {
            cout << "Sorry" << endl;
            count = 0;
        }
    }

    return 0;
}