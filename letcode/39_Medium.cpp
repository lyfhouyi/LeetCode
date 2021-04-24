#include<iostream>
#include<vector>

using namespace std;

//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。 
//示例 1：
//
//
//提示：
//
//	1 <= candidates.length <= 30
//	1 <= candidates[i] <= 200
//	candidate 中的每个元素都是独一无二的。
//	1 <= target <= 500
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/combination-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//回溯算法。根据当前组合元素和 currentSum 判断下一步可以将哪个元素加入到当前组合中。回溯于下一步加入当前组合的是哪一个元素，为使解集中的组合各不相同，在每层递归中，当前可以加入的元素只能是上次加入元素（含）之后的元素；递归基：当前组合元素和满足要求时，将当前组合加入解集中。
void findValidCombination(vector<int>& candidates, int beginIndex, vector<int>& currentCombination, int currentSum, int target, vector<vector<int>>& ret)
{
	if (currentSum == target)
	{
		ret.push_back(currentCombination);
		return;
	}
	int n = candidates.size();
	for (int i = beginIndex; i < n; i++)
	{
		if (candidates[i] + currentSum <= target)
		{
			currentCombination.push_back(candidates[i]);
			findValidCombination(candidates, i, currentCombination, candidates[i] + currentSum, target, ret);
			currentCombination.pop_back();
		}

	}
	return;
}


//递归。递归调用 findValidCombination() 函数，判断应在当前组合中加入哪个元素。
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> ret;
	vector<int> currentCombination;
	findValidCombination(candidates, 0, currentCombination, 0, target, ret);
	return ret;
}


int main39()
{
	vector<int> test = { 1,2,3 };
	vector<vector<int>> ret = combinationSum(test, 4);
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