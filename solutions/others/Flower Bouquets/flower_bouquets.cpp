#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

int flowerBouquets(int p, int q, const string& s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        // Always take the previous state's profit
        dp[i] = dp[i - 1];

        // Check for a bouquet of three roses
        if (i >= 3 && s.substr(i - 3, 3) == "000") {
            dp[i] = max(dp[i], dp[i - 3] + p);
        }

        // Check for a mixed bouquet of a rose and a cosmos
        if (i >= 2 && (s.substr(i - 2, 2) == "01" || s.substr(i - 2, 2) == "10")) {
            dp[i] = max(dp[i], dp[i - 2] + q);
        }
    }

    // The last state will have the maximum profit
    return dp[n];
}

void testCases() {
    // Empty Garden
    assert(flowerBouquets(2, 3, "") == 0);

    // All Roses
    assert(flowerBouquets(2, 3, "000000") == 4); // Should form two type 1 bouquets

    // All Cosmos
    assert(flowerBouquets(2, 3, "111111") == 0); // Can't form any bouquet

    // Single Bouquet Type 1
    assert(flowerBouquets(10, 3, "000") == 10);

    // Single Bouquet Type 2
    assert(flowerBouquets(2, 20, "01") == 20);

    // Multiple Bouquets
    assert(flowerBouquets(5, 6, "000111000") == 12); // Two type 1 and one type 2

    // Alternating Flowers
    assert(flowerBouquets(4, 5, "0101010101") == 25); // Five type 2 bouquets

    // Large Garden
    assert(flowerBouquets(3, 8, "000100010001000100010001") == 57); // Four type 2 bouquets

    // No Profitable Bouquets
    assert(flowerBouquets(10, 20, "111") == 0); // No bouquets can be formed

    cout << "All test cases passed!" << endl;
}

int main() {
    testCases();
    return 0;
}
