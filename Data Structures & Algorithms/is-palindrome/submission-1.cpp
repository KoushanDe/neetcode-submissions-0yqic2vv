class Solution {
public:
    bool isPalindrome(string s) {
        string restructured = "";

        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                restructured+=tolower(s[i]);
            }
            else if(s[i]>='0'&&s[i]<='9'){
                restructured+=s[i];
            }
        }

        int n = restructured.size();

        for(int i=0;i<n/2;i++){
            if(restructured[i]!=restructured[n-i-1])
            return false;
        }

        return true;
    }
};
