class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            if(!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if(st.top() < -asteroids[i]) {
                    st.pop();
                    // current asteroid is still alive
                    // so it can collide again
                    i--;
                }
                else if(st.top() == -asteroids[i]) {
                    st.pop();
                    // both destroyed
                }
                

            }
            else {
                st.push(asteroids[i]);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};