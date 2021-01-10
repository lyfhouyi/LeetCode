#include<iostream>
#include<string>
#include<vector>

using namespace std;

//给定一个无重复元素的有序整数数组 nums 。
//
//返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
//
//列表中的每个区间范围[a, b] 应该按如下格式输出：
//
//"a->b" ，如果 a != b
//"a" ，如果 a == b
//
//
//提示：
//
//	0 <= nums.length <= 20
//	- 231 <= nums[i] <= 231 - 1
//	nums 中的所有值都 互不相同
//	nums 按升序排列
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/summary-ranges
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历。
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> ret;
	if (0 == nums.size())
		return ret;
	nums.push_back(nums.back()); //加入尾部哨兵，以处理最后一个区间
	int intervalBegin = nums[0];
	for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); it++)
	{
		if (*(it-1) == *it-1)
			continue;
		string tmp = to_string(intervalBegin);
		if (intervalBegin != *(it - 1))
			tmp += "->" + to_string(*(it - 1));
		ret.push_back(tmp);
		intervalBegin = *it;
	}
	return ret;
}


int main228()
{
	vector<int> test = {-2147483647, 2147483647 };
	//vector<int> test = { 0, 2, 3, 4, 6, 8, 9 };
	//vector<int> test = { 0,1,2,4,5,7 };
	vector<string> ret = summaryRanges(test);
	cout << "main：ret = ";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}