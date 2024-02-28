/*
    Merge Overlapping Sub-intervals
    https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)
            return {};

        sort(intervals.begin(), intervals.end());
        int currBegin = intervals[0][0];
        int currEnd = intervals[0][1];
        vector<vector<int>> ans;

        for(int i=1; i<n; i++)
        {
            auto it = intervals[i];
            if(it[0] <= currEnd)
                currEnd = max(currEnd, it[1]);
            else
            {
                ans.push_back({currBegin, currEnd});
                currBegin = it[0];
                currEnd = it[1];
            }
        }

        ans.push_back({currBegin, currEnd});

        return ans;
    }
};

/*
    T(n) : O(nlogN) => sorting
*/