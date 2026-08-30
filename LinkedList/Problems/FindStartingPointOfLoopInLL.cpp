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

ListNode* detectCycleOptimal(ListNode* head)
{
    //Optimal Approach: Using fast and slow pointers. Distantce: L1 + D [refere the video once more]
    //T.C --> O(N)
    if(head == nullptr)return head;

    ListNode* slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

ListNode *detectCycleBrute(ListNode *head) {
    //Brute Force Approach: using hashmap
    //T.C --> O(N * LogN[insertion in hashmap]), S.C --> O(N) Hashmap
    if(head == nullptr || head->next == nullptr)return nullptr;

    map<ListNode*, int> mp;
    ListNode* temp = head;

    while(temp)
    {
        if(mp.find(temp) != mp.end()){
            // cout<<temp->data<<"\n";
            return temp;
        }
        mp[temp]++;
        temp = temp->next;
    }

    return nullptr;
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
    n9->next = n7;

    ListNode* startPoint1 = detectCycleBrute(n1);
    cout<<startPoint1->data<<"\n";
    ListNode* startPoint2 = detectCycleOptimal(n1);
    cout<<startPoint2->data;
    return 0;
}