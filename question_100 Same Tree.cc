/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL || q == NULL){
            return q==p;
        }
        if(p->val != q->val)
            return false;
        else{
            if(!isSameTree(p->left, q->left))
                return false;
            else
                return isSameTree(p->right, q->right);
        }
    }
};