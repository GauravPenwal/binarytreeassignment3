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

void helper( TreeNode * root,int lvl,vector<int>&ans){
    if(root==NULL) return;
    if(ans.size()==lvl)ans.push_back(root->val);
    helper(root->left,lvl+1,ans);
    helper(root->right,lvl+1,ans);
}

vector<int> printLeftView(TreeNode * root) {
vector<int>ans;
helper(root,0,ans);
return ans;
}
int main(){

}