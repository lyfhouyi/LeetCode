#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
//
//
//提示：
//
//	树中节点数目在范围[0, 100] 内
//	- 100 <= Node.val <= 100
//
//
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct TreeNode94 {
	int val;
	TreeNode94 *left;
	TreeNode94 *right;
	TreeNode94() : val(0), left(nullptr), right(nullptr) {}
	TreeNode94(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode94(int x, TreeNode94 *left, TreeNode94 *right) : val(x), left(left), right(right) {}
};


//递归调用 myLDR 得到左节点的中序遍历；将当前节点值尾插入结果；递归调用 myLDR 得到右节点的中序遍历。递归基：当前节点为空时，直接返回。
void myLDR(TreeNode94* root, vector<int>& vec)
{
	if (root == nullptr)
		return;
	myLDR(root->left, vec);
	vec.push_back(root->val);
	myLDR(root->right, vec);
}

//解法一：递归。
//vector<int> inorderTraversal(TreeNode94* root)
//{
//	vector<int> ret;
//	myLDR(root, ret);
//	return ret;
//}


//解法二：迭代。首先将根节点及左枝节点依次压栈；随后将栈中节点逐个弹出并输出元素值，输出元素值后，将当前节点右枝节点及其左枝节点依次压栈；当栈为空时，所有节点已遍历完毕。
//vector<int> inorderTraversal(TreeNode94* root)
//{
//	vector<int> ret;
//	stack<TreeNode94*> nodeStack;
//	TreeNode94* node = root;
//	while (node != nullptr) //将根节点及左枝节点依次压栈
//	{
//		nodeStack.push(node);
//		node = node->left;
//	}
//	while (!nodeStack.empty())
//	{
//		node = nodeStack.top();
//		nodeStack.pop();
//		ret.push_back(node->val);
//		node = node->right;
//		while (node != nullptr) //将当前节点右枝节点及其左枝节点依次压栈
//		{
//			nodeStack.push(node);
//			node = node->left;
//		}
//	}
//	return ret;
//}


//解法二，代码优化：迭代。首先将根节点及左枝节点依次压栈；随后将栈中节点逐个弹出并输出元素值，输出元素值后，将当前节点右枝节点及其左枝节点依次压栈；当栈为空时，所有节点已遍历完毕。
vector<int> inorderTraversal(TreeNode94* root)
{
	vector<int> ret;
	stack<TreeNode94*> nodeStack;
	TreeNode94* node = root;
	while (!nodeStack.empty() || node != nullptr)
	{
		while (node != nullptr) //将当前节点及其左枝节点依次压栈（当前节点的左枝节点的右枝节点会在该节点出栈后的压栈阶段压入栈中）
		{
			nodeStack.push(node);
			node = node->left;
		}
		node = nodeStack.top();
		nodeStack.pop();
		ret.push_back(node->val);
		node = node->right;
	}
	return ret;
}
Morris

//解法三：Morris 算法。对任意节点，使用其前缀节点的右指针的状态作为其左子树（前缀节点及其之前的节点）是否已被输出的标志（前缀节点的右指针为空时，说明左子树尚未被完全输出；前缀节点的右指针非空时，说明当前节点已是第二次被访问，因此当前节点的左子树必已被完全输出）。若当前节点的左子树已被输出，则应输出当前节点，并将当前节点置为当前节点的右节点；若当前节点的左子树尚未被完全输出，则应将当前节点置为当前节点的左节点。
vector<int> inorderTraversal(TreeNode94* root)
{
	vector<int> ret;
	stack<TreeNode94*> nodeStack;
	TreeNode94* node = root;
	while (!nodeStack.empty() || node != nullptr)
	{
		while (node != nullptr) //将当前节点及其左枝节点依次压栈（当前节点的左枝节点的右枝节点会在该节点出栈后的压栈阶段压入栈中）
		{
			nodeStack.push(node);
			node = node->left;
		}
		node = nodeStack.top();
		nodeStack.pop();
		ret.push_back(node->val);
		node = node->right;
	}
	return ret;
}


int main()
{
	//TreeNode94* root = new TreeNode94(4);
	//root->left = new TreeNode94(2);
	//root->right = new TreeNode94(6);
	//root->left->left = new TreeNode94(1);
	//root->left->right = new TreeNode94(3);

	TreeNode94* root = new TreeNode94(7);
	root->left = new TreeNode94(4);
	root->right = new TreeNode94(9);
	root->right->left = new TreeNode94(37);
	root->right->left->left = new TreeNode94(36);
	root->right->right = new TreeNode94(46);
	root->left->left = new TreeNode94(2);
	root->left->right = new TreeNode94(6);
	root->left->left->left = new TreeNode94(1);
	root->left->left->right = new TreeNode94(3);
	root->left->right->left = new TreeNode94(5);
	root->left->right->left->left = new TreeNode94(28);

	vector<int> ret = inorderTraversal(root);

	cout << "main：ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;

	return 0;
}