class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> distinctCnt(nums.size()+1, 0);
        int totalCnt = 0;
        int i = 0, j = 0, currCnt = 0;

        while(j < nums.size()){
            if(++distinctCnt[nums[j++]] == 1){
                k--;    //decrement k when a new element is encountered
            }
            if(k < 0){
                --distinctCnt[nums[i++]];
                k++;
                currCnt = 0;
            }
            //if k becomes 0, cnt no of subarrays
            if(k == 0){
                while(distinctCnt[nums[i]] > 1){
                    --distinctCnt[nums[i++]];
                    currCnt++;
                }
                totalCnt += currCnt + 1;
            }
        }
        return totalCnt;
    }
};