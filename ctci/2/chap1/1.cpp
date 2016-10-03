#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

void fill_with_zeros(int str[], int counter) {
    for (int i = 0; i < counter; i++) {
        str[i] = 0;
    }
    return;
}

bool if_unique(string str) {
    int char_counter[27];
    fill_with_zeros(char_counter, 27);
    for (int i = 0; i < str.size() ; i++) {
        int index = tolower(str[i]) - 'a';
        char_counter[index] += 1;
        if (char_counter[index] >= 2) return false;
    }
    return true;
}

string bool_to_str(bool b) {
    if (b) return "true";
    else return "false";
}

int main(void) {
    cout << "apple, is unique?: " << bool_to_str(if_unique("apple")) << endl;
    cout << "jap, is unique?: " << bool_to_str(if_unique("jap")) << endl;
}
