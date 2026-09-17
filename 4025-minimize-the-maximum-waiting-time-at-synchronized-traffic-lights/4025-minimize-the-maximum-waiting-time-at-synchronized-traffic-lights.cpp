class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        
        int light = *max_element(lights.begin(), lights.end());

        vector<int> maxval;

        for(int i = 0; i < arrivalTime.size(); i++) {
            int r = arrivalTime[i] % period;

            if(r >= light) {
                maxval.push_back(period - r);
            }
            else {
                maxval.push_back(0);
            }
        }

        int penalty = *max_element(maxval.begin(), maxval.end());

        return penalty;
    }
};