#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ�����ֱ��ͼ�ܴ����ˮ�� ? ֱ��ͼ�Ŀ��Ϊ 1��
//
//
//������������[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] ��ʾ��ֱ��ͼ������������£����Խ� 6 ����λ��ˮ����ɫ���ֱ�ʾˮ����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/volume-of-histogram-lcci
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//����ջ��ʹ��һ����������ջ�洢�п��ܳ�Ϊ��۵ķ�������ָ������������飬����ǰ����������ջ���������򽫵�ǰ����ѹջ�������ֲ��Ѽ���ˮλ���㣻����ǰ��������ջ���������������ջ��������ջ������ǰ�������ݻ������������¾ֲ��Ѽ���ˮλ��ֱ����ǰ����������ջ������ʱֹͣ��ջ��ѭ����ջ��������ʹ�õ�ǰջ���ٴμ��㵱ǰ������Ϊ�ұ�ʱ�Կ����ɵ�ˮ������󽫵�ǰ����ѹջ�������ֲ��Ѽ���ˮλ���㣻������Ϻ�ʢˮ�ݻ��ܺͼ�Ϊ����
int trapM1721(vector<int>& height)
{
	stack<int> leftIndexStack; //�п��ܳ�Ϊ��۵ķ���������
	int n = height.size();
	int sumVolume = 0;
	int sumLevel; //�ֲ��Ѽ���ˮλ
	for (int i = 0; i < n; i++)
	{
		sumLevel = 0;
		while (!leftIndexStack.empty() && height[i] > height[leftIndexStack.top()])
		{
			sumVolume += (i - leftIndexStack.top() - 1)*(height[leftIndexStack.top()] - sumLevel); //�ۼӵ�ǰջ����Ϊ��ۣ���ǰ������Ϊ�ұ�ʱ���ݻ�
			sumLevel = height[leftIndexStack.top()]; //���¾ֲ��Ѽ���ˮλ
			leftIndexStack.pop();
		}
		if (!leftIndexStack.empty())
			sumVolume += (i - leftIndexStack.top() - 1)*(height[i] - sumLevel); //�ۼӵ�ǰ�������һ�γ�Ϊ�ұ�ʱ���ݻ�
		leftIndexStack.push(i);
	}
	return sumVolume;
}


int mainM1721()
{
	vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1,1,1,2,3,1,1,3 };
	int ret = trapM1721(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}