#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。
//
//返回森林中兔子的最少数量。
//
//
//说明 :
//
//	answers 的长度最大为1000。
//	answers[i] 是在 [0, 999] 范围内的整数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/rabbits-in-forest
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//贪心算法。使用哈希表 sameMap 存储回答各数量的兔子数。理论上：当满足森林中兔子数量最少的要求时，对于 sameMap 中的任意回答数量 x ，最多每 x + 1 个 x 为一组，可以构成一种颜色；未回答的兔子数量最少应使得所有颜色的兔子全部“满编”；最后将所有颜色的兔子累和即为所求。实现上：首先遍历原始 answers 数组一次，填充 sameMap 哈希表，记录回答各数量的兔子数；随后遍历 sameMap 哈希表一次，对任意数量 x ，至少应有 1 + (sameMap.at(x) - 1) / (x + 1) 种颜色的兔子，这些颜色的兔子一共有 (1 + (sameMap.at(x) - 1) / (x + 1)) * (x + 1) 只，将所有颜色的兔子累和即为所求。
int numRabbits(vector<int>& answers)
{
	unordered_map<int, int> sameMap;
	for (vector<int>::iterator it = answers.begin(); it != answers.end(); it++) //记录各回答数量的兔子数
		sameMap[*it]++;

	int sumCnt = 0;
	for (unordered_map<int, int>::iterator it = sameMap.begin(); it != sameMap.end(); it++)
	{
		sumCnt += (1 + it->first)*(1 + (it->second - 1) / (1 + it->first));
	}
	return sumCnt;
}


int main781()
{
	vector<int> test = { 10, 10, 10 };
	//vector<int> test = { 1,1,2 };
	int ret = numRabbits(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}