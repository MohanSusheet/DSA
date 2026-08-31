#include<iostream>
#include<map>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode* prev;
    
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

ListNode* deleteAllOccurOfX(ListNode* head, int x) {
    //Approach: Simple linear search in using nxt, prv and cur pointers in DLL
    //T.C --> O(N), S.C --> O(1)
    if(head == nullptr)return head;

    ListNode* temp = head;

    while(temp)
    {
        if(temp->data == x)
        {
            if(temp == head)head = head->next;

            ListNode* prv = temp->prev, *nxt = temp->next;
            if(prv)prv->next = nxt;
            if(nxt)nxt->prev = prv;
            delete temp;
            temp = nxt;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    ListNode* head = n1;
    
    n1->next = n2; n1->prev = nullptr;
    n2->next = n3; n2->prev = n1;
    n3->next = n4; n3->prev = n2;
    n4->next = n5; n4->prev = n3;
    n5->next = n6; n5->prev = n4;
    n6->prev = n5;

    ListNode* newHead = deleteAllOccurOfX(n1, 5);
    traverseList(newHead);
    return 0;
}