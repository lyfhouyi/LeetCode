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
int reachNumber(int target)
{
	vector<int> reachableDomain;
	reachableDomain.push_back(0);
	int stepCnt = 1;
	int n;
	while (true)
	{
		n = reachableDomain.size();
		vector<int> reachableDomainNew;
		for (int i = 0; i < n; i++)
		{
			if (reachableDomain[i] + stepCnt == target)
				return stepCnt;
			else
				reachableDomainNew.push_back(reachableDomain[i] + stepCnt);

			if (reachableDomain[i] - stepCnt == target)
				return stepCnt;
			else
				reachableDomainNew.push_back(reachableDomain[i] - stepCnt);
		}
		reachableDomain = reachableDomainNew;
		reachableDomainNew.clear();
		stepCnt++;
	}
	return 0;
}


int main()
{
	int ret = reachNumber(100000);
	cout << "main：ret = " << ret << endl;
	return 0;
}