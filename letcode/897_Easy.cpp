#include<iostream>
#include<stack>

using namespace std;

//给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
//
//
//提示：
//
//	树中节点数的取值范围是[1, 100]
//	0 <= Node.val <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/increasing-order-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct TreeNode897 {
	int val;
	TreeNode897 *left;
	TreeNode897 *right;
	TreeNode897() : val(0), left(nullptr), right(nullptr) {}
	TreeNode897(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode897(int x, TreeNode897 *left, TreeNode897 *right) : val(x), left(left), right(right) {}
};


//解法一：栈。使用栈对原二叉树进行中序遍历，使用 preNode 指针将上一输出节点的右指针指向当前节点，将当前节点的左指针置空。
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
//		//调整上一输出节点指针
//		if (preNode == nullptr)
//		{
//			preNode = node;
//			ret = preNode;
//		}
//		else //此时 nextNode 指向上一输出节点，node 为当前输出节点
//		{
//			preNode->right = node; //将上一输出节点的右指针指向当前节点
//			preNode = node;
//		}
//		node->left = nullptr; //将当前节点的左指针置空
//		node = node->right;
//	}
//	return ret;
//}


//解法二：Morris 算法。使用 Morris 算法对原二叉树进行中序遍历。若当前节点无左子树，此时 preNode 必指向其中序遍历的前缀节点（因为 preNode 指针永远指向上一个被输出的节点），则将 preNode 的右指针指向当前节点，并将 preNode 置为当前节点（因为当前节点此时可以被输出）；若当前节点有左子树且左子树已被访问，则将当前节点的左指针置空，并将 preNode 指针指向当前节点（因为当前节点此时可以被输出）；若当前节点有左子树且左子树未被访问，则将其前缀指针的右指针指向该节点。
TreeNode897* increasingBST(TreeNode897* root)
{
	TreeNode897* node = root;
	TreeNode897* ret = nullptr;
	TreeNode897* preNode = nullptr; //永远指向上一个被输出的节点
	TreeNode897* prefixNode; //当前节点的前缀节点
	while (node != nullptr)
	{
		//找到当前节点的前缀节点
		prefixNode = node->left;
		while (prefixNode != nullptr && prefixNode->right != nullptr && prefixNode->right != node)
			prefixNode = prefixNode->right;

		if (prefixNode == nullptr) //当前节点无左子树
		{
			if (preNode == nullptr)
			{
				preNode = node;
				ret = preNode;
			}
			else //此时 preNode 指向上一个被输出的节点
				preNode->right = node;
			preNode = node; //调整 preNode 指针的指向，当前节点此时可以被输出
			node = node->right;
		}
		else if (prefixNode->right == node) //当前节点有左子树且左子树已被访问
		{
			node->left = nullptr; //将当前节点的左指针置空
			preNode = node; //调整 preNode 指针的指向，当前节点此时可以被输出
			node = node->right;
		}
		else //当前节点有左子树且左子树未被访问
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
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		if (ret->left != nullptr)
			cout << "main：error! ret->val = " << ret->val;
		cout << ret->val << "  ";
		ret = ret->right;
	}
	cout << endl;
	return 0;
}