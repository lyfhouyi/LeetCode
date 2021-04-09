#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。
//
//请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。
//
//注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。
//
//
//提示：
//
//	1 <= heights.length <= 100
//	1 <= heights[i] <= 100
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/height-checker
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴力解法。排序后比较。
//int heightChecker(vector<int>& heights)
//{
//	vector<int> sortHeights(heights.begin(), heights.end());
//	sort(sortHeights.begin(), sortHeights.end());
//	int n = heights.size();
//	int moveCnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (heights[i] != sortHeights[i])
//			moveCnt++;
//	}
//	return moveCnt;
//}


//解法二：桶。比较原始数组与理论不减数组中不同元素的个数。
int heightChecker(vector<int>& heights)
{
	vector<int> bucketVec(101, 0);
	int n = heights.size();
	for (int i = 0; i < n; i++) //构造桶
	{
		bucketVec[heights[i]]++;
	}
	int moveCnt = 0;
	int i = 0;
	for (int j = 1; j < 101; j++) //比较原始数组与理论不减数组中不同元素的个数
	{
		while (bucketVec[j] > 0)
		{
			if (heights[i] != j)
				moveCnt++;
			bucketVec[j]--;
			i++;
		}
	}
	return moveCnt;
}


int main1051()
{
	//vector<int> test = { 1,1,4,2,1,3 };
	//vector<int> test = { 5,1,2,3,4 };
	vector<int> test = { 1,2,3,4,5 };
	int ret = heightChecker(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}