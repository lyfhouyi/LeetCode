#include<iostream>
#include<vector>

using namespace std;

//在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。
//
//请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。
//
//
//提示：
//
//	2 <= coordinates.length <= 1000
//	coordinates[i].length == 2
//	- 10 ^ 4 <= coordinates[i][0], coordinates[i][1] <= 10 ^ 4
//	coordinates 中不含重复的点
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/check-if-it-is-a-straight-line
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：双指针遍历数组。判断各点斜率。
//bool checkStraightLine(vector<vector<int>>& coordinates) 
//{
//	vector<vector<int>>::iterator it1= coordinates.begin();
//	vector<vector<int>>::iterator it2= coordinates.begin()+1;
//	double gradient;
//	double tmp;
//	bool isVertical = false;
//	if (it2->at(0) == it1->at(0))
//		isVertical = true;
//	else
//		gradient = double(it2->at(1) - it1->at(1)) / double(it2->at(0) - it1->at(0));
//	while (it2 != coordinates.end())
//	{
//		if (isVertical)
//		{
//			if (it2->at(0) != it1->at(0))
//				return false;
//			else
//			{
//				it1++;
//				it2++;
//				continue;
//			}
//		}
//		if (it2->at(0) == it1->at(0))
//			return false;
//		tmp= double(it2->at(1) - it1->at(1)) / double(it2->at(0) - it1->at(0));
//		if (tmp != gradient)
//			return false;
//		gradient = tmp;
//		it1++;
//		it2++;
//	}
//	return true;
//}


//解法二：单指针遍历数组。同时避免判断斜率时的除法。
bool checkStraightLine(vector<vector<int>>& coordinates)
{
	int dx0 = coordinates[1][0] - coordinates[0][0];
	int dy0 = coordinates[1][1] - coordinates[0][1];
	int n = coordinates.size();
	int dx;
	int dy;
	for (int i = 1; i < n; i++)
	{
		dx = coordinates[i][0] - coordinates[0][0];
		dy= coordinates[i][1] - coordinates[0][1];
		if (dx*dy0 != dy * dx0)
			return false;
	}
	return true;
}



int main1232()
{
	vector<vector<int>> test = { {1, 2},{2,3},{3,4},{3,7}/*,{3, 4},{4, 5},{5, 6},{6, 7}*/ };
	//vector<vector<int>> test = { {0,0},{0,2},{1,1},{2,0},{2,2} };
	//vector<vector<int>> test = { {0,0} };
	int ret = checkStraightLine(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}