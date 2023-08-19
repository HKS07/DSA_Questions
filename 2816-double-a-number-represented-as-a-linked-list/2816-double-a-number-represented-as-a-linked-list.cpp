/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode *head)
    {
        ListNode *prev= NULL, *next=NULL, *temp = head;
        
        while( temp )
        {
            next = temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        
        head = prev;
        
        temp = head;
        // while( temp )
        // {
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        // cout<<endl;
        return temp;
    }
    ListNode* doubleIt(ListNode* head) {
        if( head == NULL) return head;
        head = rev(head);
        ListNode *t = head, *prev = NULL;
        // cout<<t->val;
        int c = 0;
        while(t)
        {
            prev = t;
            int num = t->val*2+c;
            t->val = num%10;
            c = num/10;
            cout<<"val "<<t->val<<" carrry "<<c<<endl;
            t = t->next;
            
        }
        
        if( c != 0 ) 
        {
            ListNode *h = new ListNode(c);
            prev->next = h;
        }
        
        head = rev(head);
        
        return head;
        
    }
};