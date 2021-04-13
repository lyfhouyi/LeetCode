#include<iostream>
#include<climits>

using namespace std;

//����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ�����������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
//
//
//��ʾ��
//
//	���������� 2 ���ڵ㡣
//	������ 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ ��ͬ
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct TreeNode530 {
	int val;
	TreeNode530 *left;
	TreeNode530 *right;
	TreeNode530() : val(0), left(nullptr), right(nullptr) {}
	TreeNode530(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode530(int x, TreeNode530 *left, TreeNode530 *right) : val(x), left(left), right(right) {}
};


void myInfixSearch_pro(TreeNode530* root, int& preValue, int& ret)
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


//�������������������Ĺ����У�ά��ǰ׺�ڵ�ֵ��ʹ��ǰ׺�ڵ�ֵ�����ֵ��Сֵ��
int getMinimumDifference(TreeNode530* root)
{
	int ret = INT_MAX;
	int preValue = -1;
	myInfixSearch_pro(root, preValue, ret);
	return ret;
}


int main530()
{
	TreeNode530* root = new TreeNode530(4);
	root->left = new TreeNode530(2);
	root->right = new TreeNode530(6);
	root->left->left = new TreeNode530(1);
	root->left->right = new TreeNode530(3);
	int ret = getMinimumDifference(root);
	cout << "main��ret = " << ret << endl;
	return 0;
}