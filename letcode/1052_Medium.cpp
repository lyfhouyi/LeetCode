#include<iostream>
#include<vector>

using namespace std;

//今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。
//
//在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。
//
//书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。
//
//请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
//
//
//提示：
//
//	1 <= X <= customers.length == grumpy.length <= 20000
//	0 <= customers[i] <= 1000
//	0 <= grumpy[i] <= 1
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/grumpy-bookstore-owner
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//滑动窗。首先计算初始状态不满意的客人数量数组；随后在该数组上移动窗宽为 X 的滑动窗口，将窗口滑动一遍后，找到窗内不满意客人数量的最大值；将不满意客人数量最大的那个窗口置为“不生气”窗口，则客人总数减去剩余不满意的人数即为所求。
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
	int n = customers.size();
	int customerCnt = 0; //客人总数
	int currentDiscontentCnt = 0; //当前窗口不满意的客人数量
	for (int i = 0; i < X; i++) //第一个窗口
	{
		customerCnt += customers[i];
		currentDiscontentCnt += customers[i] * grumpy[i];
	}

	int discontentCnt = currentDiscontentCnt; //不满意的客人总数
	int maxDiscontentCnt = currentDiscontentCnt; //所有窗口中不满意的客人数量的最大值
	for (int i = 1; i < n - X + 1; i++) //窗口滑动
	{
		customerCnt += customers[i + X - 1];
		discontentCnt += customers[i + X - 1] * grumpy[i + X - 1];
		currentDiscontentCnt = currentDiscontentCnt + customers[i + X - 1] * grumpy[i + X - 1] - customers[i - 1] * grumpy[i - 1];
		maxDiscontentCnt = maxDiscontentCnt > currentDiscontentCnt ? maxDiscontentCnt : currentDiscontentCnt;
	}
	return customerCnt - discontentCnt + maxDiscontentCnt;
}


int main1052()
{
	//vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
	//vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
	vector<int> customers = { 10 };
	vector<int> grumpy = { 0 };
	int ret = maxSatisfied(customers, grumpy, 1);
	cout << "main：ret = " << ret << endl;
	return 0;
}