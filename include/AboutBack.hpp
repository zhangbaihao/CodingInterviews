#include "Util.h"
// JZ12 矩阵中的路径
class JZ12Solution
{
public:
    // k代表走过的路程大小，从(row,col)点走
    bool dfs(vector<vector<char>> matrix, string word, int k, int row, int col)
    {
        if (matrix[row][col] != word[k])
            return false;
        //把每次成功找到的走过的路径上的字符设置为*；防止str中存在重复的元素
        matrix[row][col] = '#';
        k++;
        //当找到的路径数目等于字符长度，那么说明路径已经找到了
        if (k == word.size())
            return true;
        //定义四个方向坐标 {上下,左右}
        int dirct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            //从x y往上下左右四个方向走
            int row1 = row + dirct[i][0];
            int col1 = col + dirct[i][1];
            if (col1 >= 0 && col1 < matrix[0].size() && row1 >= 0 && row1 < matrix.size())
                if (dfs(matrix, word, k, row1, col1))
                    return true;
        }
        return false;
    }
    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(matrix, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
// JZ13 机器人的运动范围
// 10,1,100 返回值29
//说明：
/*[0,0],[0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[0,7],[0,8],[0,9],[0,10],[0,11],[0,12],
[0,13],[0,14],[0,15],[0,16],[0,17],[0,18],[0,19],[0,20],[0,21],[0,22],[0,23],[0,24],
[0,25],[0,26],[0,27],[0,28] 这29种，后面的[0,29],[0,30]以及[0,31]等等是无法到达的
*/
// 0≤threshold≤15 1≤rows,cols≤100
class JZ13Solution
{
public:
    int flags[100][100];
    //往              右       下      左        上
    int dx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int threshold, int row, int col, int rows, int cols, int &count)
    {
        flags[row][col] = 1;
        count = count + 1;
        for (int j = 0; j < 4; j++)
        {
            int row_t = row + dx[j][0];
            int col_t = col + dx[j][1];
            if (col_t >= 0 && col_t < cols && row_t >= 0 && row_t < rows)
            {
                //这里还要防止往回走
                if (flags[row_t][col_t] == 1)
                    continue;
                int rowSum = row_t % 10 + (row_t / 10) % 10;
                int colSum = col_t % 10 + (col_t / 10) % 10;
                //不能进入行坐标和列坐标的数位之和大于 threshold 的格子
                if (rowSum + colSum > threshold)
                {
                    continue;
                }
                dfs(threshold, row_t, col_t, rows, cols, count);
            }
        }
    }
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        dfs(threshold, 0, 0, rows, cols, count);
        return count;
    }
};
