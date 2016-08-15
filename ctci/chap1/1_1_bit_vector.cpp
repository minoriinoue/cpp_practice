#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
bool isUniqueChars(string str);
string boolToString(bool boolean);

int main () {
    cout << boolToString(isUniqueChars("finc")) << endl;
    cout << boolToString(isUniqueChars("apple")) << endl;
}

bool isUniqueChars(string str) {
    if (str.length() > 256) return false;
    
    int checker = 0;
    for (int i = 0; i < str.length(); i++) {
        int val = tolower(str[i]) - 'a';
        if ((checker & (1 << val)) > 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

string boolToString(bool boolean) {
    if (boolean) return "True";
    else return "False";
}
