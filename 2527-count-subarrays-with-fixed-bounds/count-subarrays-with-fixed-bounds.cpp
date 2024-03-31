class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;
        
        for(int i=0; i<nums.size(); i++){
            //check if out of bound
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            if(nums[i] == minK)
                minPos = i;
            if(nums[i] == maxK)
                maxPos = i;

            int cnt = min(minPos, maxPos) - leftBound;
            ans += cnt <= 0 ? 0 : cnt;
        }
        return ans;
    }
};