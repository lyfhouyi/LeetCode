#include<iostream>
#include<vector>

using namespace std;

//如果数组是单调递增或单调递减的，那么它是单调的。
//
//如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i] > = A[j]，那么数组 A 是单调递减的。
//
//当给定的数组 A 是单调数组时返回 true，否则返回 false。
//
//
//提示：
//
//	1 <= A.length <= 50000
//	- 100000 <= A[i] <= 100000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/monotonic-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历数组。逐项比较。
bool isMonotonic(vector<int>& A)
{
	int n = A.size();
	if (n < 2)
		return true;
	int i = 1;
	while (i < n && A[i] == A[i - 1]) //相等的元素不影响数组的单调性，可跳过
		i++;
	if (i == n)
		return true;
	bool isIncrease = A[i] > A[i - 1];
	while (i < n)
	{
		if ((isIncrease && A[i] < A[i - 1]) || (!isIncrease && A[i] > A[i - 1])) //相等的元素不会满足条件
			return false;
		i++;
	}
	return true;
}


int main896()
{
	//vector<int> test = { 1,1,0 };
	//vector<int> test = { 1,1,0,0,-1 };
	//vector<int> test = { 1,1,2 };
	//vector<int> test = { 1,1,1 };
	//vector<int> test = { 1,2,2,3 };
	vector<int> test = { 3,2,2,1 };
	bool ret = isMonotonic(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}