#include<iostream>
#include<vector>

using namespace std;

//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//
//如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1。
//
//说明 :
//
//	如果题目有解，该答案即为唯一答案。
//	输入数组均为非空数组，且长度相同。
//	输入数组中的元素均为非负数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/gas-station
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历。beginGas 记录试探出发的位置，stopGas 记录当前试探可以到达的位置。当前试探失败后，下次试探的出发位置为这次试探失败的位置（即 beginGas_n+1 = stopGas_n ）；如此，当 beginGas 返回到第一次试探的位置时，判定为无法绕行一周。时间复杂度 O(1) ，只需遍历数组一次。
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	vector<int>::iterator stopGas = gas.begin();
	vector<int>::iterator stopCost = cost.begin();
	vector<int>::iterator beginGas;
	vector<int>::iterator beginCost;
	int net;
	int stopSpan = 0;
	bool flag = false; // stopGas 是否经过数组尾
	while (true)
	{
		beginGas = stopGas;
		beginCost = stopCost;
		net = 0;
		bool flagi = false;
		while (net >= 0)
		{
			net = net + *stopGas - *stopCost; // net 保存的是刚到达 stopGas 加油站时油箱的剩余油量（尚未在 stopGas 加油时）
			stopGas++;
			stopCost++;
			if (stopGas == gas.end())
			{
				if (flagi && (beginGas == gas.end() - 1)) //防止试探的出发 beginGas 在数组最后一个元素时，stopGas > beginGas 永远不会成立的死循环
				{
					return beginGas - gas.begin();
				}
				flag = true;
				flagi = true;
				stopGas = gas.begin();
				stopCost = cost.begin();
			}
			if (flagi && (stopGas > beginGas))
				return beginGas - gas.begin();
		}
		stopSpan += flag ? (stopGas - beginGas + gas.size()) : (stopGas - beginGas);
		if (stopSpan > gas.size())
			return -1;
	}
}


int main134()
{
	vector<int> test1 = { 5,1,2,3,4 };
	vector<int> test2 = { 4,4,1,5,1 };
	int ret = canCompleteCircuit(test1, test2);
	cout << "main：ret = " << ret << endl;
	return 0;
}