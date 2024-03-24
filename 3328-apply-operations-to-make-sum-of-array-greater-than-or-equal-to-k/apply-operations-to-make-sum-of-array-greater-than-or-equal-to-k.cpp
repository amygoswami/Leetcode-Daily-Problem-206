class Solution {
public:
    int f(int sum, int maxi, int k, vector<int>& dp){
        //base case
        if(sum >= k)    return 0;
        if(dp[maxi] != -1)  return dp[maxi];
        int notTake = 1 + f(sum + 1, maxi+1, k, dp);
        int take = 1 + f(sum + maxi, maxi, k, dp);
        return dp[maxi] = min(notTake, take);
    }

    int minOperations(int k) {
        vector<int> dp(k+1, -1);
        return f(1, 1, k, dp);
    }
};