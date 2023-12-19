<p><strong>Problem: [525. Contiguous Array](https://leetcode.com/problems/contiguous-array/)<br>
<strong>Category:</strong> Array<br>
<strong>Difficulty:</strong> Medium<br>
<strong>Language:</strong> C++</p>

TC / SC = O(n) / O(n)

<br>

<h3>(1) Thought Process</h3>
<h4>1–1 General Cases</h4>
<p>Input: nums = [1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1] / Output: 6<br>
Note: Returned 0 for the case "Input: nums = [0, 1] / Output: 2"</p>

```cpp
// For general cases
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // Hash table
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1); // Convert 0 to -1
            if (!mp.count(sum)) {
                mp[sum] = i; // Record the first apperance of that sum
                continue;
            }
            ans = max(ans, i - mp[sum]); // Find the max distance to the first one
        }
        return ans;
    }
};
```

<h4>1–2 Edge Cases</h4>
<p>Input: nums = [0, 1] / Output: 2<br>
Input: nums = [0, 1, 0, 1, 0, 1] / Output: 6</p>

```cpp
// For general cases & edge cases
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1; // The different line

        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (!mp.count(sum)) {
                mp[sum] = i;
                continue;
            }
            ans = max(ans, i - mp[sum]);
        }
        return ans;
    }
```

- TC / SC = O(n) / O(n)
