class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3)
            return 0;

        int l = 0;
        int r = n-1;

        int leftmax = height[0];
        int rightmax = height[n-1];
        int area = 0;

        while(l<r){
            if(leftmax<rightmax){
                l++;
                area+=max(0,leftmax - height[l]);
                leftmax = max(leftmax,height[l]);
            }
            else{
                r--;
                area+=max(0,rightmax-height[r]);
                rightmax = max(rightmax,height[r]);
            }
        }

        return area;
    }
};
