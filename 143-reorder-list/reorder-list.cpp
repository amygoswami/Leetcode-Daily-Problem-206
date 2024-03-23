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
    void reorderList(ListNode* head) {
        //find midpoint
        ListNode *fast = head->next, *slo = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slo = slo->next;    //slo will be at midpoint of ll
        }

        //split into 2 halves, note 2nd half & break the link
        ListNode *second = slo->next;
        slo->next = NULL;

        //reverse 2nd half
        ListNode *prev = NULL;
        while(second){
            ListNode *front = second->next;
            second->next = prev;
            prev = second;
            second = front;
        }

        //merge 1st & 2nd half
        ListNode *first = head;
        second = prev;  //head of reversed 2nd half
        while(second){
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;   //new next of 1st half
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};