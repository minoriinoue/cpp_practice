#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Count up letters in 2 strings separately.
// If all the counter elements are same, the string
// is a permutation of the other.
//

bool if_permutation(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    unordered_map<char, int> counter_1;
    unordered_map<char, int> counter_2;

    for (int i = 0; i < str1.size(); i++) {
        counter_1[str1[i]] += 1;
        counter_2[str2[i]] += 1;
    }

    for (auto iter1 = counter_1.begin(); iter1 != counter_1.end(); iter1++) {
        char key = iter1->first;
        if (iter1->second != counter_2[key]) return false;
    }
    return true;
}

string bool_to_string(bool b) {
    if (b) return "true";
    else return "false";
}

int main(void) {
    cout << "apple and aelpp: " << bool_to_string(if_permutation("apple", "aelpp")) << endl;
    cout << "apple and aeple: " << bool_to_string(if_permutation("apple", "aeple")) << endl;
    return 0;
}
