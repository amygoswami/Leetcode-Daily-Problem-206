class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> indexes;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == maxEle)
                indexes.push_back(i);   //stores all occurences of maxEle using their index
                int freq = indexes.size();
                if(freq >= k)
                    ans += indexes[freq - k] + 1;
        }

        return ans;
    }
};