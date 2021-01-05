#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//有一堆石头，每块石头的重量都是正整数。
//
//每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
//
//提示：
//
//1.	1 <= stones.length <= 30
//2.	1 <= stones[i] <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/last-stone-weight
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力排序。
int lastStoneWeight(vector<int>& stones)
{

	int left = 0;
	while (stones.size() > 1)
	{
		sort(stones.begin(), stones.end());
		left = abs(stones[stones.size() - 1] - stones[stones.size() - 2]);
		cout << "粉碎最重的两块石头：" << stones[stones.size() - 1] << " , " << stones[stones.size() - 2] << endl;
		stones.pop_back();
		stones.pop_back();
		stones.push_back(left);
	}
	if (1 == stones.size())
		return stones[0];
	return 0;
}



int main1046()
{
	vector<int>test = { 2,7,4,1,8,1 };
	int ret = lastStoneWeight(test);
	cout << "main：ret=" << ret << endl;
	return 0;
}