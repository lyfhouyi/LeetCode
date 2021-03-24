#include<iostream>
#include<string>

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

//算法正确但时间超时。
//时间复杂度 O(n^2)
string minInteger(string num, int k)
{
	string ret;
	int n = num.length();
	int offset = 0;
	int minOffset;
	int minJ;
	int j;
	char currentMin;
	int currentIndex = 0;
	while (k > 0)
	{
		while (num[currentIndex] == ' ')
		{
			currentIndex++;
		}
		if (currentIndex == n)
			break;
		currentMin = num[currentIndex];
		j = currentIndex + 1;
		minJ = currentIndex;
		offset = 0;
		minOffset = 0;
		while (offset < k && j < n) //找到最小的可交换数字
		{
			if (num[j] == ' ')
			{
				j++;
				continue;
			}
			offset++;
			if (num[j] < currentMin)
			{
				currentMin = num[j];
				minJ = j;
				minOffset = offset;
			}
			j++;
		}
		ret.push_back(num[minJ]);
		num[minJ] = ' ';
		k -= minOffset;
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] != ' ')
			ret.push_back(num[i]);
	}
	return ret;
}


//未通过。自己的算法时间复杂度 O(n^2) 会超时；官解算法的时间复杂度 O(nlogn) 可以通过，但需使用线段树数据结构，该数据结构尚未掌握。 
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