class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto s : strs){
            string str = s;
            sort(str.begin(), str.end());
            mp[str].push_back(s);
        }
        for(auto it : mp)   ans.push_back(it.second);   
        return ans;
    }
};