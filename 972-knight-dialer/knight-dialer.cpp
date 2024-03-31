class Solution {
public:   int mod = 1e9 + 7;  
    vector<vector<int>> jumps = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
    };

    int dfs(int remain, int i, vector<vector<int>> &dp){
        if(remain == 0)
            return 1;
        
        if(dp[remain][i] != 0)  
            return dp[remain][i];
        
        int ans = 0;
        //explore neighbors
        for(int j : jumps[i])
            ans = (ans + dfs(remain-1, j, dp)) % mod;
        
        dp[remain][i] = ans;
        return ans;
    }

    int knightDialer(int n) {
        vector<vector<int>> dp(n+1, vector<int> (10, 0));
        int ans = 0;
        for(int i=0; i<10; i++)
            ans = (ans + dfs(n-1, i, dp)) % mod;
        return ans;
    }
};