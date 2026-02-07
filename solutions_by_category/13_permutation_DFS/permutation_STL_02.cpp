/*
Let's see how to use the next_permutation() in C++ by a conrete example of string
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str = "abc";

    cout << "All permutations of \"" << str << "\":\n";
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    return 0;
}
/*
All permutations of "abc":
abc
acb
bac
bca
cab
cba
*/