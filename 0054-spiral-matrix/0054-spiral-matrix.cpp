class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> v;

        int sr = 0;
        int sc = 0;
        int er = matrix.size() - 1;
        int ec = matrix[0].size() - 1;

        while (sr <= er && sc <= ec)
        {
            // Top row
            for (int i = sc; i <= ec; i++)
                v.push_back(matrix[sr][i]);

            // Right column
            for (int i = sr + 1; i <= er; i++)
                v.push_back(matrix[i][ec]);

            // Bottom row (only if another row exists)
            if (sr < er)
            {
                for (int i = ec - 1; i >= sc; i--)
                    v.push_back(matrix[er][i]);
            }

            // Left column (only if another column exists)
            if (sc < ec)
            {
                for (int i = er - 1; i > sr; i--)
                    v.push_back(matrix[i][sc]);
            }

            sr++;
            sc++;
            er--;
            ec--;
        }

        return v;
    }
};