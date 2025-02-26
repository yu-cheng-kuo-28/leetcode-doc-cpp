/*
Let's see how to use the next_permutation() in C++ by a conrete example of int array
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "All permutations:\n";
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}

/*
All permutations:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/