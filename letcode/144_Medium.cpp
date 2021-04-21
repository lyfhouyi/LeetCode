#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//
//
//提示：
//
//	树中节点数目在范围[0, 100] 内
//	- 100 <= Node.val <= 100
//
//
//进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct TreeNode144 {
	int val;
	TreeNode144 *left;
	TreeNode144 *right;
	TreeNode144() : val(0), left(nullptr), right(nullptr) {}
	TreeNode144(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode144(int x, TreeNode144 *left, TreeNode144 *right) : val(x), left(left), right(right) {}
};


//将当前节点值尾插入结果；递归调用 myDLR 得到左节点的前序遍历；递归调用 myLDR 得到右节点的前序遍历。递归基：当前节点为空时，直接返回。
void myDLR(TreeNode144* root, vector<int>& vec)
{
	if (root == nullptr)
		return;
	vec.push_back(root->val);
	myDLR(root->left, vec);
	myDLR(root->right, vec);
}

//解法一：递归。
//vector<int> preorderTraversal(TreeNode144* root)
//{
//	vector<int> ret;
//	myDLR(root, ret);
//	return ret;
//}


//解法二：迭代。首先将跟节点压栈；随后将将栈中节点逐个弹出并输出元素值，输出元素值后，将当前节点的右节点及左节点压栈；当栈为空时，所有节点已遍历完毕。
vector<int> preorderTraversal(TreeNode144* root)
{
	vector<int> ret;
	stack<TreeNode144*> nodeStack;
	if (root != nullptr)
		nodeStack.push(root);
	TreeNode144* node;
	while (!nodeStack.empty())
	{
		node = nodeStack.top();
		ret.push_back(node->val);
		nodeStack.pop();
		if (node->right != nullptr)
			nodeStack.push(node->right);
		if(node->left != nullptr)
			nodeStack.push(node->left);
	}
	return ret;
}


int main()
{
	//TreeNode144* root = new TreeNode144(4);
	//root->left = new TreeNode144(2);
	//root->right = new TreeNode144(6);
	//root->left->left = new TreeNode144(1);
	//root->left->right = new TreeNode144(3);

	TreeNode144* root = new TreeNode144(7);
	root->left = new TreeNode144(4);
	root->right = new TreeNode144(9);
	root->right->left = new TreeNode144(37);
	root->right->left->left = new TreeNode144(36);
	root->right->right = new TreeNode144(46);
	root->left->left = new TreeNode144(2);
	root->left->right = new TreeNode144(6);
	root->left->left->left = new TreeNode144(1);
	root->left->left->right = new TreeNode144(3);
	root->left->right->left = new TreeNode144(5);
	root->left->right->left->left = new TreeNode144(28);

	vector<int> ret = preorderTraversal(root);

	cout << "main：ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;

	return 0;
}