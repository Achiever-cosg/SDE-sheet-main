// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

/*   Approach-I: Using set O(N), O(N)   */
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    unordered_set<int> st;
    vector<int> ans;
    
    for(int x: A)
    {
        if(st.find(x) != st.end())
        {
            ans.push_back(x);
        }
        st.insert(x);
    }
    
    for(int i=1; i<=A.size(); i++)
    {
        if(st.find(i) == st.end())
        {
            ans.push_back(i); 
            break;
        }      
    }
    
    return ans;
}


/*    Optimized Approach: Using maths O(N), O(1)   */

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    int n = A.size();

    long long sum = 0;

    long long squareSum = 0;

    long long expectedSum = (long long)n * (n + 1) / 2;

    long long expectedSquareSum = (long long)n * (n + 1) * (2 * n + 1) / 6;


    for (int num : A) {

        sum += num;

        squareSum += (long long)num * num;

    }


    long long diffSum = expectedSum - sum;

    long long diffSquareSum = expectedSquareSum - squareSum;


    long long sumDiff = diffSquareSum / diffSum;


    int missingNumber = (sumDiff + diffSum) / 2;

    int repeatedNumber = (sumDiff - missingNumber);


    return {repeatedNumber, missingNumber};

}