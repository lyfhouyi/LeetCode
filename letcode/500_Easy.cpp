#include<iostream>
#include<vector>
#include<string>

using namespace std;

//����һ���ַ������� words ��ֻ���ؿ���ʹ���� ��ʽ���� ͬһ�е���ĸ��ӡ�����ĵ��ʡ���������ͼ��ʾ��
//
//��ʽ���� �У�
//
//	��һ�����ַ� "qwertyuiop" ��ɡ�
//	�ڶ������ַ� "asdfghjkl" ��ɡ�
//	���������ַ� "zxcvbnm" ��ɡ�
//
//
//��ʾ��
//
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] ��Ӣ����ĸ��Сд�ʹ�д��ĸ�����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/keyboard-row
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//����������ͨ����ĸ�������ֵ��жϵ����е���ĸ�Ƿ�����ͬһ�����С�
vector<string> findWords(vector<string>& words)
{
	//������ĸ�������ֵ�
	vector<int> lineMap(26);
	lineMap[0] = 2;
	lineMap[1] = 3;
	lineMap[2] = 3;
	lineMap[3] = 2;
	lineMap[4] = 1;
	lineMap[5] = 2;
	lineMap[6] = 2;
	lineMap[7] = 2;
	lineMap[8] = 1;
	lineMap[9] = 2;
	lineMap[10] = 2;
	lineMap[11] = 2;
	lineMap[12] = 3;
	lineMap[13] = 3;
	lineMap[14] = 1;
	lineMap[15] = 1;
	lineMap[16] = 1;
	lineMap[17] = 1;
	lineMap[18] = 2;
	lineMap[19] = 1;
	lineMap[20] = 1;
	lineMap[21] = 3;
	lineMap[22] = 1;
	lineMap[23] = 3;
	lineMap[24] = 1;
	lineMap[25] = 3;

	vector<string> ret;
	int n = words.size();
	int currentLine;
	int len;
	bool isValid;
	char tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = words[i][0] >= 97 ? words[i][0] - 32 : words[i][0];
		currentLine = lineMap[tmp - 'A'];
		isValid = true;
		len = words[i].size();
		for (int j = 1; j < len; j++)
		{
			tmp = words[i][j] >= 97 ? words[i][j] - 32 : words[i][j];
			if (lineMap[tmp - 'A'] != currentLine)
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
			ret.push_back(words[i]);
	}
	return ret;
}


int main500()
{
	vector <string> test = { "Hello","Alaska","Dad","Peace" };
	vector<string> ret = findWords(test);
	cout << "main��ret = [";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}