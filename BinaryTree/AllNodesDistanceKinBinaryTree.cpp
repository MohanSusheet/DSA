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

void mapToParent(TreeNode* root, map<TreeNode*, TreeNode*>& parentMapping)
{
    if(root == NULL)return;

    if(root->left)
    {
        if(parentMapping.find(root->left) == parentMapping.end())
        {
            parentMapping[root->left] = root;
        }
        mapToParent(root->left, parentMapping);
    }

    if(root->right)
    {
        if(parentMapping.find(root->right) == parentMapping.end())
        {
            parentMapping[root->right] = root;
        }
        mapToParent(root->right, parentMapping);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    map<TreeNode*, TreeNode*> parentMapping;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    int dist = 0;
    vector<int>ans;

    if(root == NULL)return {};
    
    mapToParent(root, parentMapping);

    //target node is to be treated as root node
    q.push(target);
    visited[target] = true;

    while(!q.empty() && dist < k)
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right&& !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parentMapping.find(node) != parentMapping.end() && !visited[parentMapping[node]])
            {
                q.push(parentMapping[node]);
                visited[parentMapping[node]];
            }
            visited[node] = true;
        }

        dist += 1;
    }
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->val);
    }

    return ans;
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

    vector<int> ans = distanceK(root, target, 1);

    for(auto it: ans)cout<<it<<" ";
    return 0;
}