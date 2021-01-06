#include<iostream>
#include<vector>
#include<string>

using namespace std;

//在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。
//
//例如，在字符串 s = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
//
//分组可以用区间[start, end] 表示，其中 start 和 end 分别表示该分组的起始和终止位置的下标。上例中的 "xxxx" 分组用区间表示为[3, 6] 。
//
//我们称所有包含大于或等于三个连续字符的分组为 较大分组 。
//
//找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。
//
//
//提示：
//
//	1 <= s.length <= 1000
//	s 仅含小写英文字母
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/positions-of-large-groups
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单个滑动指针遍历数组
vector<vector<int>> largeGroupPositions(string s)
{
	vector<vector<int>> largeGroups(0);
	int consecutiveCnt = 1;
	int consecutiveBegin = 0;
	for (string::iterator it = s.begin() + 1; it != s.end(); it++)
	{
		if (*it == *(it - 1))
		{
			consecutiveCnt++;
			continue;
		}
		if (consecutiveCnt >= 3)
			largeGroups.push_back(vector<int>({ consecutiveBegin ,int(it - s.begin() - 1) }));
		consecutiveBegin = it - s.begin();
		consecutiveCnt = 1;
	}
	if (consecutiveCnt >= 3)
		largeGroups.push_back(vector<int>({ consecutiveBegin ,int(s.end() - s.begin() - 1) }));
	return largeGroups;
}

int main830()
{
	string test = "abcdddeeeeaabbbcd";
	vector<vector<int>> ret= largeGroupPositions(test);
	cout << "main：ret = [";
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[" << it->at(0) << "," << it->at(1) << "],";
	}
	cout << "]" << endl;
	return 0;
}