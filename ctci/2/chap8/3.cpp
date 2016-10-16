// Find magic index
// i: 0  1  2  3  4
// v:    1  3
// When value is larger than the index, (i: 2 vs. v: 3)
// There is no need to explore bigger index since
// index can only increase by 1 and thus will never be able to catch up.
// --> Search smaller index.
// i: 0  1  2  3  4
// v:       1
// When value is smaller than the index, (i:2 vs v: 1)
// No need to search smaller index.
// --> Search bigger index.
#include <vector>
#include <iostream>
using namespace std;
int rec(vector<int>& v, int, int);
int rec(vector<int>& v, int f, int l) {
    if (f > l) return -1; // No magic index.
    int m = (f+l) / 2;
    if (v[m] == m) return m;
    else if (v[m] > m) return rec(v, f, m-1);
    else return rec(v, m+1, l);
}

int main(void) {
    vector<int> v = {-1, 1, 3, 4, 5};
    cout << rec(v, 0, v.size()-1) << endl;
    vector<int> v2 = {-1, 0, 1, 3, 5};
    cout << rec(v2, 0, v2.size()-1) << endl;
    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << rec(v3, 0, v3.size()-1) << endl;
}
