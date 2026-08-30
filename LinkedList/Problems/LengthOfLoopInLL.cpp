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

int lengthOfLoopBrute(ListNode *head) {
    //Brute Force Approach: using hashmap/
    //T.C --> O(N[traversing the list] * LogN[map operation])
    //S.C --> O(N) map
    if(head == nullptr)return 0;
    map<ListNode*, int> mp;
    ListNode* temp = head;
    int count = 0;
    
    while(temp)
    {
        count++;
        if(mp.find(temp) != mp.end())
        {
            return count - mp[temp];
        }
        mp[temp] = count;
        temp = temp->next;
    }
    
    return 0;
}

int findLoopLenght(ListNode* slow, ListNode* fast)
{
    int counter = 1;
    
    while(slow != fast)
    {
        counter++;
        fast = fast->next;
    }
    
    return counter;
}
int lengthOfLoopOptimal(ListNode *head) {
    //Optimal Approach: Using slow and fast pointers.
    //T.C --> O(2N), S.C --> O(1)
    if(head == nullptr)return 0;
    
    ListNode* slow = head, *fast = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return findLoopLenght(slow, fast->next);
        }
    }
    
    return 0;
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
    n9->next = n3;

    cout<<"Length of the loop: "<<lengthOfLoopBrute(n1);
    cout<<"\nLenght of the loop: "<<lengthOfLoopOptimal(n1);

    return 0;
}