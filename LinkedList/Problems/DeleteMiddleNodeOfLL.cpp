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

void traverseList(ListNode* head)
{
    ListNode* temp = head;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

ListNode* deleteMiddleBrute(ListNode* head) {
    //Brute Force Approach: counting the number of nodes and reaching the node previous to the middle node.
    //T.C --> O(N + N/2), S.C --> O(1)
    if(head == nullptr || head->next == nullptr)return nullptr;
    int count = 0;
    ListNode* temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    int target = count/2 - 1; //reaching the node previous to the middle node.
    temp = head;

    while(target--)
    {
        temp = temp->next;
    }

    if(temp && temp->next)temp->next = temp->next->next;

    return head;
}

ListNode* deleteMiddleOptimal(ListNode* head) {
    //Optimal Approach: Using slow and fast pointers.
    //T.C --> O(N / 2), S.C --> O(1)
    if(head == nullptr || head->next == nullptr)return nullptr;
    ListNode *slow = head, *fast = head;

    fast = fast->next->next; //Moving fast one time without moving slow to make sure slow ends up pointing to the node previous to the middle node.

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;

    return head;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);

    ListNode* head = n1;
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    ListNode* newHead1 = deleteMiddleBrute(n1);
    traverseList(newHead1);
    cout<<endl;
    ListNode* newHead2 = deleteMiddleOptimal(n1);
    traverseList(newHead2);
    return 0;
}