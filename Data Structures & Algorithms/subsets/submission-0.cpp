class Solution {
public:
    void allSubsets(vector<vector<int>>& ans, vector<int>& nums, int index, vector<int>& temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        allSubsets(ans,nums,index+1,temp);
        temp.pop_back();
        allSubsets(ans,nums,index+1,temp);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        allSubsets(ans,nums,0,temp);

        return ans;
    }
};
