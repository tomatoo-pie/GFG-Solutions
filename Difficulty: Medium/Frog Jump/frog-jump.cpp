class Solution {
  public:
    int minEnergy(vector<int>& heights, int n, int id, vector<int>& dp) {

        // Reached last stair
        if (id == n - 1)
            return 0;
    
        // Already calculated
        if (dp[id] != -1)
            return dp[id];
    
        int onestep = INT_MAX;
        int twostep = INT_MAX;
    
        // Jump 1 step
        if (id + 1 < n) {
            onestep = abs(heights[id] - heights[id + 1])
                      + minEnergy(heights, n, id + 1, dp);
        }
    
        // Jump 2 steps
        if (id + 2 < n) {
            twostep = abs(heights[id] - heights[id + 2])
                      + minEnergy(heights, n, id + 2, dp);
        }
    
        return dp[id] = min(onestep, twostep);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);

        return minEnergy(height, n, 0, dp);
    }
};