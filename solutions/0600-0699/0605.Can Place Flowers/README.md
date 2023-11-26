Also on me Medium <a href="https://yc-kuo.medium.com/leetcode-605-can-place-flowers-easy-30c9b1460374">Leetcode : 605. Can Place Flowers (Easy)</a>

<p><strong>Problem:</strong> 605. Can Place Flowers<br>
<strong>Category:</strong> Array (refer to Grind75)<br>
<strong>Difficulty:</strong> Easy<br>
<strong>Language:</strong> C++</p>

<h4>(1) Thought Process</h4>
<h5>1–1 General Cases</h5>
<p>For 0’s in a row like […, 1, 0, 0, 0, 1, …], we have:</p>
<ul>
  <li>One 0 => No flower</li>
  <li>Two 0s => No flower</li>
  <li>Three 0s => 1 flower</li>
  <li>Four 0s => 1 flower</li>
  <li>Five 0s => 2 flowers</li>
  <li>...</li>
</ul>
<p>So after considering the general cases, the code looked like:</p>

```cpp
// For general cases
class Solution {
public:
    bool canPlaceFlowers(vector&lt;int&gt;& flowerbed, int n) {
        int cnt = 1, sum = 0; // start with 1 to account for the virtual zero at the start

        for (int i = 0; i &lt; flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++cnt; // increment count of zeros
            } else {
                if (cnt &gt; 2) sum += (cnt - 1) / 2; // add the number of flowers that can be planted
                cnt = 0; // reset count when a flower is found
            }
        }
        if (cnt &gt; 0) sum += cnt / 2; // handle the last sequence of zeros
        return n &lt;= sum;
    }
};
```

<h5>1–2 Edge Cases</h5>
<p>Now, let’s move on to cases like [0, 0, 1, …] & […, 1, 0, 0], we have:</p>
<ul>
  <li>One 0 => No flower</li>
  <li>Two 0s => 1 flower</li>
  <li>Three 0s => 1 flower</li>
  <li>Four 0s => 2 flowers</li>
  <li>Five 0s => 2 flowers</li>
</ul>
<p>Then, finally we have the solution below.</p>

```cpp
// For general cases & edge cases
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 1, sum = 0; // start with 1 to account for the virtual zero at the start
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++cnt; // increment count of zeros
            } else {
                if (cnt > 2) sum += (cnt - 1) / 2; // add the number of flowers that can be planted
                cnt = 0; // reset count when a flower is found
            }
        }
        if (cnt > 0) sum += cnt / 2; // handle the last sequence of zeros
        return n <= sum;
    }
};
```
- TC / SC = O(n) / O(1)
<br>

<h4>(2) Alternative Solutions</h4>
<p>Retrieved from <a href="https://github.com/doocs/leetcode/tree/main/solution/0600-0699/0605.Can%20Place%20Flowers">Doocs GitHub Repository</a></p>

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector&lt;int&gt;& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i &lt; m; ++i) {
            int l = i == 0 ? 0 : flowerbed[i - 1];
            int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n &lt;= 0;
    }
};
```

<p>I couldn’t figure it out at the first glance, just too complicated.</p>
