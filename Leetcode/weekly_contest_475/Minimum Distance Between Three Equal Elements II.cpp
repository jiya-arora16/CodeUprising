class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &[key, val] : mp) {
            if (val.size() >= 3) {
                for (int i = 0; i< val.size()-2; i++) {
                    int temp = 2 * (val[i + 2] - val[i]);
                    ans = min(ans, temp);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
