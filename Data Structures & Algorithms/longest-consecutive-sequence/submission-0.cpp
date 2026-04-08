class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;

        unordered_set<int> inputSet;

        for(int i=0;i<nums.size();i++){
            inputSet.insert(nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            int len = 1;
            while(true){
                if(inputSet.find(temp-1)==inputSet.end())
                    break;

                len++;
                temp--;
            }
            if(len>maxlen)
                maxlen=len;
        }

        return maxlen;
    }
};
