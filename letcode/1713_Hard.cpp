#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>

using namespace std;

//给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。
//
//每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1, 4, 1, 2] ，那么你可以在中间添加 3 得到 [1, 4, 3, 1, 2] 。你可以在数组最开始或最后面添加整数。
//
//请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
//
//一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2, 7, 4] 是 [4, 2, 3, 7, 2, 1, 4] 的子序列（加粗元素），但 [2, 4, 2] 不是子序列。
//
//
//提示：
//
//	1 <= target.length, arr.length <= 10^5
//	1 <= target[i], arr[i] <= 10^9
//	target 不包含任何重复元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//字典。首先遍历一次 target 数组，构造 target 数组索引字典；随后遍历一次 arr 数组，使用 target 数组索引字典构造索引数组 indexVec ，indexVec 中按顺序存储 arr 数组中出现的 target 数组中元素的索引，则索引数组 indexVec 的严格上升子序列的最大长度即为 arr 数组中与 target 数组具有相同子序列的子序列的最大长度；所求即为 target 数组的长度与该最大长度的差值。
int minOperations(vector<int>& target, vector<int>& arr)
{
	unordered_map<int, int> tIndexMap;
	int n = target.size();
	for (int i = 0; i < n; i++) //构造 target 数组索引字典
		tIndexMap.insert(make_pair(target[i], i));

	vector<int> indexVec;
	n = arr.size();
	for (int i = 0; i < n; i++) //构造索引数组
	{
		if (tIndexMap.count(arr[i]))
			indexVec.push_back(tIndexMap.at(arr[i]));
	}

	vector<int> increaseVec(1, INT_MIN);
	int maxLength = 0;
	n = indexVec.size();
	for (int i = 0; i < n; i++) //计算严格上升子序列的最大长度
	{
		if (increaseVec[maxLength] < indexVec[i])
		{
			increaseVec.push_back(indexVec[i]);
			maxLength++;
		}
		else
		{
			*lower_bound(increaseVec.begin(), increaseVec.end(), indexVec[i]) = indexVec[i];
		}
	}
	return target.size() - maxLength;
}


int main1713()
{
	vector<int> target = { 6,4,8,1,3,2,7 };
	vector<int> arr = { 4,8,3,3,2,7 };
	//vector<int> target = { 5,1,3 };
	//vector<int> arr = { 9,4,2,3,4 };
	int ret = minOperations(target, arr);
	cout << "main：ret = " << ret << endl;
	return 0;
}