class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k){
        //remove subarrays storing distinct elements < k & store only those w distinct elements = k 
        return slidingWindowAtmost(nums, k) - slidingWindowAtmost(nums, k-1);   
    }

    int slidingWindowAtmost(vector<int>& nums, int K) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int i = 0, j = 0;

        while(j < nums.size()){
            mp[nums[j]]++;

            while(mp.size() > K){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            
            cnt += j-i+1;   //represents no of subarrays betn i and j
            j++;
        }
        return cnt;
    }
};