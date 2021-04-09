#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

//给你一个字符串 num 和一个整数 k 。其中，num 表示一个很大的整数，字符串中的每个字符依次对应整数上的各个 数位 。
//
//你可以交换这个整数相邻数位的数字 最多 k 次。
//
//请你返回你能得到的最小整数，并以字符串形式返回。
//
//
//提示：
//
//	1 <= num.length <= 30000
//	num 只包含 数字 且不含有 前导 0 。
//	1 <= k <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class BIT
{
public:
	BIT(int n) :t(vector<int>(n + 1, 0)) {}
	void originAdd(int index) //原数组索引为 index 的元素加 1
	{
		add(index + 1, 1);
	}
	int sumRight(int index) //返回原数组索引为 index 的元素的右侧和 [index + 1,end)
	{
		return ask(t.size() - 1) - ask(index + 1);
	}
private:
	vector<int> t;
	int lowbit(int x)
	{
		return x & (-x);
	}
	void add(int tIndex, int value) //原数组的第 tIndex 个元素值加 value （单点修改）
	{
		int n = t.size();
		while (tIndex < n)
		{
			t[tIndex] += value;
			tIndex += lowbit(tIndex);
		}
	}
	int ask(int tIndex) //计算原数组的前 tIndex 项和（查询前缀和）
	{
		int ret = 0;
		while (tIndex > 0)
		{
			ret += t[tIndex];
			tIndex -= lowbit(tIndex);
		}
		return ret;
	}
};


//贪心算法，暴力解法。算法正确但时间超时。
//时间复杂度 O(n^2)
//string minInteger(string num, int k)
//{
//	string ret;
//	int n = num.length();
//	int offset = 0;
//	int minOffset;
//	int minJ;
//	int j;
//	char currentMin;
//	int currentIndex = 0;
//	while (k > 0)
//	{
//		while (num[currentIndex] == ' ')
//		{
//			currentIndex++;
//		}
//		if (currentIndex == n)
//			break;
//		currentMin = num[currentIndex];
//		j = currentIndex + 1;
//		minJ = currentIndex;
//		offset = 0;
//		minOffset = 0;
//		while (offset < k && j < n) //找到最小的可交换数字
//		{
//			if (num[j] == ' ')
//			{
//				j++;
//				continue;
//			}
//			offset++;
//			if (num[j] < currentMin)
//			{
//				currentMin = num[j];
//				minJ = j;
//				minOffset = offset;
//			}
//			j++;
//		}
//		ret.push_back(num[minJ]);
//		num[minJ] = ' ';
//		k -= minOffset;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (num[i] != ' ')
//			ret.push_back(num[i]);
//	}
//	return ret;
//}


//贪心算法，树状数组。正序遍历原始字符串（即由最高位至最低位），对任一位置 i ，应将其后与其距离不大于 k 的最小元素交换至此。使用 posVec 队列数组记录原始字符串中可被交换的元素的初始位置集合，使用树状数组记录原始字符串中的哪些位置的元素已被移动至字符串前部；交换的任一时刻，对于判断位置 i ，正序遍历 posVec 队列数组，对于 posVec[x] 队列，其队首元素值与原始字符串中 i 位置后已被交换的数字个数之和为距离当前判断位置 i 最近的数值为 x 的元素的位置，若该位置与 i 的距离不大于当前剩余交换次数，则交换此元素(x)，并判断下一位置 i + 1 。
string minInteger(string num, int k)
{
	int n = num.length();
	BIT bit(n);
	vector<queue<int>> posVec(10);
	for (int i = 0; i < n; i++) //初始化 posVec 队列数组
		posVec[num[i] - '0'].push(i);

	string ret;
	int offset;
	for (int i = 0; i < n; i++) //遍历各判断位置
	{
		for (int j = 0; j < 10; j++) //找到满足交换距离限制的最小元素值
		{
			if (!posVec[j].empty())
			{
				offset = posVec[j].front() + bit.sumRight(posVec[j].front()) - i;
				if (offset <= k)
				{
					bit.originAdd(posVec[j].front());
					posVec[j].pop();
					k -= offset;
					ret.push_back(j + '0');
					break;
				}
			}
		}
	}
	return ret;
}


int main1505()
{
	//string test = "9438957234785635408";
	//string test = "4321";
	string test = "22";
	//string test = "36789";
	//string test = "100";
	string ret = minInteger(test, 22);
	cout << "main：ret = " << ret << endl;
	return 0;
}