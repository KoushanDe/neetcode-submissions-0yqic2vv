class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        vector<pair<int,int>> temp;
        for(auto x:freq){
            temp.push_back({x.second,x.first});
        }

        sort(temp.begin(),temp.end(),greater<pair<int,int>>());

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};
