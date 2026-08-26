#include<iostream>
#include<stack>
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

ListNode* reverse(ListNode* head)
{
    if(head == NULL || head->next == NULL)return head;
    
    ListNode* cur = head, *prev = NULL;
    
    while(cur)
    {
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    return prev;
}
ListNode* addOne(ListNode* head) {
    if(head == NULL)return head;
    
    head = reverse(head);
    
    ListNode* temp = head;
    int carry = 1; //initially 1 as 1 needs to be added to the number
    
    while(temp)
    {
        if(temp->data + carry < 10)
        {
            traverseList(head);
            cout<<"\nSum is less than 10 : "<<temp->data + carry<<"\n";
            temp->data = temp->data + carry;
            carry = 0;
            break;
        }
        else
        {
            traverseList(head);
            cout<<"\nSum is greater than 10 : "<<temp->data + carry<<"\n";
            carry = (temp->data + carry) / 10;
            temp->data = (temp->data + carry) % 10;
            cout<<"Carry : "<<carry<<"\n";
            temp = temp->next;
        }
    }
    
    if(carry)
    {
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        cout<<"List before returning (newHEad): ";
        traverseList(newHead); cout<<"\n";
        return newHead;
    }
    
    cout<<"List before returning: ";
    traverseList(head);
    cout<<"\n";
    head = reverse(head);
    return head;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(9);
    ListNode* n3 = new ListNode(9);
    // ListNode* n4 = new ListNode(1);
    // ListNode* n5 = new ListNode(2);

    n1->next = n2;
    n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;

    ListNode* head = n1;
    cout<<"List before function call: "; traverseList(head);cout<<endl;
    ListNode* newHead = addOne(head);
    traverseList(newHead);

    return 0;
}