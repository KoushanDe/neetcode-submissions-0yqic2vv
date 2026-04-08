class Solution {
public:

    string encode(vector<string>& strs) {
        string finalString;

        for(int i=0;i<strs.size();i++){
            finalString+=strs[i];
            finalString+='`';
        }

        return finalString;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='`'){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp+=s[i];
            }
        }

        return ans;
    }
};
