// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isPermutation(string str1, string str2);
string boolToString(bool boolean);

int main () {
    cout << "abc and bca are permuation?: " << boolToString(isPermutation("abc", "bca")) << endl;
    cout << "cc and bb are permuation?: " << boolToString(isPermutation("cc", "bb")) << endl;
}

// solution1: use hash and check if the two strings have
// same keys.
//
// solution2: use an array index by char number and compare the array.
//
// both are O(n)
//
// solution 1 is better because of the memory size.

bool isPermutation(string str1, string str2) {
    if (str1.length() != str2.length()) return false;

    unordered_map<char, int> char_counter_map;
    for (int i = 0; i < str1.length(); i++) {
        char_counter_map[str1[i]]++;
        char_counter_map[str2[i]]--;
    }

    for (auto kv : char_counter_map) {
        if (kv.second != 0) return false;
    }
    return true;
}

string boolToString(bool boolean) {
    if (boolean) return "true";
    else return "false";
}
