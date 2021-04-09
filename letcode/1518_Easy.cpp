#include<iostream>

using namespace std;

//小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//
//如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//
//请你计算 最多 能喝到多少瓶酒。
//
//
//提示：
//
//	1 <= numBottles <= 100
//	2 <= numExchange <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/water-bottles
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：迭代。有的喝就喝，喝完换空瓶。
//int numWaterBottles(int numBottles, int numExchange)
//{
//	int ret = 0;
//	int emptyCnt = 0;
//	int fullCnt = numBottles;
//	while (fullCnt > 0) //先喝，再换空瓶
//	{
//		ret += fullCnt; //喝
//		emptyCnt += fullCnt; //喝完剩下空瓶
//		fullCnt = emptyCnt / numExchange; //换空瓶
//		emptyCnt = emptyCnt % numExchange; //换完剩下空瓶
//	}
//	return ret;
//}


//解法二：数学。可以换瓶的轮数 n = 1 + (numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) : -1) ，每轮换 1 瓶。
int numWaterBottles(int numBottles, int numExchange)
{
	return numBottles + 1 + (numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) : -1);
}


int main1518()
{
	int ret = numWaterBottles(5, 5);
	cout << "main：ret = " << ret << endl;
	return 0;
}