#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<math.h>

using namespace std;

class TreeNode
{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){} //Empty Constructor
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int getLeftHeight(TreeNode* root)
{
    if(root == NULL)return 0;
    int height = 0;
    while(root)
    {
        height++;
        root = root->left;
    }
    return height;
}

int getRightHeight(TreeNode* root)
{
    if(root == NULL)return 0;
    int height = 0;
    while(root)
    {
        height++;
        root = root->right;
    }
    return height;
}

int getCount(TreeNode* root)
{
    if(root == NULL)return 0;

    int lh = 1 + getLeftHeight(root->left);
    int rh = 1 + getRightHeight(root->right);

    if(lh == rh)return pow(2, lh) - 1;

    return 1 + getCount(root->left) + getCount(root->right);
}

int countNodes(TreeNode* root) 
{
    //T.C --> O(log N[traversing] * log N[height]) ~~ O((log N)^2)
    //S.C --> O(log N)
    return getCount(root);
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(13);
    root->left->right->right = new TreeNode(19);

    /*COMPLETE TREE: every level, except possibly the last, is completely filled in a complete binary tree,
    and all nodes in the last level are as far left as possible.*/

    //Approach 1: Naive approach, Use any of the traveral DFS(inoreder, preorder, postorder) or BFS and simply
    //count the nodes present in the tree.

    //Approach 2: Using the Height of the tree.
    //Case 1: when the tree is PERFECT (lh == rh) i.e. All internal nodes have two children, and all leaf nodes are at the same level
    //Then the no. of node = 2^h - 1
    //Case 2: when the tree is Complete and lh != rh.
    //then the above formula would fail to give the total no. of nodes so, node = 1 + leftSubtree_nodes + rightSubtree_Nodes
    int ans = countNodes(root);

    cout<<"Number of Nodes in the given Tree : "<<ans;

    return 0;
}