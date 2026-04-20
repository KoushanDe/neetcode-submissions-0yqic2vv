class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else if(!st.empty()){
                char test = st.top();
                if((test=='('&&s[i]!=')')||(test=='{'&&s[i]!='}')||(test=='['&&s[i]!=']'))
                    return false;
                st.pop();
            }
            else
            return false;
        }

        return st.empty();
    }
};
