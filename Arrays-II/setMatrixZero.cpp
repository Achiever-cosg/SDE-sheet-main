/*
    Rotate Image by 90 degrees
    https://leetcode.com/problems/rotate-image/
*/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
   T(n): O(n^2)
*/

/* Rotate image by 180 dergrees */

/*
    reverse each row, and then swap each unswapped row with the last unswapped row
*/

class Solution
{
public:
    void rotateBy180Degrees(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            reverse(matrix.begin(), matrix.end());
        }

        int i = 0;
        while (i < n / 2)
        {
            swap(matrix[i], matrix[n - i - 1]);
            i++;
        }

        for (auto it : matrix)
        {
            for (int x : it)
                cout << x << " ";

            cout << endl;
        }
    }
};