#include<iostream>
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

ListNode* RemoveNthNodeFromEndOFListBrute(ListNode* head, int n)
{
    //Brute Force Approach: 2 pass solution. 1-> count the number of nodes and determine the target node to be deleted.
    //2-> traverse to the target node and delete it.
    //T.C --> O(N) + O(N-n) [if n = 1] ~~ O(2N)  {N being the length of the LL}, S.C --> O(1)
    if(head == NULL or head->next == NULL)return NULL;

    ListNode* temp = head, *delNode = nullptr;
    int count = 0;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    if(count == n)//if node from the end to be deleted is = count that means the head node needs to be deleted
    {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    int target = count - n; //target points to the node just previous to the node to be deleted 

    temp = head;

    while(temp)
    {
        target--;
        if(target == 0)break;

        temp = temp->next;
    }

    delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

ListNode* RemoveNthNodeFromEndOFListOptimal(ListNode* head, int n)
{
    //Optimal Approach: 1 pass solution. We need to reach the prev to target node which is N-n.
    //But N is not known, how can N-n be calculated?
    //Actually N-n can be calculated using Slow and Fast pointer, by keeping the FAST pointer ahead of slow pointer by "n" steps
    //T.C --> O(N-n) {N being the length of the LL}, S.C --> O(1)
    if(head == NULL || head->next == NULL)return NULL;
    
    ListNode* fast = head, *slow = head;

    for(int i = 0; i < n; i++)fast = fast->next;

    if(fast == NULL){ //When n == N. in that case fast will already be pointing to NULL
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    while(fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

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

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    ListNode* head = n1;
    
    traverseList(head); cout<<endl;

    // head = RemoveNthNodeFromEndOFListBrute(head, 3);
    head = RemoveNthNodeFromEndOFListOptimal(head, 3);
    traverseList(head);
    return 0;
}