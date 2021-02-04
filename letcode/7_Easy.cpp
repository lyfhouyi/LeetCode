#include<iostream>
#include<queue>

using namespace std;

//给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围 [−2^31, 2^31 − 1] ，就返回 0。
//
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
//
//提示：
//
//	- 2^31 <= x <= 2^31 - 1
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-integer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//使用队列由低位至高位依次记录各位数值。
//int reverse(int x)
//{
//	queue<int> digitQueue;
//	int tmp;
//
//	//逐位入队
//	while (x != 0)
//	{
//		digitQueue.push(x % 10);
//		x /= 10;
//	}
//
//	//逐位出队
//	int ret = 0;
//	while (!digitQueue.empty())
//	{
//		tmp = abs(ret);
//		if (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && digitQueue.front() > 7)) //判断溢出
//			return 0;
//		ret = 10* ret+ digitQueue.front();
//		digitQueue.pop();
//	}
//	return ret;
//}


//优化版。可以不使用队列，直接逐位反转
int reverse(int x)
{
	int ret = 0;
	int tmp;

	//逐位反转
	while (x != 0)
	{
		tmp = abs(ret);
		if (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && x % 10 > 7)) //判断溢出
			return 0;
		ret = 10 * ret + x % 10;
		x /= 10;
	}

	return ret;
}


int main7()
{
	//int ret = reverse(INT_MAX - 2929);
	//int ret = reverse(INT_MIN + 2929);
	int ret = reverse(-120);
	cout << "main：ret = " << ret << endl;
	return 0;
}