#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        // leaf node hitting condition
        int n = targetSum-(root->val);
        if(root->left==NULL && root->right==NULL){
            return n==0;
        }
        return hasPathSum(root->left,n) || hasPathSum(root->right,n);
    }
};

int main(){
    
}