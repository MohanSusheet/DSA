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
ListNode* addOneIterative(ListNode* head) {
    //T.C--> O(3N), S.C --> O(1)
    if(head == NULL)return head;
    
    head = reverse(head);  //--> O(N)
    
    ListNode* temp = head;
    int carry = 1; //initially 1 as 1 needs to be added to the number
    
    while(temp)  //--> O(N)
    {
        if(temp->data + carry < 10)
        {
            int sum = temp->data + carry;
            temp->data = sum;
            carry = 0;
            break;
        }
        else
        {
            int sum = temp->data + carry;
            carry = sum / 10;
            temp->data = sum % 10;
            temp = temp->next;
        }
    }
    
    head = reverse(head); //--> O(N)

    if(carry)
    {
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        return newHead;
    }
    
    return head;
}

int helper(ListNode* head)
{
    if(head == nullptr)return 1;

    int carry = helper(head->next);

    head->data += carry;

    if(head->data < 10)
    {
        return 0;
    }

    head->data = head->data % 10;
    return 1;
}

ListNode* addOneRecursive(ListNode* head)
{
    //T.C --> O(N), S.C --> O(N) stack space
    ListNode* temp = head;

    int carry = helper(temp);

    if(carry)
    {
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        return newHead;
    }
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
    cout<<"List before function call: "; 
    traverseList(head);
    // ListNode* newHead = addOneIterative(head);
    ListNode* newHead = addOneRecursive(head);
    cout<<"\nList after function call: ";
    traverseList(newHead);


    /*NOTE: Both the solutions have their pro and cons. Neither one is the optmal one
    */
    return 0;
}