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

ListNode* segregateBrute(ListNode* head) 
{
    //Brute Force: using count variable for 0, 1 and 2 and overwriting the values in given LL. In 2 passes
    //T.C --> O(2N), S.C --> O(1)
    int count0 = 0, count1 = 0, count2 = 0;
    ListNode* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            count0++;
        }
        else if(temp->data == 1)
        {
            count1++;
        }
        else count2++;

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL)
    {
        if(count0)
        {
            temp->data = 0;
            count0--;
        }
        else if(count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }

    return head;
}

ListNode* segregateOptimal(ListNode* head)
{
    // code here
    //Optimal Approach: using 3 dummy nodes and rearranging the links to sort the LL in just 1 pass
    //T.C --> O(N), S.C --> O(1)
    ListNode* temp = head;
    
    ListNode* dummy0 = new ListNode(-1), *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
    ListNode* zero = dummy0, *one = dummy1, *two = dummy2;
    
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    //condition to be handled
    //zero->next = dummy1->next;
    //one->next = dummy2->next;
    
    //condition handled
    zero->next = (dummy1->next) ? dummy1->next : dummy2->next; 
    one->next = dummy2->next;
    two->next = NULL;
    
    return dummy0->next;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(0);
    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(0);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    ListNode* head = n1;
    traverseList(head);
    cout<<endl;
    // head = segregateBrute(head);
    head = segregateOptimal(head);
    traverseList(head);

    return 0;
}