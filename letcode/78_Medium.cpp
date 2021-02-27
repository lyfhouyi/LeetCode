#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//提示：
//
//	1 <= nums.length <= 10
//	- 10 <= nums[i] <= 10
//	nums 中的所有元素 互不相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/subsets
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


void subsetsBegin(vector<vector<int>>& ret, int cur, vector<int>& nums, vector<int>& currentSubSet)
{
	if (cur == nums.size())
	{
		ret.push_back(currentSubSet);
		return;
	}
	currentSubSet.push_back(nums[cur]);
	subsetsBegin(ret, cur + 1, nums, currentSubSet);
	currentSubSet.pop_back();
	subsetsBegin(ret, cur + 1, nums, currentSubSet);
}


//解法一：位表示法。利用值域有限的特性，将原数组表示为一个 21 位二进制数；通过计算该二进制数的各位的全部子集得到原数组的所有可能的子集；最后将全部子集的位表示法转化为值域上的数值得到所求返回值。
//vector<vector<int>> subsets(vector<int>& nums) 
//{
//	vector<vector<int>> ret;
//	int n = nums.size();
//	//用一个 21 位二进制数表示原数组  由高至低各位分别表示 10,9,8,...,1,0,-1,-2,-3,...,-10
//	int setMask=0;
//	for (int i = 0; i < n; i++)
//	{
//		setMask |= 1 << nums[i] + 10;
//	}
//	//cout <<"setMask = "<< bitset<21>(setMask) << endl;
//	int subSetBit = setMask;
//	int tmp;
//	int pos;
//	while (subSetBit != 0) //计算原数组的子集
//	{
//		//此时 subSetBit 是原数组的一个子集的位表示
//		tmp = subSetBit;
//		pos = 0;
//		vector<int> subSet;
//		while (tmp != 0) //将位表示的子集转化为值域上的数值
//		{
//			if (0 != (tmp & 1))
//			{
//				subSet.push_back(pos - 10);
//			}
//			pos++;
//			tmp >>= 1;
//		}
//		ret.push_back(subSet);
//		subSetBit = (subSetBit - 1) & setMask;
//	}
//	ret.push_back(vector<int>());
//	return ret;
//}


//解法二：迭代。遍历原数组中各元素，每次将新的元素加入到当前的各集合中构成新的子集。
//vector<vector<int>> subsets(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<vector<int>> ret(1, vector<int>()); //初始状态：只有一个空集
//	for (int i = 0; i < n; i++) //将新的元素加入到当前的各集合中构成新的子集
//	{
//		int len = ret.size();
//		for (int j = 0; j < len; j++)
//		{
//			ret.push_back(ret[j]);
//			ret[len + j].push_back(nums[i]);
//		}
//	}
//	return ret;
//}


//解法三：二进制枚举。对原数组中的每个元素，子集中可能包含它也可能不包含它；对原数组中的任一元素，用 1 表示某子集中包含它，则枚举原数组中每个元素包含与否的全部可能情况后，将用 0/1 表示的子集转化为用元素数值表示的子集即可。
//vector<vector<int>> subsets(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<vector<int>> ret;
//	int setMask = pow(2, n) - 1; //原数组的 0/1 表示法
//	int subSetBit = setMask; //子集的 0/1 表示法
//	vector<int> subSet; //子集的元素数值表示法
//	int tmp;
//	int pos;
//	while (subSetBit != 0)
//	{
//		subSet.clear();
//		tmp = subSetBit;
//		pos = 0;
//		while (tmp != 0) //将位表示的子集转化为值域上的数值
//		{
//			if (0 != (tmp & 1))
//			{
//				subSet.push_back(nums[pos]);
//			}
//			pos++;
//			tmp >>= 1;
//		}
//		ret.push_back(subSet);
//		subSetBit = (subSetBit - 1) & setMask;
//	}
//	ret.push_back(vector<int>());
//	return ret;
//}


//解法四：回溯算法。遍历原数组，使用递归分别处理子集包含当前元素及不包含当前元素的情况。
vector<vector<int>> subsets(vector<int>& nums)
{
	int n = nums.size();
	vector<vector<int>> ret;
	vector<int> currentSubSet;
	subsetsBegin(ret, 0, nums, currentSubSet);
	return ret;
}


int main78()
{
	//vector<vector<int>> test = { {3} };
	//vector<vector<int>> test = { {1,2,3},{4,5,6} };
	vector<int> test = { 1,2,3 };
	vector<vector<int>> ret = subsets(test);
	cout << "main：ret =" << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}
	return 0;
}