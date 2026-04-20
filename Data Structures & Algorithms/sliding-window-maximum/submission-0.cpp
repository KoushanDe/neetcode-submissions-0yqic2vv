class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,greater<int>> freq;
        vector<int> ans;

        int l=0,r=0;

        while(r<nums.size()){
            freq[nums[r]]++;
            if(r-l+1==k){
                ans.push_back((*freq.begin()).first);
                freq[nums[l]]--;
                if(freq[nums[l]]==0)
                    freq.erase(nums[l]);
                l++;
            }
            r++;
        }

        return ans;

    }
};
