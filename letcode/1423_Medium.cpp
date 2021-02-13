#include<iostream>
#include<vector>

using namespace std;

//几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
//
//每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
//
//你的点数就是你拿到手中的所有卡牌的点数之和。
//
//给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
//
//
//提示：
//
//	1 <= cardPoints.length <= 10 ^ 5
//	1 <= cardPoints[i] <= 10 ^ 4
//	1 <= k <= cardPoints.length
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针构造滑动窗口。两个指针 itA 、 itB 所构成的滑动窗口为 [begin,itA) ∪ [itB,end) ；使滑动窗划过整个数组，窗内元素和的最大值即为所求。
int maxScore(vector<int>& cardPoints, int k)
{
	int n = cardPoints.size();
	int currentSum = 0;
	//第一个滑动窗。itA = k , itB = n
	for (int i = 0; i < k; i++)
	{
		currentSum += cardPoints[i];
	}
	int maxSum = currentSum;

	if (n == k) //满窗时，无需移动
		return maxSum;

	//从第二个位置开始移动滑动窗窗。滑动窗为 [begin,itA) ∪ [itB,end)
	int itB;
	for (int itA = k - 1; itA >= 0; itA--)
	{
		//新移出的元素位于 itA 处，新移入的元素位于 itB 处
		itB = n - k + itA;
		currentSum = currentSum - cardPoints[itA] + cardPoints[itB];
		maxSum = maxSum > currentSum ? maxSum : currentSum;
	}
	return maxSum;
}


int main1423()
{
	vector<int> test = { 1, 79, 80, 1, 1, 1, 200, 1 };
	//vector<int> test = { 1,1000,1 };
	//vector<int> test = { 9,7,7,9,7,7,9 };
	//vector<int> test = { 2,2,2 };
	//vector<int> test = { 1,2,3,4,5,6,1 };
	int ret = maxScore(test, 3);
	cout << "main：ret = " << ret << endl;
	return 0;
}