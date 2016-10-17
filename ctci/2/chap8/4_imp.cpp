// Write a method to return all subsets of a set.
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void rec(const vector<int>& s,
                          int,
         vector<vector<int>>*,
        unordered_map<int, vector<vector<int>>>*);

void print_vv(const vector<vector<int>>& vs) {
    for (auto v: vs) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}
void rec(const vector<int>& s, int index, vector<vector<int>>* result, unordered_map<int, vector<vector<int>>>* m) {
    if (index == s.size() - 1) { // Last index
        vector<int> v1 = {s[index]};
        vector<int> v2; // Empty vector
        result->push_back(v1);
        result->push_back(v2);
    } else {
        rec(s, index+1, result, m);
        int original_size = result->size();
        for (int i = 0; i < original_size; i++) {
            vector<int> new_v((*result)[i]);
            new_v.push_back(s[index]);
            result->push_back(new_v);
        }
    }
}

int main(void) {
    vector<int> set = {1, 2, 3};
    vector<vector<int>> result;
    unordered_map<int, vector<vector<int>>> memo;
    rec(set, 0, &result, &memo);
    // print result
    print_vv(result);
}
