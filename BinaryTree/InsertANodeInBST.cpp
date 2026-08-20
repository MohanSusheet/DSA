#include<iostream>

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

void inorderTraversal(TreeNode* root)
{
    if(root == NULL)return;

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

void insertInBST(TreeNode*root, int k)
{
    //T.C --> O(H), S.C -->O(H) [H = N if Skewed or log N if balanced]
    if(root == NULL)return;

    TreeNode* cur = root;

    while(true)
    {
        if(k > cur->val)
        {
            if(cur->right != NULL)cur = cur->right;
            else
            {
                cur->right = new TreeNode(k);
                break;
            }
        }
        else
        {
            if(cur->left != NULL)cur = cur->left;
            else
            {
                cur->left = new TreeNode(k);
                break;
            }
        }
    }

}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(21);
    root->right->right->left = new TreeNode(19);
    root->right->right->right = new TreeNode(25);

    int k = 8;

    inorderTraversal(root);
    //There can be many ways to insert a node(with changing the positions of roots)
    //implemented approach inserts the given value at leaf
    insertInBST(root, k);

    cout<<endl;
    inorderTraversal(root); //To verify the result.

    return 0;
}