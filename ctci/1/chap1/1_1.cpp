#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
bool isUniqueChar(string str);
string boolToString(bool boolean);

int main() {
    cout << boolToString(isUniqueChar("finc")) << endl;
    cout << boolToString(isUniqueChar("apple"));
}

bool isUniqueChar(string str) {
    if (str.length() > 256) return false;

    bool array[256];
    for (int i = 0; i < str.length(); i++) {
        if (array[str[i]] == false) {
            array[str[i]] = true;
        } else {
            return false;
        }
    }
    return true;
}

string boolToString(bool boolean) {
    return boolean? "true" : "false";
}
