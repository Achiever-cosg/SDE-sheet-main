/*
    Merge Sorted Array
    https://leetcode.com/problems/merge-sorted-array/description/
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(nums1[i] <= nums2[j])
                i++;
            else
            {
                for(int k=m-1; k>=i; k--)
                {
                    nums1[k+1] = nums1[k];
                }

                nums1[i] = nums2[j];
                m++;
                i++;
                j++;
            }
        }

        if(j < n)
        {
            while(j<n)
            {
                nums1[i] = nums2[j];
                i++;
                j++;
            }
        }
    }
};

/*
    T(n) : O(n*m)
*/