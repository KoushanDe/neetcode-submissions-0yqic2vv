class MinStack {
public:
    stack<pair<int,int>> st;
    int minm;
    MinStack() {
        minm = INT_MAX;
    }
    
    void push(int val) {
        if(val<minm)
            minm=val;
        
        st.push({val,minm});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())minm = st.top().second;
        else minm=INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
