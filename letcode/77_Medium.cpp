#include<iostream>
#include<vector>

using namespace std;

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/combinations
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//回溯算法。根据当前组合选择是否将当前元素加入到当前组合中。回溯于是否将当前元素加入到当前组合中，为使解集中的组合不存在重复元素且组合各不相同，在每层递归中，当前可以加入的元素只能是上次加入元素之后的元素；递归基：当前组合元素数量满足要求时，将当前组合加入解集中。
void findCombination(int n, int beginValue, vector<int>& currentCombination, int k, vector<vector<int>>& ret)
{
	if (currentCombination.size() == k)
	{
		ret.push_back(currentCombination);
		return;
	}
	for (int i = beginValue; i <= n; i++)
	{
		if (currentCombination.size() + n - i + 1 < k) //剪枝：剩余元素即使全部选取也不可能达到满足要求的元素数量时，可以提前退出循环
			break;
		currentCombination.push_back(i);
		findCombination(n, i + 1, currentCombination, k, ret);
		currentCombination.pop_back();
	}
	return;
}


//递归。递归调用 findCombination() 函数，判断应在当前组合中加入哪个元素。
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ret;
	vector<int> currentCombination;
	findCombination(n, 1, currentCombination, k, ret);
	return ret;
}


int main77()
{
	vector<vector<int>> ret = combine(4, 2);
	cout << "main：ret = " << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}