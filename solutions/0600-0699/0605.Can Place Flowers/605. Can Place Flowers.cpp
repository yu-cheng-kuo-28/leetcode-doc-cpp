// For general cases & edge cases
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 1, sum = 0; // start with 1 to account for the virtual zero at the start

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++cnt; // increment count of zeros
            } else {
                if (cnt > 2) sum += (cnt - 1) >> 1; // add the number of flowers that can be planted
                cnt = 0; // reset count when a flower is found
            }
        }

        if (cnt > 0) sum += cnt >> 1; // handle the last sequence of zeros

        return n <= sum;
    }
};