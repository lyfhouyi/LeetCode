#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//
//注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同
//
//
//提示：
//
//	树中节点数目在范围[2, 100] 内
//	0 <= Node.val <= 10^5
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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


//中序遍历。首先使用深度优先搜索求出原根节点的中序遍历数组（该数组一定是升序的）；随后遍历中序遍历数组一次，计算差值的最小值。
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


//优化。在中序遍历的过程中，维护前缀节点值并使用前缀节点值计算差值最小值。
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
	cout << "main：ret = " << ret << endl;
	return 0;
}