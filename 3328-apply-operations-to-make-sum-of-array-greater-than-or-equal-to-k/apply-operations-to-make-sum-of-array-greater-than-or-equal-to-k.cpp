class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            int temp = ceil(k*1.0/i);
            ans = min(ans,i-1+temp-1);
        }
        return ans;
    }
};