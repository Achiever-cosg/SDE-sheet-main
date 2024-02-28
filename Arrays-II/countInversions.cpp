// https://www.codingninjas.com/studio/problems/count-inversions_615?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

long long getInversions(long long *arr, int n){

    // Write your code here.

    set<long long> st;

     long long ans = 0;

    for(int i=n-1;i>=0;i--){

          if(!st.empty()){

            ans+=distance(st.begin(),st.lower_bound(arr[i]));

          }

          st.insert(arr[i]);

    }

    return ans;

}

/*
    ans += distance(st.begin(), st.lower_bound(arr[i]));
    This line calculates the number of elements greater than arr[i] that are already present in the set st 
    using the lower_bound function. 
    The distance function calculates the distance between the iterators returned by st.begin() and st.lower_bound(arr[i]), 
    which gives the count of such elements. 
    This count is then added to ans.

    Time Complexity: 
    The lower_bound function in a set takes O(logN) time. So, 
    the overall time complexity is O(nLogN).
*/