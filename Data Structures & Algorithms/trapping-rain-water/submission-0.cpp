class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3)
        return 0;

        vector<int> leftmax(n,0),rightmax(n,0);
        
        int left = 0;
        for(int i=1;i<n;i++){
            left = max(left,height[i-1]);
            leftmax[i]=left;
        }

        int right = 0;
        for(int i=n-2;i>=0;i--){
            right = max(right,height[i+1]);
            rightmax[i]=right;
        }

        int area = 0;

        for(int i=1;i<n-1;i++){
            if(min(leftmax[i],rightmax[i])>height[i]){
                area+=(min(leftmax[i],rightmax[i])-height[i]);
            }
        }

        return area;
    }
};
