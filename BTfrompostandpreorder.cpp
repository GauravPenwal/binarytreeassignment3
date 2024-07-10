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
    TreeNode*helper(vector<int>&pre,int prelo,int prehi,vector<int>&post,int polo,int pohi){
        if(polo>pohi || prelo>prehi)return NULL;
        TreeNode*root= new TreeNode (pre[prelo]);
        if(prelo==prehi)return root;
        int i = polo;
        while(post[i]!=pre[prelo+1]){i++;}
        int total = i+1-polo;
        root->left = helper(pre,prelo+1,prelo+total,post,polo,i);
        root->right = helper(pre,prelo+total+1,prehi,post,i+1,pohi-1);
return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return  helper(pre,0,n-1,post,0,n-1);
    }
};

int main(){

}