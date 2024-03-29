#include <iostream>
#include <vector>

using namespace std;

// 在 R 行 C 列的矩阵上，我们从 (r0, c0) 面朝东面开始
//
// 这里，网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。
//
// 现在，我们以顺时针按螺旋状行走，访问此网格中的每个位置。
//
// 每当我们移动到网格的边界之外时，我们会继续在网格之外行走（但稍后可能会返回到网格边界）。
//
// 最终，我们到过网格的所有 R * C 个空间。
//
// 按照访问顺序返回表示网格位置的坐标列表。
//
//
// 提示：
//
//     1 <= R <= 100
//     1 <= C <= 100
//     0 <= r0 < R
//     0 <= c0 < C
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/spiral-matrix-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//判断给定位置是否在给定矩阵之中
bool isSafe(int rows, int cols, int posRow, int posCol)
{
    return (posRow >= 0 && posRow < rows && posCol >= 0 && posCol < cols);
}

//根据漫步方向计算漫步位置
void calcNextPos(int curRow, int curCol, int face, int &nextRow, int &nextCol)
{
    switch (face)
    {
    case 0:
        //面向东
        nextRow = curRow;
        nextCol = curCol + 1;
        break;
    case 1:
        //面向南
        nextRow = curRow + 1;
        nextCol = curCol;
        break;
    case 2:
        //面向西
        nextRow = curRow;
        nextCol = curCol - 1;
        break;
    default:
        //面向北
        nextRow = curRow - 1;
        nextCol = curCol;
        break;
    }
}

//暴力解法。首先试探性地顺时针转向，若下一漫步位置不符合要求（没出格，但已经漫步过）则逆时针转回继续向前；即使下一漫步位置出格，依旧可以保持顺时针转向后的方向继续漫步，只不过不能输出，相当于矩阵外围有一圈只能漫步不能输出的“路径”。
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<bool>> flagMatrix(rows, vector<bool>(cols, false));
    vector<vector<int>> ret;
    int walkCnt = 0;
    int curRow = rStart;
    int curCol = cStart;
    int nextRow;
    int nextCol;
    int face = 3;
    while (walkCnt < rows * cols)
    {
        if (isSafe(rows, cols, curRow, curCol))
        {
            //输出当前漫步位置
            ret.push_back(vector<int>({curRow, curCol}));
            flagMatrix[curRow][curCol] = true;
            walkCnt++;
            // cout << "第" << walkCnt << "步：[" << curRow << "," << curCol << "]" << endl;
        }

        //计算漫步方向
        face = (face + 1) % 4; //试探性地顺时针转向
        calcNextPos(curRow, curCol, face, nextRow, nextCol);
        if (isSafe(rows, cols, nextRow, nextCol) && flagMatrix[nextRow][nextCol])
        {
            //没出格，但已经漫步过，则逆时针转回继续向前
            face = (face - 1) % 4;
            calcNextPos(curRow, curCol, face, nextRow, nextCol);
        }

        //移动至下一漫步位置
        curRow = nextRow;
        curCol = nextCol;
    }
    return ret;
}

int main885()
{
    vector<vector<int>> ret = spiralMatrixIII(1, 4, 0, 0);
    // vector<vector<int>> ret = spiralMatrixIII(3, 6, 1, 4);
    cout << "main：ret = " << endl;
    for (auto pos = ret.begin(); pos != ret.end(); pos++)
    {
        cout << "[" << pos->at(0) << "," << pos->at(1) << "], ";
    }
    cout << endl;
    return 0;
}