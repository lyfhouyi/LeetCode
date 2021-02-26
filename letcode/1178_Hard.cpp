#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>

using namespace std;

//������˷����й����������һ��Ӣ�İ������С��Ϸ���������²¿��ɡ�
//
//���յ����� puzzle ���ַ�����ʽ���������һ������ word ��������������������ô���Ϳ��������յף�
//
//	���� word �а������� puzzle �ĵ�һ����ĸ��
//	���� word �е�ÿһ����ĸ������������ puzzle ���ҵ���
//
//����һ�������� answer�������е�ÿ��Ԫ�� answer[i] ���ڸ����ĵ����б� words �п�����Ϊ�������� puzzles[i] ����Ӧ���յ׵ĵ�����Ŀ��
//
//
//��ʾ��
//
//	1 <= words.length <= 10 ^ 5
//	4 <= words[i].length <= 50
//	1 <= puzzles.length <= 10 ^ 4
//	puzzles[i].length == 7
//	words[i][j], puzzles[i][j] ����СдӢ����ĸ��
//	ÿ�� puzzles[i] ���������ַ������ظ���
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����ⷨ������ͨ����ĸ���鹹���յ�λ���飻������������桢�յף����������λ��ʾ�������Ӧ���յ�������
//�㷨��ȷ����ʱ�䳬ʱ��
//vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
//{
//	int m = words.size();
//	int n = puzzles.size();
//
//	//������ĸ����
//	vector<int> alphabetDict(26);
//	for (int i = 0; i < 26; i++)
//		alphabetDict[i] = pow(2, 25 - i);
//
//	//�����յ�λ����
//	vector<int> wordBitVec(m);
//	for (int i = 0; i < m; i++)
//	{
//		int len = words[i].size();
//		for (int j = 0; j < len; j++)
//		{
//			wordBitVec[i] |= alphabetDict[words[i][j] - 'a'];
//		}
//	}
//
//	//��������λ���鲢�������Ӧ���յ�����
//	vector<int> ret(n);
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		int len = puzzles[i].size();
//		for (int j = 0; j < len; j++) //���������λ��ʾ
//		{
//			tmp |= alphabetDict[puzzles[i][j] - 'a'];
//		}
//		for (int wIndex = 0; wIndex < m; wIndex++)
//		{
//			if ((0 == (~tmp & wordBitVec[wIndex])) && ((alphabetDict[puzzles[i][0] - 'a'] & wordBitVec[wIndex]) != 0))
//				ret[i]++;
//		}
//	}
//	return ret;
//}


//�����ⷨ���Ż��档�յװ�����ĸ�ļ��ϱ������������ĸ�ļ��ϵ��Ӽ����Ҹ��Ӽ��бذ������������ĸ�����ȹ����յ������ֵ䣻�����������棬ö�ٸ�������������ĸ��ȫ���Ӽ��������յ������ֵ������Ӽ����յ��е�������
//�Ż�һ�������յס������λ��ʾʱʹ����λ���������ĸ���飻�Ż�����������Ŀ�� puzzles[i].length == 7 �����ԣ�ʹ��������Ӽ�����ģ��С�����ٲ������Ӧ���յ�������
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
{
	int m = words.size();
	int n = puzzles.size();

	//�����յ�λ����
	unordered_map<int, int> wordCntMap;
	for (int i = 0; i < m; i++)
	{
		int wordBit = 0; //�յ׵�λ��ʾ
		int len = words[i].size();
		for (int j = 0; j < len; j++)
		{
			wordBit |= 1 << (words[i][j] - 'a');
		}
		wordCntMap[wordBit]++;
		//cout << bitset<26>(wordBit);
		//cout << endl;
	}

	//��������λ���鲢�������Ӧ���յ�����
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
	{
		int puzzleBit = 0; //�����λ��ʾ
		int len = puzzles[i].size();
		for (int j = 1; j < len; j++) //���������λ��ʾ
		{
			puzzleBit |= (1 << (puzzles[i][j] - 'a'));
		}

		//ö�������ȫ���Ӽ�
		int initial = 1 << (puzzles[i][0] - 'a'); //���������ĸ
		int subSet = puzzleBit; //������Ӽ�
		int s; //�����������ĸ���Ӽ�
		while (subSet != 0)
		{
			s = subSet | initial;
			if (wordCntMap.count(s) == 1)
				ret[i] += wordCntMap.at(s);
			subSet = (subSet - 1) & puzzleBit;
		}
		if (wordCntMap.count(initial) == 1)
			ret[i] += wordCntMap.at(initial);
	}
	return ret;
}


int main1178()
{
	vector<string> words = { "aaaa","asas","able","ability","actt","actor","access" };
	vector<string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
	vector<int> ret = findNumOfValidWords(words, puzzles);
	cout << "main��ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}