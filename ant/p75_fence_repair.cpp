#include <queue>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int rec(int, priority_queue<int, vector<int>, greater<int>>);
vector<int> argument_to_int_array(int, char *argv);

int main(int argc, char **argv) {
    if (argc < 3) {
        cout << "Arguments not valid. Please provide at least 3 "
            << "arguments. FILE_NAME N L" << endl;
        return 1;
    }
    int n = stoi(argv[1]);
    if (n != argc - 2) {
        cout << "Arguments not valid. N stands for the number "
            << "of Ls provided." << endl;
        return 1;
    }
    vector<int> input_l = argument_to_int_array(n, argv[2]);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int element : input_l) pq.push(element);
    cout << rec(n, pq) << endl;
}

vector<int> argument_to_int_array(int n, char *argv) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        // cout << i << endl;
        char *a = argv;
        // cout << a << endl;
        argv = argv + 2;
        v.push_back(stoi(a));
        //v.push_back(stoi(*((&argv)[i])));
        //argvはarrayのarrayの最初の配列のpointerでもあり、配列の
        //配列のpointerでもある。(配列の配列だけではなく、配列のpointer
        //でもある）ので、&argvはコマンド引数の配列のpointerを指している
        //ことになり、変。
        //しかしながら、次の配列(配列の配列ではなく)を得ようと思って、argv++
        //にしてしまうと、配列の配列のincrementと間違えてしまい、5 8 5と引数
        //を与えた場合、5の次にspaceが得られてしまう。２次元配列から
        //一旦配列を得てしまうと、元の2次元配列で次の配列の配列が得られる
        //ようなことができなくなってしまう。
    }
    return v;
}   

int rec(int n, priority_queue<int, vector<int>, greater<int>> pq) {
    if (n == 1) return 0;
    int first_min_element = pq.top();
    pq.pop();
    int second_min_element = pq.top();
    pq.pop();
    int new_element =  first_min_element + second_min_element;
    pq.push(new_element);
    return new_element + rec(n-1, pq);
}

