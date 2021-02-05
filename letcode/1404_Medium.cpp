#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：
//
//如果当前数字为偶数，则将其除以 2 。
//
//如果当前数字为奇数，则将其加上 1 。
//
//题目保证你总是可以按上述规则将测试用例变为 1 。
//
//
//提示：
//
//	1 <= s.length  <= 500
//	s 由字符 '0' 或 '1' 组成。
//	s[0] == '1'
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针反向遍历字符串。根据当前数位的值和进位情况，确定处理当前位所需的步骤数及处理后的进位情况。
int numSteps(string s) {
	int value = 0;
	int n = s.size();
	int stepCnt = 0;
	bool carryBit = false;

	//处理最低位至次高位
	for (int i = n - 1; i > 0; i--)
	{
		if (carryBit)
			stepCnt += (s[i] == '0' ? 2 : 1);
		else
		{
			stepCnt += (s[i] == '0' ? 1 : 2);
			if (s[i] == '1')
				carryBit = true;
		}
	}

	//处理最高位
	if (carryBit)
		stepCnt++;
	return stepCnt;
}


int main1404()
{
	string test = "1";
	int ret = numSteps(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}