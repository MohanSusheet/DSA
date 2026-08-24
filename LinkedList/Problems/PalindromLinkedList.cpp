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

bool isPalindromeBrute(ListNode* head) {
    //Brute Force Approach: using 2 Passes and Stack data structure. LIFO property of stack helps use compare the LL in reverse order.
    //T.C --> O(2N), S.C --> O(N)
    stack<int> st;
    ListNode* temp = head;

    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp)
    {
        if(temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }

    return st.empty();
}

ListNode* reverse(ListNode* head)
{
    ListNode* cur = head, *prev = NULL;

    while(cur)
    {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

bool isPalindromeOptimal(ListNode* head) {
    //Optimal Approach: Determining the midway of LL. Reversing the second half and comparing.
    //NOTE: Reverse the 2nd half back to its original config before returning
    //T.C --> O(2N), S.C --> O(1)
    ListNode* slow = head, *fast = head;

    //for even length LL we will have m1 and m2 (2 middle nodes). We need to stop at m1, hece the following condition
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverse(slow->next); //slow->next points to the 1st node of second half
    ListNode* first = head, *second = newHead;

    while(second)
    {
        if(first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    ListNode* head = n1;
    
    cout<<((isPalindromeBrute(head) == 1) ? "Palindrome" : "Not a palindrome");
    cout<<((isPalindromeOptimal(head) == 1) ? "\nPalindrome" : "\nNot a palindrome");
    //NOTE: cout<<(isPalindromeBrute(head) == 1) ? "Palindrome" : "Not a palindrome";  PRINTED '1' and not desired string because
    //the stream insertion operator "<<" has higher precedence than the ternary conditional operator "? :"
    //C++ evaluates cout << (isPalindromeBrute(head) == 1) first.
    return 0;
}