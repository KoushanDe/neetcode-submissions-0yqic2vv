class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastind = -1;
        int len = 0;
        unordered_map<char,int> pos;

        for(int i=0;i<s.size();i++){
            if(pos.find(s[i])==pos.end()|| pos[s[i]]<lastind){
                len = max(len,i-lastind);
            }
            else{
                lastind = pos[s[i]];
            }

            pos[s[i]] = i;
        }

        return len;
    }
};
