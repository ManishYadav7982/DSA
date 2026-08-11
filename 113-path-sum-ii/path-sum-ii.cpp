/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void f(TreeNode* root, int targetSum, vector<int>& store,
           vector<vector<int>>& ans) {

        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            store.push_back(root ->val) ;
            ans.push_back(store);
            store.pop_back() ;
            return;
        }

        else if (root->left == NULL && root->right == NULL && targetSum != root ->val ) {
            return;
        }
        // for(int i : store){
        //     cout <<i <<"  " ; 
        // }
        // cout << endl ; 

        if (root->left != NULL) {
            store.push_back(root->val);
            f(root->left, targetSum - root->val, store, ans);
            store.pop_back();
        }

        if (root->right != NULL) {
            store.push_back(root->val);
            f(root->right, targetSum - root->val, store, ans);
            store.pop_back();
        }

        
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> store;
        set<vector<int>> set;
        if (root == NULL)
            return ans;
        f(root, targetSum , store, ans);
        // for (auto i : set) {
        //     ans.push_back(i);
        // }
        return ans;
    }
};