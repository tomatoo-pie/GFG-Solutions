class Solution {
public:
    int minCost(vector<int>& height) {

        int n = height.size();

        int dp2 = 0; // dp[i-2]
        int dp1 = 0; // dp[i-1]

        for (int i = 1; i < n; i++) {

            // Jump from i-1 to i
            int oneStep = dp1 + abs(height[i] - height[i - 1]);

            // Jump from i-2 to i
            int twoStep = INT_MAX;

            if (i > 1) {
                twoStep = dp2 + abs(height[i] - height[i - 2]);
            }

            int dp = min(oneStep, twoStep);

            // Shift
            dp2 = dp1;
            dp1 = dp;
        }

        return dp1;
    }
};