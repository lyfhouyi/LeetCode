#include<iostream>
#include<vector>

using namespace std;

//在一根无限长的数轴上，你站在0的位置。终点在target的位置。
//
//每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
//
//返回到达终点需要的最小移动次数。
//
//
//注意 :
//
//	target是在[-10 ^ 9, 10 ^ 9]范围中的非零整数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reach-a-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法。枚举所有可达解，直到找到目标值。
//算法正确，但时间超时。
//int reachNumber(int target)
//{
//	vector<int> reachableDomain(1,0);
//	int stepCnt = 1;
//	int n;
//	while (true)
//	{
//		n = reachableDomain.size();
//		vector<int> reachableDomainNew;
//		for (int i = 0; i < n; i++)
//		{
//			if (reachableDomain[i] + stepCnt == target)
//				return stepCnt;
//			else
//				reachableDomainNew.push_back(reachableDomain[i] + stepCnt);
//
//			if (reachableDomain[i] - stepCnt == target)
//				return stepCnt;
//			else
//				reachableDomainNew.push_back(reachableDomain[i] - stepCnt);
//		}
//		reachableDomain = reachableDomainNew;
//		reachableDomainNew.clear();
//		stepCnt++;
//	}
//	return 0;
//}


//解法一：数学分析。首先找到累加和足够大的 k ；随后判断累加和与目标值的差的奇偶性，当累加和与目标值之差为偶数时，只需将 k 中的某个值取负即可；当累加和与目标值之差为奇数时，需取到 k + 1 或 k + 2 使目累加和与目标值之差为偶数，并将累加和中的某个值取负即可。可以证明，当累加和与目标值之差为偶数时，存在且一定存在某个累加和元素，将其取负时可以达到目标值，且此时步数最少。
//int reachNumber(int target)
//{
//	target = target > 0 ? target : -target;
//	int s = 0;
//	int k = 0;
//	while (s < target)
//	{
//		k++;
//		s += k;
//	}
//	int delta = s - target;
//	int ret = k + delta % 2;
//	if (delta % 2 == 1 && k % 2 == 1)
//		ret++;
//	return ret;
//}


//解法二：数学分析。逐个累加累加和，直到累加和大于或等于目标值，且累加和与目标值之差为偶数为止；此时只需将累加和与目标值之差的一半的那个累加和项取负即可得到目标值。可以证明，此时的步数最少。
int reachNumber(int target)
{
	target = target > 0 ? target : -target;
	int s = 0;
	int k = 0;
	while (s < target || (s - target) % 2 == 1)
	{
		k++;
		s += k;
	}
	return k;
}


int main754()
{
	int ret = reachNumber(100000);
	cout << "main：ret = " << ret << endl;
	return 0;
}