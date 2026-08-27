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

void traverseList(ListNode* head)
{
    ListNode* temp = head;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

ListNode* findIntersection1(ListNode* head1, ListNode* head2)
{
    //  Brute Force Approach: Using hashing to store the node of one linkedList
    //T.C --> O(N1 * logN1) [iterating and storing the 1st LL nodes] + O(N2)
    //S.C --> O(N1)

    map<ListNode*, int> mp;
    
    ListNode* temp1 = head1, *temp2 = head2;
    
    while(temp1)
    {
        mp[temp1]++;
        temp1 = temp1->next;
    }
    
    while(temp2)
    {
        if(mp.find(temp2) != mp.end())return temp2;
        temp2 = temp2->next;
    }
    
    return nullptr;
}

ListNode* intersectionPoint(ListNode* h1, ListNode* h2, int d)
{
    ListNode* t1 = h1, *t2 = h2;
    
    while(d--) //--> O(N2 - N1)
    {
        t2 = t2->next;
    }
    
    while(t1 != t2) //--> O(N1)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    
    return t1;
}

ListNode* findIntersection2(ListNode* head1, ListNode* head2) {
    //  BetterApproach:Finding out length of both LLs and making them stand at the same vertical level
    //T.C --> O(N1) + O(N2) + O(N2 - N1) + O(N1)
    //S.C --> O(1)
    
    int len1 = 0, len2 = 0;
    ListNode* temp1 = head1, *temp2 = head2;
    
    while(temp1) //--> O(N1)
    {
        len1++;
        temp1 = temp1->next;
    }
    
    while(temp2) //--> O(N2)
    {
        len2++;
        temp2 = temp2->next;
    }
    
    if(len1 < len2)
    {
        return intersectionPoint(head1, head2, len2-len1); //assuming len1 > len2
    }
    else return intersectionPoint(head2, head1, len1-len2);
}

ListNode* findIntersectionOptimal(ListNode* head1, ListNode* head2)
{
    //Optimal Approach: Moving the 2 pointers pointing to each head simultaneously.
    //When each of them reaches null, it starts again from the other List's head;
    //T.C -->O(N1 + N2), S.C --> O(1)

    ListNode* temp1 = head1, *temp2 = head2;

    while(temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        
        if(temp1 == temp2)return temp1;

        if(temp1 == nullptr)temp1 = head2;
        if(temp2 == nullptr)temp2 = head1;
    }

    return temp1;
}

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