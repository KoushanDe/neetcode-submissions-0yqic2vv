class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = heights[0];
        int right = heights[n-1];

        int i=0,j=n-1;
        
        int ans = 0;

        while(i<j){
            int tempvol = min(left,right) * (j-i);

            if(tempvol>ans)
                ans = tempvol;

            if(left<=right){
                i++;
                left = heights[i];
            }
                
            else {
                j--;
                right = heights[j];
            }
        }

        return ans;
    }
};
