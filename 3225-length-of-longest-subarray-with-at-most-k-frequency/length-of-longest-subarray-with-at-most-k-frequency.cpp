class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int i = -1, j = 0;
        while(j < nums.size()){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                i++;
                mp[nums[i]]--;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};