// nth stair = 1 hop from (n-1)th stair
//             or 2 hops from (n-2)th stair
//             or 3 hops from (n-3)th stair

#include <unordered_map>
#include <iostream>
using namespace std;

int rec(int, unordered_map<int, int>*);

int rec(int n, unordered_map<int, int>* memo) {
    if (n == 0) return 1; // Completed
    else if (n < 0) return 0; // Couldn't
    else if (memo->find(n) != memo->end()) return (*memo)[n];
    else {
        (*memo)[n] = rec(n-1, memo) + rec(n-2, memo) + rec(n-3, memo);
        return (*memo)[n];
    }
}

int main(void) {
    unordered_map<int, int> m;
    cout << "n, 3: " << rec(3, &m) << endl;
    cout << "n, 9: " << rec(9, &m) << endl;
}
