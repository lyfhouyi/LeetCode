#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
//
//注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//
//
//提示：
//
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/largest-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//“特殊”的排序规则
bool mySort(int A, int B)
{
	string sA = to_string(A) + to_string(B); //数字 A 排前面可以取得的值
	string sB = to_string(B) + to_string(A); //数字 B 排前面可以取得的值
	return sA > sB;
}


//“特殊”的排序规则
//bool mySort(int A, int B)
//{
//	long upA = 10;
//	long upB = 10;
//
//	while (upA <= A) //求最小的大于 A 的 10 的整数幂
//		upA *= 10;
//	while (upB <= B) //求最小的大于 B 的 10 的整数幂
//		upB *= 10;
//
//	return A * upB + B > B*upA + A;
//}


//排序。首选按“特殊规则”排序；随后按序合成字符串作为返回值。
string largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), mySort);
	string ret;
	if (nums[0] == 0)
		return "0";
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		ret += to_string(*it);
	}
	return ret;
}


int main179()
{
	//vector<int> test = { 9,99,6,65,68,54,66,60 };
	//vector<int> test = { 10,0,0,0 };
	//vector<int> test = { 34323, 3432 };
	vector<int> test = { 0, 0, 0 };
	//vector<int> test = { 3,30,34,5,9 };
	string ret = largestNumber(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}