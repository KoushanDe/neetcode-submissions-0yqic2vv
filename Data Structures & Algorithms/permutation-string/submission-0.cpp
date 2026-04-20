class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        unordered_map<char,int> s1freq,s2freq;

        for(int i=0;i<s1.size();i++){
            s1freq[s1[i]]++;
        }

        for(int i=0;i<s1.size();i++){
            s2freq[s2[i]]++;
        }

        int l=0,r=s1.size()-1;
        bool ans;
        while(r<s2.size()){
            ans = true;
            for(auto x:s1freq){
                if(s2freq[x.first]!=x.second){
                    ans=false;
                    break;
                }
            }

            if(ans == true) return true;

            s2freq[s2[l]]--;
            l++;
            r++;
            s2freq[s2[r]]++;
        }

        return false;
    }
};
