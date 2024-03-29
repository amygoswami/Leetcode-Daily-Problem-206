class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        //find largest element
        int num = *max_element(nums.begin(), nums.end());
        int i = 0, j = 0;
        
        while(j < nums.size()){
            if(nums[j] == num)  
                k--;    //found an occurence of num
            
            while(!k){
                if(nums[i] == num)
                    k++;    //shift the ptr cuz we reached our goal
                i++;
            }
            ans += i;
            j++;
        }

        return ans;
    }
};