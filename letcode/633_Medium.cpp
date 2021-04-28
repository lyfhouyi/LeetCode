#include<iostream>

using namespace std;

//给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
//
//
//提示：
//
//	0 <= c <= 2^31 - 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sum-of-square-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴力解法。逐项遍历整数 a ，判断其是否满足要求。
//bool judgeSquareSum(int c)
//{
//	for (int a = 0; a*a <= c / 2; a++)
//	{
//		int b2 = c - a * a;
//		if (sqrt(b2) == (int)sqrt(b2))
//			return true;
//	}
//	return false;
//}


//解法二：双指针。使用双指针分别指向候选的整数 a、b ；若当前平方和小于 c ，则将 a++ ；若当前平方和大于 c ，则将 b-- ；若当前平方和等于 c ，则找到答案。双指针分别从 [0,sqrt(c)] 开始向中间靠拢，直到 a > b 时退出循环。
bool judgeSquareSum(int c)
{
	long a = 0;
	long b = sqrt(c);
	while (a <= b)
	{
		if (a * a + b * b < c)
			a++;
		else if (a * a + b * b > c)
			b--;
		else
			return true;
	}
	return false;
}

int main633()
{
	bool ret = judgeSquareSum(4);
	cout << "main：ret = " << ret << endl;
	return 0;
}