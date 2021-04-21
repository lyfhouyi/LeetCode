#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��
//
//ע�⣺������ 530��https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ ��ͬ
//
//
//��ʾ��
//
//	���нڵ���Ŀ�ڷ�Χ[2, 100] ��
//	0 <= Node.val <= 10^5
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct TreeNode783 {
	int val;
	TreeNode783 *left;
	TreeNode783 *right;
	TreeNode783() : val(0), left(nullptr), right(nullptr) {}
	TreeNode783(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode783(int x, TreeNode783 *left, TreeNode783 *right) : val(x), left(left), right(right) {}
};


void myInfixSearch(TreeNode783* root, vector<int>& valueVec)
{
	if (root == nullptr)
		return;
	myInfixSearch(root->left, valueVec);
	valueVec.push_back(root->val);
	myInfixSearch(root->right, valueVec);
}


void myInfixSearch_pro(TreeNode783* root, int& preValue, int& ret)
{
	if (root == nullptr)
		return;
	myInfixSearch_pro(root->left, preValue, ret); //���ڵ��ǰ׺ֵ������ preValue
	if (preValue == -1)
		preValue = root->val;
	else
	{
		ret = root->val - preValue < ret ? root->val - preValue : ret;
		preValue = root->val;
	}
	myInfixSearch_pro(root->right, preValue, ret); //�Ҳ�ڵ��ǰ׺ֵ��ʼ�� root->val
}


//�������������ʹ����������������ԭ���ڵ������������飨������һ��������ģ��������������������һ�Σ������ֵ����Сֵ��
//int minDiffInBST(TreeNode783* root)
//{
//	vector<int> valueVec;
//	myInfixSearch(root, valueVec);
//	int n = valueVec.size();
//	int ret = INT_MAX;
//	for (int i = 0; i + 1 < n; i++)
//	{
//		ret = valueVec[i + 1] - valueVec[i] < ret ? valueVec[i + 1] - valueVec[i] : ret;
//	}
//	return ret;
//}


//�Ż�������������Ĺ����У�ά��ǰ׺�ڵ�ֵ��ʹ��ǰ׺�ڵ�ֵ�����ֵ��Сֵ��
int minDiffInBST(TreeNode783* root)
{
	int ret = INT_MAX;
	int preValue = -1;
	myInfixSearch_pro(root, preValue, ret);
	return ret;
}

int main783()
{
	TreeNode783* root = new TreeNode783(4);
	root->left = new TreeNode783(2);
	root->right = new TreeNode783(6);
	root->left->left = new TreeNode783(1);
	root->left->right = new TreeNode783(3);
	int ret = minDiffInBST(root);
	cout << "main��ret = " << ret << endl;
	return 0;
}