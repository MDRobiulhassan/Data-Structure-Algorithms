#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int area = 0;
        stack<int> st;
        int nse, pse, element;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                element = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                area = max(heights[element] * (nse - pse - 1), area);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            area = max(heights[element] * (nse - pse - 1), area);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > pf(n, vector<int>(m));

        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum = (matrix[i][j] == '0') ? 0 : sum + (matrix[i][j] - '0');
                pf[i][j] = sum;
            }
        }

        int maxarea = 0;
        for (int i = 0; i < n; i++)
            maxarea = max(maxarea, largestRectangleArea(pf[i]));

        return maxarea;
    }
};