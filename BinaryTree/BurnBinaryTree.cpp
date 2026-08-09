#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>

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

void mapToParent(TreeNode* root, map<TreeNode*, TreeNode*>& parentMapping, int start, TreeNode* &startingNode)
{
    if(root == NULL)return;

    if(root->val == start)startingNode = root;
    if(root->left)
    {
        if(parentMapping.find(root->left) == parentMapping.end())
        {
            parentMapping[root->left] = root;
        }
        mapToParent(root->left, parentMapping, start, startingNode);
    }

    if(root->right)
    {
        if(parentMapping.find(root->right) == parentMapping.end())
        {
            parentMapping[root->right] = root;
        }
        mapToParent(root->right, parentMapping, start, startingNode);
    }
}
int amountOfTime(TreeNode* root, int start) {
    if(root == NULL)return 0;

    map<TreeNode*, TreeNode*> parentMapping;
    queue<TreeNode*> q;
    TreeNode* startingNode;
    unordered_map<TreeNode*, bool> visited;

    mapToParent(root, parentMapping, start, startingNode);
    // cout<<start<<" and Starting Node : "<<startingNode->val<<"\n";
    int timeTaken = 0;
    q.push(startingNode);
    visited[startingNode] = true;

    while(!q.empty())
    {
        int size = q.size();
        // cout<<"size of q: "<<size<<"\n";

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parentMapping.find(node) != parentMapping.end() && !visited[parentMapping[node]])
            {
                q.push(parentMapping[node]);
                visited[parentMapping[node]] = true;
            }
        }
        timeTaken++;
    }

    return timeTaken - 1; //equal to the number of edges;
}


int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->right->right->left->right = new TreeNode(19);

    TreeNode* target = root->left->right;

    cout<<"Time taken for the tree to burn: "<<amountOfTime(root, target->val);

    return 0;
}