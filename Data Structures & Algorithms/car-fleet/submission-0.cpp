class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;

        for(int i=0;i<speed.size();i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end(),greater<pair<int,int>>());

        int numberOfFleet = 0;
        double latestTime = 0.0;
        for(int i=0;i<speed.size();i++){
            double curr = (double)(target - cars[i].first)/cars[i].second;
            if(curr>latestTime){
                latestTime = curr;
                numberOfFleet++;
            }
        }

        return numberOfFleet;
    }
};
