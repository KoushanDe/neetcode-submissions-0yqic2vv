class Solution {
public:
    bool canEat(vector<int>& piles, int h, int rate){
        int totalHours = 0;

        for(int i=0;i<piles.size();i++){
            totalHours += (piles[i]/rate);
            if(piles[i]%rate)
            totalHours+=1;
        }

        return totalHours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high;
        high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;

        while(low<=high){
            int mid = (low+high)/2;

            if(canEat(piles,h,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};
