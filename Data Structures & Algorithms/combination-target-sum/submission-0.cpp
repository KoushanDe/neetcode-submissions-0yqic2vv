class Solution {
public:
    void allComb(vector<vector<int>>& ans, vector<int>& nums, int i, vector<int>& temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()){
            return;
        }

        if(nums[i]<=target){
            temp.push_back(nums[i]);
            allComb(ans,nums,i,temp,target-nums[i]);
            temp.pop_back();
        }
        allComb(ans,nums,i+1,temp,target);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        allComb(ans,nums,0,temp,target);

        return ans;
    }
};
