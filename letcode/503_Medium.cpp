#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء����� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ - 1��
//
//
//ע�� : ��������ĳ��Ȳ��ᳬ�� 10000��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/next-greater-element-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ݼ�ջ����ָ��ѭ���������飬ʹ��һ���ݼ�ջά����ǰָ��֮ǰ����δ�ҵ�����Ԫ�ص�Ԫ�ص�λ������������ǰָ���Ԫ�ش���ջ��Ԫ�أ�˵��ջ��Ԫ�����ҵ�λ������ұ��������Ԫ�أ�����¸�λ�ò�����ջ�����������˹��򵯳�ջ��Ԫ�أ�ֱ��ջ��Ԫ�ش��ڻ���ڵ�ǰԪ�غ󣬽���ǰԪ��ѹջ����ѭ��������һԪ�أ���ѭ������ָ�����ƶ�һ�����ƶ�����ǰջ��Ԫ�ص�λ�ã�˵��ȫ��Ԫ���Ѵ�����ϣ���ʱջ��Ԫ�ؾ�Ϊ���ֵԪ�أ����䷵��ֵ��Ϊ -1 ���ɡ�
vector<int> nextGreaterElements(vector<int>& nums)
{
	int n = nums.size();
	int i = 0;
	int bottom;
	bool isRound = false;
	stack<int> undeterminedElements;
	vector<int> ret(n, -1);
	while (i < n) //������Ԫ��
	{
		while (!undeterminedElements.empty() && nums[undeterminedElements.top()] < nums[i]) //���¸�λ�ò�����ջ��
		{
			ret[undeterminedElements.top()] = nums[i];
			undeterminedElements.pop();
		}
		if (-1 == ret[i]) //�Ѵ������Ԫ����������ջ
		{
			if (undeterminedElements.empty()) //ʵʱ��¼ջ�׵�Ԫ������
				bottom = i;
			undeterminedElements.push(i);
		}
		if (isRound && bottom == i) //��ʱջ�е�Ԫ�ؾ������Ϊԭ��������ֵԪ��
			break;
		i++;
		if (i >= n)
		{
			isRound = true;
			i -= n;
		}
	}
	return ret;
}


int main503()
{
	//vector<int> test = { 1,2,1 };
	//vector<int> test = { -1,-2,-1,2,2,1,1 };
	//vector<int> test = { 5,3,9,1,2,4,0,3,7,9,6,2,4 };
	vector<int> test = { 5,3,9,1,2,4,0,3,7,9 };
	//vector<int> test = { 5,3,9,1,2,4,2,0,1,3,7,6,2,4 };
	vector<int> ret = nextGreaterElements(test);
	cout << "main��ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}