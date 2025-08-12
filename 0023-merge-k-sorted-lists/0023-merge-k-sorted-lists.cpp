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

 //better approach
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*head=nullptr;
        if(lists.empty()) return nullptr;
        for(int i=0;i<lists.size();i++){
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*t1=list1;
        ListNode*t2=list2;
        ListNode*dNode=new ListNode(-1);
        ListNode*temp=dNode;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1)temp->next=t1;
        if(t2)temp->next=t2;
        return dNode->next;
    }
};