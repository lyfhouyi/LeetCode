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
//vector<int> preorderTraversal(TreeNode144* root)
//{
//	vector<int> ret;
//	stack<TreeNode144*> nodeStack;
//	if (root != nullptr)
//		nodeStack.push(root);
//	TreeNode144* node;
//	while (!nodeStack.empty())
//	{
//		node = nodeStack.top();
//		ret.push_back(node->val);
//		nodeStack.pop();
//		if (node->right != nullptr)
//			nodeStack.push(node->right);
//		if (node->left != nullptr)
//			nodeStack.push(node->left);
//	}
//	return ret;
//}


//解法三：Morris 算法。对任意节点，使用其前缀节点的右指针的状态作为其左子树（前缀节点及其之前的节点）是否已被输出的标志（前缀节点的右指针为空时，说明左子树尚未被完全输出；前缀节点为空时，说明当前节点无左子树；前缀节点的右指针非空（若非空，则必等于当前节点）时，说明当前节点已是第二次被访问，因此当前节点的左子树必已被完全输出）。若当前节点无左子树则应输出当前节点，并将当前节点置为当前节点的右节点；若当前节点有左子树且左子树尚未被完全输出，则应输出当前节点，并将前缀节点的右节点置为当前节点，并将当前节点置为当前节点的左节点；若当前节点有左子树且左子树已被完全输出，则应将当前节点置为当前节点的右节点。
//vector<int> preorderTraversal(TreeNode144* root)
//{
//	vector<int> ret;
//	TreeNode144* node = root;
//	TreeNode144* preNode;
//	while (node != nullptr)
//	{
//		//找到当前节点的前缀节点
//		preNode = node->left;
//		while (preNode != nullptr && preNode->right != nullptr && preNode->right != node)
//			preNode = preNode->right;
//
//		if (preNode == nullptr) //当前节点无左子树
//		{
//			ret.push_back(node->val);
//			node = node->right;
//		}
//		else if (preNode->right == nullptr) //当前节点有左子树且左子树尚未被完全输出
//		{
//			ret.push_back(node->val);
//			preNode->right = node;
//			node = node->left;
//		}
//		else //当前节点有左子树且左子树已被完全输出
//		{
//			preNode->right = nullptr; //恢复树结构
//			node = node->right;
//		}
//	}
//	return ret;
//}


//解法四：迭代。首先将根节点及左枝节点依次输出元素值并压栈；随后将栈中节点逐个弹出，并将当前节点右枝节点及其左枝节点依次输出元素值并压栈；当栈为空时，所有节点已遍历完毕。
vector<int> preorderTraversal(TreeNode144* root)
{
	vector<int> ret;
	stack<TreeNode144*> nodeStack;
	TreeNode144* node = root;
	while (!nodeStack.empty() || node != nullptr)
	{
		while (node != nullptr)
		{
			ret.push_back(node->val);
			nodeStack.push(node);
			node = node->left;
		}
		node = nodeStack.top();
		nodeStack.pop();
		node = node->right;
	}
	return ret;
}


int main144()
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