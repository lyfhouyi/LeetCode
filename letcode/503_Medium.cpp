#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 - 1。
//
//
//注意 : 输入数组的长度不会超过 10000。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/next-greater-element-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递减栈。单指针循环遍历数组，使用一个递减栈维护当前指针之前的尚未找到更大元素的元素的位置索引；若当前指针的元素大于栈顶元素，说明栈顶元素已找到位于其后且比它更大的元素，则更新该位置并弹出栈顶；持续按此规则弹出栈顶元素，直到栈顶元素大于或等于当前元素后，将当前元素压栈，并循环考察下一元素；若循环遍历指针已移动一周且移动至当前栈底元素的位置，说明全部元素已处理完毕，此时栈中元素均为最大值元素，则将其返回值置为 -1 即可。
vector<int> nextGreaterElements(vector<int>& nums)
{
	int n = nums.size();
	int i = 0;
	int bottom;
	bool isRound = false;
	stack<int> undeterminedElements;
	vector<int> ret(n, -1);
	while (i < n) //逐项处理各元素
	{
		while (!undeterminedElements.empty() && nums[undeterminedElements.top()] < nums[i]) //更新该位置并弹出栈顶
		{
			ret[undeterminedElements.top()] = nums[i];
			undeterminedElements.pop();
		}
		if (-1 == ret[i]) //已处理过的元素无需再入栈
		{
			if (undeterminedElements.empty()) //实时记录栈底的元素索引
				bottom = i;
			undeterminedElements.push(i);
		}
		if (isRound && bottom == i) //此时栈中的元素均相等且为原数组的最大值元素
			break;
		i++;
		if (i >= n)
		{
			isRound = true;
			i -= n;
		}
	}
	return ret;
}


int main503()
{
	//vector<int> test = { 1,2,1 };
	//vector<int> test = { -1,-2,-1,2,2,1,1 };
	//vector<int> test = { 5,3,9,1,2,4,0,3,7,9,6,2,4 };
	vector<int> test = { 5,3,9,1,2,4,0,3,7,9 };
	//vector<int> test = { 5,3,9,1,2,4,2,0,1,3,7,6,2,4 };
	vector<int> ret = nextGreaterElements(test);
	cout << "main：ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}