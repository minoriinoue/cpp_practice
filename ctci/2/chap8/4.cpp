// Write a method to return all subsets of a set.
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> rec(const vector<int>& s, int, unordered_map<int, vector<vector<int>>>*);
void print_vv(const vector<vector<int>>& vs) {
    for (auto v: vs) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> rec(const vector<int>& s, int index, unordered_map<int, vector<vector<int>>>* m) {
    if (index == s.size() - 1) { // Last index
        vector<int> v1 = {s[index]};
        vector<int> v2; // Empty vector
        vector<vector<int>> v = {v1, v2};
        return v;
    } else if (m->find(index) != m->end()) {
        return (*m)[index];
    } else {
        vector<vector<int>> n_1s = rec(s, index+1, m);
        int original_size = n_1s.size();
        for (int i = 0; i < original_size; i++) {
            vector<int> new_v(n_1s[i]);
            new_v.push_back(s[index]);
            n_1s.push_back(new_v);
        }
        (*m)[index] = n_1s;
        return (*m)[index];
    }
}

int main(void) {
    vector<int> set = {1, 2, 3};
    unordered_map<int, vector<vector<int>>> memo;
    vector<vector<int>> result = rec(set, 0, &memo);
    // print result
    print_vv(result);
}
