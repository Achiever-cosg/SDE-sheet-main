/*
 Using Merge Sort Algorithm to figure out the number of such pairs
 If a number of in a left sorted array can make a pair with that in a right sorted array, 
 then all the elements right of the element of left array will also make a pair with that 
 particular element in the right array beacuse the left array is already sorted.
*/ 

#include <bits/stdc++.h> 
using namespace std;
void merge(int start, int mid, int end, long long *nums, long long& cnt)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
        {
            temp.push_back(nums[j++]);
            cnt += (mid-i+1);          // only modification in Merge Sort algo
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
            temp.push_back(nums[i++]);
    }

    if (j <= end)
    {
        while (j <= end)
            temp.push_back(nums[j++]);
    }

    for (int k = start; k <= end; k++)
    {
        nums[k] = temp[k - start];
    }
}

void mergeSort(int start, int end, long long *nums, long long& cnt)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(start, mid, nums, cnt);
    mergeSort(mid + 1, end, nums, cnt);

    merge(start, mid, end, nums, cnt);
}

long long getInversions(long long *arr, int n){
    long long cnt = 0;
    mergeSort(0, n-1, arr, cnt);
    return cnt;
}

