#include<iostream>

using namespace std;

//给定二叉搜索树的根结点 root，返回值位于范围[low, high] 之间的所有结点的值的和。
//
//
//提示：
//
//	树中节点数目在范围[1, 2 * 10^4] 内
//	1 <= Node.val <= 10^5
//	1 <= low <= high <= 10^5
//	所有 Node.val 互不相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/range-sum-of-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct TreeNode938 {
	int val;
	TreeNode938 *left;
	TreeNode938 *right;
	TreeNode938() : val(0), left(nullptr), right(nullptr) {}
	TreeNode938(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode938(int x, TreeNode938 *left, TreeNode938 *right) : val(x), left(left), right(right) {}
};


//递归调用 myLDR 得到左子树满足要求的节点的和；将当前节点值累和（若满足要求）；递归调用 myLDR 得到右子树满足要求的节点的和。递归基：当前节点为空时，直接返回。
void myRangeSumLDR(TreeNode938* root, int low, int high, int& ret)
{
	if (root == nullptr)
		return;

	if (root->val > low) //左子树可能存在满足要求的节点
		myRangeSumLDR(root->left, low, high, ret);
	if (root->val >= low && root->val <= high)
		ret += root->val;
	if (root->val < high) //右子树可能存在满足要求的节点
		myRangeSumLDR(root->right, low, high, ret);
}


//递归。中序遍历，利用当前节点的值进行剪枝。若当前节点的值小于等于 low 则当前节点的左子树上所有节点的值必均小于 low（所有节点值互不相同），则无需访问左子树；若当前节点的值大于等于 high 则当前节点的右子树上所有节点的值必均大于 high（所有节点值互不相同），则无需访问右子树。
int rangeSumBST(TreeNode938* root, int low, int high)
{
	int ret = 0;
	myRangeSumLDR(root, low, high, ret);
	return ret;
}


int main938()
{
	TreeNode938* root = new TreeNode938(10);
	root->left = new TreeNode938(5);
	root->right = new TreeNode938(15);
	root->left->left = new TreeNode938(3);
	root->left->right = new TreeNode938(7);
	root->right->right = new TreeNode938(18);

	int ret = rangeSumBST(root, 7, 15);
	cout << "main：ret = " << ret << endl;
	return 0;
}