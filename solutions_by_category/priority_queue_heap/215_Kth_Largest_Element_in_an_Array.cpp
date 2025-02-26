/*
215. Kth Largest Element in an Array
http://leetcode.com/problems/kth-largest-element-in-an-array
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap; // Max heap by default
        for (int& num : nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        return -heap.top();
    }
};
    
/*
This probably is the most fundamental priority queue problem
*/