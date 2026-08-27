#include<iostream>
#include<stack>
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

ListNode* findMiddleNodeBrute(ListNode* head)
{
    //Brute Force Approach: counting the total nuber of nodes and then returning the middle one
    //T.C --> O(N + N/2), S.C --> O(1)
    if(head == nullptr)return head;

    int count = 0;

    ListNode* temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    temp = head;

    int target = count / 2;

    while(target--)
    {
        temp = temp->next;
    }

    return temp;
}

ListNode* findMiddleNodeOptimal(ListNode* head)
{
    //Optimal Approach: Using 2 pointers (slow and fast) Tortoise and Hair
    //T.C --> O(N/2), S.C --> O(1)
    if(head == nullptr || head->next == nullptr)return head;

    ListNode* slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    ListNode* middleNode = findMiddleNodeBrute(head);
    cout<<"Middle Node: "<<middleNode->data;
    ListNode* middleNode1 = findMiddleNodeOptimal(head);
    cout<<"\nMiddle Node: "<<middleNode1->data;

    return 0;
}