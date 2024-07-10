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

TreeNode*helper(vector<int>& post,int polo,int pohi,vector<int>& in,int inlo,int inhi){
        if(inlo>inhi)return NULL;
        TreeNode*root = new TreeNode(post[pohi]);
        if(inlo==inhi)return root;
        int i =inlo;
        while(i<=inhi){
            if(in[i]==post[pohi])break;
            i++;
        }
        int lc = i-inlo;
        int rc = inhi-i;
        root->left = helper(post,polo,polo+lc-1,in,inlo,i-1);
        root->right = helper(post,polo+lc,pohi-1,in,i+1,inhi);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
    int n = in.size();
    return helper(post,0,n-1,in,0,n-1);
    }

int main(){

}