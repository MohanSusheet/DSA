#include<iostream>
#include<map>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
    
    ListNode()
    {
        this->data = 0;
        this->next = nullptr;
    }
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ListNode(int data, ListNode* next)
    {
        this->data = data;
        this->next = next;
    }
};

bool hasCycleBrute(ListNode* head)
{
    //Brute Force Approach: Using hashmap to store the nodes and check whether we encounter any node more than (1)once
    //T.C --> O(N * Log N[map insertion ]), S.C --> O(N)[all the nodes will be stored in the map]
    map<ListNode*, int> mp;

    ListNode* temp = head;

    while(temp)
    {
        if(mp.find(temp) != mp.end())return true;

        mp[temp]++;
        temp = temp->next;
    }

    return false;
}

bool hasCycleOptimal(ListNode *head) 
{
    //Optmial Approach: Using 2 pointers (slow and fast) [hair and tortoise]
    //T.C --> O(N), S.C --> O(1)

    ListNode* slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return true;
    }

    return false;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    ListNode* head = n1;
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout<<hasCycleBrute(head)<<"\n";
    cout<<hasCycleOptimal(head);

    return 0;
}