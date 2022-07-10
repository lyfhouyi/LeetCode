#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

// 你的面前有一堵矩形的、由 n 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。
//
// 你现在要画一条 自顶向下 的、穿过 最少 砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
//
// 给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。
//
// 提示：
//
//     n == wall.length
//     1 <= n <= 10^4
//     1 <= wall[i].length <= 10^4
//     1 <= sum(wall[i].length) <= 2 * 10^4
//     对于每一行 i ，sum(wall[i]) 是相同的
//     1 <= wall[i][j] <= 2^31 - 1
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/brick-wall
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//暴力解法。以单位宽度为步长，逐行、逐宽度判断当前位置是否为缝隙；各宽度位置缝隙数最大的垂线即为所求。
//算法正确，时间超时。
// int leastBricks(vector<vector<int>> &wall)
// {
//     int height = wall.size();
//     int width = accumulate(wall[0].begin(), wall[0].end(), 0);

//     vector<vector<bool>> isSeam(height, vector<bool>(width, false));
//     //计算缝隙矩阵
//     for (int i = 0; i < height; i++)
//     {
//         int brickNo = 0;
//         int skip = 0;
//         for (int j = 0; j < width; j++)
//         {
//             if (skip == 0)
//             {
//                 skip = wall[i][brickNo]; //获取缝隙位置
//                 brickNo++;
//             }
//             skip--;
//             isSeam[i][j] = skip > 0 ? false : true; //判断是否为缝隙
//         }
//     }

//     //计算垂线穿过砖块的最小次数
//     int minCnt = height;
//     for (int j = 0; j < width - 1; j++)
//     {
//         int colCnt = 0;
//         for (int i = 0; i < height; i++)
//         {
//             if (isSeam[i][j] == false)
//             {
//                 colCnt++;
//             }
//         }
//         minCnt = min(colCnt, minCnt);
//     }
//     return minCnt;
// }

//暴力解法。逐行统计不同位置上的缝隙个数；各位置上缝隙数最大的垂线即为所求。
int leastBricks(vector<vector<int>> &wall)
{
    unordered_set<int> widthPos;
    unordered_multiset<int> widthPosCnt;
    int height = wall.size();

    //统计不同位置上的缝隙个数
    for (int i = 0; i < height; i++)
    {
        int pos = -1;
        for (int j = 0; j < wall[i].size() - 1; j++)
        {
            pos += wall[i][j];
            widthPos.insert(pos);
            widthPosCnt.insert(pos);
        }
    }

    //找到各位置上缝隙的最大个数
    int maxCnt = 0;
    for (unordered_set<int>::iterator it = widthPos.begin(); it != widthPos.end(); it++)
    {
        maxCnt = max(maxCnt, int(widthPosCnt.count(*it)));
    }
    return height - maxCnt;
}

int main554()
{
    // vector<vector<int>> test{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
    vector<vector<int>> test{{1}, {1}, {1}};
    // vector<vector<int>> test{{100000000}, {100000000}, {100000000}};
    int ret = leastBricks(test);
    cout << "main：ret = " << ret << endl;
    return 0;
}