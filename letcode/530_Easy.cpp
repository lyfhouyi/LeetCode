#include<iostream>
#include<climits>

using namespace std;

//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//提示：
//
//	树中至少有 2 个节点。
//	本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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
	myInfixSearch_pro(root->left, preValue, ret); //左侧节点的前缀值依旧是 preValue
	if (preValue == -1)
		preValue = root->val;
	else
	{
		ret = root->val - preValue < ret ? root->val - preValue : ret;
		preValue = root->val;
	}
	myInfixSearch_pro(root->right, preValue, ret); //右侧节点的前缀值初始是 root->val
}


//中序遍历。在中序遍历的过程中，维护前缀节点值并使用前缀节点值计算差值最小值。
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
	cout << "main：ret = " << ret << endl;
	return 0;
}