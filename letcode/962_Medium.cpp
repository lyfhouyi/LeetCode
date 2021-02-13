#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
//
//找出 A 中的坡的最大宽度，如果不存在，返回 0 。
//
//
//
//提示：
//
//	2 <= A.length <= 50000
//	0 <= A[i] <= 50000
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-width-ramp
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递减栈。首先从首元素开始，将比栈顶元素小的元素索引压入栈中；随后从尾元素开始遍历，若当前元素小于栈顶则跳过，若当前元素大于栈顶，更新最大宽度并弹出栈顶；反向遍历一次后，即可得到所求的最大宽度。
int maxWidthRamp(vector<int>& A)
{
	int n = A.size();
	stack<int> heightStack;

	//构造递减栈
	heightStack.push(0);
	for (int i = 1; i < n; i++)
	{
		if (A[i] < A[heightStack.top()])
			heightStack.push(i);
	}

	//计算最大跨度
	int j = n - 1;
	int maxLength = 0;
	int currentLength;
	while (j >= 0)
	{
		if (heightStack.empty())
			break;
		if (A[j] < A[heightStack.top()])
			j--;
		else
		{
			currentLength = j - heightStack.top();
			maxLength = maxLength > currentLength ? maxLength : currentLength;
			heightStack.pop();
		}
	}
	return maxLength;
}


int main962()
{
	vector<int> test = { 2,9 };
	//vector<int> test = { 6,0,8,2,1,5 };
	//vector<int> test = { 9,8,1,0,1,9,4,0,4,1 };
	int ret = maxWidthRamp(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}