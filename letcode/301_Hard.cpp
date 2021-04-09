#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

//����һ�����������ź���ĸ��ɵ��ַ��� s ��ɾ����С��������Ч���ţ�ʹ��������ַ�����Ч��
//
//�������п��ܵĽ�����𰸿��԰� ����˳�� ���ء�
//
//
//��ʾ��
//
//	1 <= s.length <= 25
//	s ��СдӢ����ĸ�Լ����� '(' �� ')' ���
//	s �����ຬ 20 ������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-invalid-parentheses
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


 //�ж��ַ����Ƿ���Ч��
bool isValid(const string &s)
{
	int leftBracketCnt = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			leftBracketCnt++;
		else if (s[i] == ')')
			leftBracketCnt--;
		if (leftBracketCnt < 0)
			return false;
	}
	if (leftBracketCnt != 0)
		return false;
	return true;
}

//�ⷨһ�������㷨���������ж��Ƿ�Ӧ�� s �е���һ�����ż�������� currentS �������ڼ��� s �е���һ�����źͲ����� s �е���һ�����ţ��ݹ��������ǰ�ж�λ�õ��� s ��ĩβʱ���жϵ�ǰ�ַ����������⣩ currentS �Ƿ���Ч������Ч�ҳ��ȱ� sSet �����е��ַ������������� currentS �ַ������ sSet ���ϣ���������ǰ�ַ�����
//void findValidParentheses(unordered_set<string>& sSet, const string& s, int index, string currentS)
//{
//	if (index == s.length())
//	{
//		if (isValid(currentS))
//		{
//			if (sSet.empty())
//				sSet.insert(currentS);
//			else
//			{
//				if (sSet.begin()->length() < currentS.length())
//				{
//					sSet.clear();
//					sSet.insert(currentS);
//				}
//				else if (sSet.begin()->length() == currentS.length())
//					sSet.insert(currentS);
//			}
//		}
//		return;
//	}
//
//	if (s[index] == '(' || s[index] == ')')
//		findValidParentheses(sSet, s, index + 1, currentS);
//	findValidParentheses(sSet, s, index + 1, currentS + s[index]);
//}


//�ⷨһ���ݹ顣�ݹ���� findValidParentheses() �������������ж��Ƿ�Ӧ�� s �е���һ�����ż�������⼯�ϡ�
//vector<string> removeInvalidParentheses(string s)
//{
//	unordered_set<string> sSet;
//	string currentS = "";
//	findValidParentheses(sSet, s, 0, currentS);
//	vector<string> ret(sSet.begin(), sSet.end());
//	return ret;
//}


//�ⷨ���������㷨���������ж��Ƿ�Ӧ�� s �е���һ�����ż�������� currentS �������ڼ��� s �е���һ�����źͲ����� s �е���һ�����ţ��ݹ��������ǰ�ж�λ�õ��� s ��ĩβʱ���жϵ�ǰ�ַ����������⣩ currentS �Ƿ���Ч������Ч�ҳ��ȱ� sSet �����е��ַ������������� currentS �ַ������ sSet ���ϣ���������ǰ�ַ�����
void findValidParentheses(unordered_set<string>& sSet, const string& s, int index, string currentS, int leftBracketCnt, int rightBracketCnt)
{
	if (index == s.length())
	{
		if (leftBracketCnt == 0 && rightBracketCnt == 0 && isValid(currentS))
			sSet.insert(currentS);
		return;
	}

	if (s[index] == '(' && leftBracketCnt > 0)
		findValidParentheses(sSet, s, index + 1, currentS, leftBracketCnt - 1, rightBracketCnt);
	else if (s[index] == ')' && rightBracketCnt > 0)
		findValidParentheses(sSet, s, index + 1, currentS, leftBracketCnt, rightBracketCnt - 1);
	findValidParentheses(sSet, s, index + 1, currentS + s[index], leftBracketCnt, rightBracketCnt);
}


//�ⷨ�����ݹ顣�ݹ���� findValidParentheses() �������������ж��Ƿ�Ӧ�� s �е���һ�����ż�������⼯�ϡ�
vector<string> removeInvalidParentheses(string s)
{
	//����������������
	int leftBracketCnt = 0; //�����Ŷ��������
	int rightBracketCnt = 0; //�����Ŷ��������
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it == '(')
			leftBracketCnt++;
		else if (*it == ')')
			leftBracketCnt--;
		if (leftBracketCnt < 0)
		{
			leftBracketCnt = 0;
			rightBracketCnt++;
		}
	}

	unordered_set<string> sSet;
	string currentS = "";
	findValidParentheses(sSet, s, 0, currentS, leftBracketCnt, rightBracketCnt);
	vector<string> ret(sSet.begin(), sSet.end());
	return ret;
}


int main301()
{
	//string test = "()()";
	string test = ")(n";
	//string test = "(a)())()";
	vector<string> ret = removeInvalidParentheses(test);
	cout << "main��ret = [";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}