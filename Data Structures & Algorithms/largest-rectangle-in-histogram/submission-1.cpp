class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        heights.push_back(-1);

        for(int i=0;i<=n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                int curr = st.top();
                int ns = i;
                int ps;
                st.pop();
                if(st.empty())
                ps = -1;
                else
                ps = st.top();
                maxArea = max(maxArea, heights[curr]*(ns-ps-1));
            }
            st.push(i);
        }

        return maxArea;
    }
};
