//懒得想更好的方法了，就这样吧……
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* createNode(const int* l, const int* r){
        if(l > r)
            return NULL;
        int mid = (r-l)/2;
        TreeNode* node = new TreeNode(l[mid]);
        node->left = createNode(l, l+mid-1);
        node->right = createNode(l+mid+1, r);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
            return NULL;
        const int* l= num.data();
        return createNode(l, l+num.size()-1);
    }

    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        while(head != NULL){
            result.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(result);
    }
};