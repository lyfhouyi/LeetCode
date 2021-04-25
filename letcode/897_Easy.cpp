#include<iostream>
#include<stack>

using namespace std;

//����һ�ö��������������� ��������� ������������Ϊһ�õ���˳����������ʹ��������ߵĽڵ��Ϊ���ĸ��ڵ㣬����ÿ���ڵ�û�����ӽڵ㣬ֻ��һ�����ӽڵ㡣
//
//
//��ʾ��
//
//	���нڵ�����ȡֵ��Χ��[1, 100]
//	0 <= Node.val <= 1000
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/increasing-order-search-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct TreeNode897 {
	int val;
	TreeNode897 *left;
	TreeNode897 *right;
	TreeNode897() : val(0), left(nullptr), right(nullptr) {}
	TreeNode897(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode897(int x, TreeNode897 *left, TreeNode897 *right) : val(x), left(left), right(right) {}
};


//�ⷨһ��ջ��ʹ��ջ��ԭ�������������������ʹ�� preNode ָ�뽫��һ����ڵ����ָ��ָ��ǰ�ڵ㣬����ǰ�ڵ����ָ���ÿա�
//TreeNode897* increasingBST(TreeNode897* root)
//{
//	stack<TreeNode897*> nodeStack;
//	TreeNode897* node = root;
//	TreeNode897* ret = nullptr;
//	TreeNode897* preNode = nullptr;
//	while (!nodeStack.empty() || node != nullptr)
//	{
//		while (node != nullptr)
//		{
//			nodeStack.push(node);
//			node = node->left;
//		}
//		node = nodeStack.top();
//		nodeStack.pop();
//
//		//������һ����ڵ�ָ��
//		if (preNode == nullptr)
//		{
//			preNode = node;
//			ret = preNode;
//		}
//		else //��ʱ nextNode ָ����һ����ڵ㣬node Ϊ��ǰ����ڵ�
//		{
//			preNode->right = node; //����һ����ڵ����ָ��ָ��ǰ�ڵ�
//			preNode = node;
//		}
//		node->left = nullptr; //����ǰ�ڵ����ָ���ÿ�
//		node = node->right;
//	}
//	return ret;
//}


//�ⷨ����Morris �㷨��ʹ�� Morris �㷨��ԭ�����������������������ǰ�ڵ�������������ʱ preNode ��ָ�������������ǰ׺�ڵ㣨��Ϊ preNode ָ����Զָ����һ��������Ľڵ㣩���� preNode ����ָ��ָ��ǰ�ڵ㣬���� preNode ��Ϊ��ǰ�ڵ㣨��Ϊ��ǰ�ڵ��ʱ���Ա������������ǰ�ڵ������������������ѱ����ʣ��򽫵�ǰ�ڵ����ָ���ÿգ����� preNode ָ��ָ��ǰ�ڵ㣨��Ϊ��ǰ�ڵ��ʱ���Ա������������ǰ�ڵ�����������������δ�����ʣ�����ǰ׺ָ�����ָ��ָ��ýڵ㡣
TreeNode897* increasingBST(TreeNode897* root)
{
	TreeNode897* node = root;
	TreeNode897* ret = nullptr;
	TreeNode897* preNode = nullptr; //��Զָ����һ��������Ľڵ�
	TreeNode897* prefixNode; //��ǰ�ڵ��ǰ׺�ڵ�
	while (node != nullptr)
	{
		//�ҵ���ǰ�ڵ��ǰ׺�ڵ�
		prefixNode = node->left;
		while (prefixNode != nullptr && prefixNode->right != nullptr && prefixNode->right != node)
			prefixNode = prefixNode->right;

		if (prefixNode == nullptr) //��ǰ�ڵ���������
		{
			if (preNode == nullptr)
			{
				preNode = node;
				ret = preNode;
			}
			else //��ʱ preNode ָ����һ��������Ľڵ�
				preNode->right = node;
			preNode = node; //���� preNode ָ���ָ�򣬵�ǰ�ڵ��ʱ���Ա����
			node = node->right;
		}
		else if (prefixNode->right == node) //��ǰ�ڵ������������������ѱ�����
		{
			node->left = nullptr; //����ǰ�ڵ����ָ���ÿ�
			preNode = node; //���� preNode ָ���ָ�򣬵�ǰ�ڵ��ʱ���Ա����
			node = node->right;
		}
		else //��ǰ�ڵ�����������������δ������
		{
			prefixNode->right = node;
			node = node->left;
		}
	}
	return ret;
}


int main897()
{
	//TreeNode897* root = new TreeNode897(4);
	//root->left = new TreeNode897(2);
	//root->right = new TreeNode897(6);
	//root->left->left = new TreeNode897(1);
	//root->left->right = new TreeNode897(3);

	//TreeNode897* root = new TreeNode897(7);
	//root->left = new TreeNode897(4);
	//root->right = new TreeNode897(9);
	//root->right->left = new TreeNode897(37);
	//root->right->left->left = new TreeNode897(36);
	//root->right->right = new TreeNode897(46);
	//root->left->left = new TreeNode897(2);
	//root->left->right = new TreeNode897(6);
	//root->left->left->left = new TreeNode897(1);
	//root->left->left->right = new TreeNode897(3);
	//root->left->right->left = new TreeNode897(5);
	//root->left->right->left->left = new TreeNode897(28);

	//TreeNode897* root = new TreeNode897(2);
	//root->left = new TreeNode897(1);
	//root->right = new TreeNode897(4);
	//root->right->left = new TreeNode897(3);

	TreeNode897* root = new TreeNode897(5);
	root->left = new TreeNode897(3);
	root->right = new TreeNode897(6);
	root->left->left = new TreeNode897(2);
	root->left->left->left = new TreeNode897(1);
	root->left->right = new TreeNode897(4);
	root->right->right = new TreeNode897(8);
	root->right->right->left = new TreeNode897(7);
	root->right->right->right = new TreeNode897(9);


	TreeNode897* ret = increasingBST(root);
	cout << "main��ret = ";
	while (ret != nullptr)
	{
		if (ret->left != nullptr)
			cout << "main��error! ret->val = " << ret->val;
		cout << ret->val << "  ";
		ret = ret->right;
	}
	cout << endl;
	return 0;
}