/**
 *	https://leetcode.com/problems/symmetric-tree/
 *	
 *	101. Symmetric Tree
 *	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 先判断是否都有子树，单独一个有子树的认为不对称，都有子树的递归判断子树是否相等，注意当前节点的左子树与兄弟节点的右子树比，右子树与兄弟左子树比

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return true;
	} 

	if (root->left != NULL && root->right != NULL) 
	{
		return isEqualTree(root->left, root->right);
	} 
	else 
	{
		return false;
	}
}

bool isEqualTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}

	if (p != NULL && q != NULL)
	{
		return (p->val == q->val) && isEqualTree(p->left, q->right) && isEqualTree(p->right, q->left);
	}
	else
	{
		return false;
	}
}
