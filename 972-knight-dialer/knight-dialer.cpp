class Solution {
public:   int mod = 1e9 + 7;  
    vector<vector<int>> jumps = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
    };

    int knightDialer(int n) {
        vector<vector<int>> dp(n+1, vector<int> (10, 0));
        //base case
        for(int i=0; i<10; i++)
            dp[0][i] = 1; 

        //write changing params ie remain and i
        for(int remain=1; remain<n; remain++){
            for(int i=0; i<10; i++){
                int ans = 0;
                //explore neighbors
                for(int j : jumps[i])
                    ans = (ans + dp[remain-1][j]) % mod;
                dp[remain][i] = ans;
            }
        }

        int ans = 0;
        for(int i=0; i<10; i++)
            ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};