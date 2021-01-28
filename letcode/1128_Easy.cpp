#include<iostream>
#include<vector>

using namespace std;

//给你一个由一些多米诺骨牌组成的列表 dominoes。
//
//如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
//
//形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a == c 且 b == d，或是 a == d 且 b == c。
//
//在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对(i, j) 的数量。
//
//
//提示：
//
//	1 <= dominoes.length <= 40000
//	1 <= dominoes[i][j] <= 9
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//使用骨牌桶记录等价的骨牌数量。
//int numEquivDominoPairs(vector<vector<int>>& dominoes) 
//{
//	const int BucketSize = 81;
//	vector<int> dominoBucket(BucketSize);
//	int minPair;
//	int maxPair;
//
//	//装填骨牌桶
//	for (vector<vector<int>>::iterator it = dominoes.begin(); it != dominoes.end(); it++)
//	{
//		minPair = it->at(0) > it->at(1) ? it->at(1) : it->at(0);
//		maxPair = it->at(0) > it->at(1) ? it->at(0) : it->at(1);
//		dominoBucket[9 * (minPair - 1) + (maxPair - 1)]++;
//	}
//	
//	//计算等价骨牌对
//	int equivCnt = 0;
//	for (int i = 0; i < BucketSize; i++)
//	{
//		equivCnt += dominoBucket[i] * (dominoBucket[i] - 1) / 2;
//	}
//	return equivCnt;
//}


//优化版。
int numEquivDominoPairs(vector<vector<int>>& dominoes)
{
	const int BucketSize = 81;
	vector<int> dominoBucket(BucketSize);

	//装填骨牌桶，同时计算等价骨牌对数量。
	int equivCnt = 0;
	int index;
	for (vector<vector<int>>::iterator it = dominoes.begin(); it != dominoes.end(); it++)
	{
		index = it->at(0) > it->at(1) ? (9 * (it->at(0) - 1) + it->at(1) - 1) : (9 * (it->at(1) - 1) + it->at(0) - 1);
		equivCnt += dominoBucket[index];
		dominoBucket[index]++;
	}
	return equivCnt;
}

int main1128()
{
	vector<vector<int>> test = { {1,2},{2,2},{2,1},{1,2} ,{1,2} };
	int ret = numEquivDominoPairs(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}