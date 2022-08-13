class Solution {
public:
    pair<int, int> lower_bound(int l, int r, vector<pair<int, int>>& vals, int target) {
        while (l < r) {
            int md = (l+r)/2;
            if (vals[md].first < target)
                l = md+1;
            else
                r = md-1;
        }
        return vals[l];
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vals;
        for (int i = 0; i < nums.size(); i++)
            vals.push_back({nums[i], i});
        sort(vals.begin(), vals.end());
        for (pair<int, int> now : vals) {
            int val = now.first;
            int pos = now.second;
            
            pair<int, int> query = lower_bound(0, nums.size()-1, vals, target - val);
            if (query.second != pos && query.first + val == target)
                return vector<int>{pos, query.second};
        }
    
        return vector<int>{0, 0};
    }
};