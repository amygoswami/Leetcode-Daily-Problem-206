class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        set<int> set;
        for(int i=0; i<nums.size(); i++){
            if(set.count(nums[i]))
                ans.push_back(nums[i]);
            set.insert(nums[i]);
        }
        return ans;
    }
};