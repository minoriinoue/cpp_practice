// Get a string and returns a reversed string.

#include <iostream>

using namespace std;

string reverseChar(string str);

int main() {
    cout << "finc is reversed as 'cnif':" << reverseChar("finc") << endl;
    cout << "apple is reversed as 'elppa':" << reverseChar("apple") << endl;
}

string reverseChar(string str) {
    if (str.length() == 1) return str;

    int front_index = 0;
    int rear_index = str.length() - 1;
    do {
        char tmp = str[front_index];
        str[front_index] = str[rear_index];
        str[rear_index] = tmp;

        front_index++;
        rear_index--;
    } while (front_index <= rear_index);
    return str;
}
