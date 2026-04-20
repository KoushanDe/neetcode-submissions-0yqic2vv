class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l=0,r=0;

        int maxlen = 0;
        int maxfreq = 0;
        freq[s[0]] = 1;
        while(r<s.size()){
            for(auto x:freq){
                maxfreq = max(maxfreq,x.second);
            }

            if(r-l+1-maxfreq<=k){
                maxlen = max(maxlen,r-l+1);
                r++;
                freq[s[r]]++;
            }
            else{
                freq[s[l]]--;
                l++;
            }
        }

        return maxlen;
    }
};
