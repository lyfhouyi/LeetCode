#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
//注意 :
//
//1.可以认为区间的终点总是大于它的起点。
//2.区间[1, 2] 和[2, 3] 的边界相互“接触”，但没有相互重叠

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/non-overlapping-intervals
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


bool smallInterval(vector<int>intervalA, vector<int>intervalB)
{
	if (intervalA[0] < intervalB[0])
		return true;
	if (intervalA[0] == intervalB[0])
		return (intervalA[1] < intervalB[1]);
	return false;
}

//判断 A , B 区间哪个应该被移除（ A 返回 1，B 返回 2，无需移除返回 0 ）
int which2erase(vector<int>intervalA, vector<int>intervalB)
{
	if (intervalB[0] >= intervalA[1])
		return 0;
	if (intervalB[1] >= intervalA[1])
		return 2;
	return 1;
}


//贪心算法：将区间排序后，依次比较两个相邻区间，步幅为1，每次比较都决定比较的两个区间中哪个应该被移除或者都无需移除。
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
	if (0 == intervals.size())
		return 0;
	sort(intervals.begin(), intervals.end(), smallInterval);
	vector<vector<int>>::iterator it1 = intervals.begin();
	vector<vector<int>>::iterator it2 = intervals.begin() + 1;
	int eraseInterval = -1;
	int eraseCnt = 0;
	while (it2 != intervals.end())
	{
		eraseInterval = which2erase(*it1, *it2);
		switch (eraseInterval)
		{
		case 2:
		{
			cout << "移除区间：[" << (*it2)[0] << "," << (*it2)[1] << "]" << endl;
			eraseCnt++;
			*it2 = *it1;
			break;
		}
		case 1:
		{
			cout << "移除区间：[" << (*it1)[0] << "," << (*it1)[1] << "]" << endl;
			eraseCnt++;
			break;
		}
		default:
			break;
		}
		it1++;
		it2++;
	}
	return eraseCnt;
}


int main435()
{
	//vector<vector<int>>test = { {1,2},{2,3},{3,4},{1,3} };
	vector<vector<int>>test = {  };
	int ret = eraseOverlapIntervals(test);
	cout << "main：ret=" << ret << endl;
	return 0;
}