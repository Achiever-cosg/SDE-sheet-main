/*
Find the duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/description/
*/

// Approach-I: sorting  O(nlogN)

// Approach - II : USing Frequency Array/ Unordered Map
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x: nums)
        {
            mpp[x]++;
        }

        for(auto it: mpp)
        {
            if(it.second == 2)
                return it.first;
        }

        return -1;
    }
};

/*
    T(n): O(n)
    S(n): O(n)
*/


/*   Optimized Approach: Linked-list Cycle method   */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = nums[0], fast = nums[0];

       do 
       {
           slow = nums[slow];
           fast = nums[nums[fast]];
       } while(slow != fast);
    
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// T(n) : O(N)

