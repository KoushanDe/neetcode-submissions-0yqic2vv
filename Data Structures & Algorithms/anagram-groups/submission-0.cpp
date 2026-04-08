class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> groupMap;
        vector<vector<string>> ans;

        for(int i=0; i<strs.size();i++){
            map<char,int> freq;
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]]++;
            }

            groupMap[freq].push_back(strs[i]);
        }

        for(auto x: groupMap){
            ans.push_back(x.second);
        }

        return ans;
    }
};
