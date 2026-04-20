class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freqs,freqt;

        for(int i=0;i<t.size();i++){
            freqt[t[i]]++;
        }

        int minlen = INT_MAX;
        int minl=0,minr=-1;
        int l=0,r=1;
        freqs[s[0]]++;
        while(r<=s.size()){
            bool isEligible = true;
            for(auto x:freqt){
                if(freqs[x.first]<x.second){
                    isEligible = false;
                    break;
                }
            }

            if(isEligible){
                if(r-l<minlen){
                    minlen = r-l;
                    minl = l;
                    minr = r;
                }
                freqs[s[l]]--;
                l++;
            }
            else{
                if(r<s.size()) freqs[s[r]]++;
                r++;
            }
        }

        string ans = "";

        for(int i=minl;i<minr;i++){
            ans = ans + s[i];
        }

        return ans;
    }
};
