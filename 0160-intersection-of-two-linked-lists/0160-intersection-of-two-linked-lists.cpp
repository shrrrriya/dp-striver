/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //CALCULATE THE LENGTH OF headA
        ListNode*temp=headA;
        int sizeA=0;
        while(temp!=NULL){
            sizeA++;
            temp=temp->next;
        }
        temp=headB;
        int sizeB=0;
        while(temp!=NULL){
            sizeB++;
            temp=temp->next;
        }
        if(sizeA>sizeB){
            int n=sizeA-sizeB;
            for(int i=0;i<n;i++){
                headA=headA->next;
            }
        }else{
            int n=sizeB-sizeA;
            for(int i=0;i<n;i++){
                headB=headB->next;
            }   
        }
        while(headA!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};

//BRUTE FORCE 
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         map<ListNode*,int> mpp;
//         while(headA!=NULL){
//             mpp[headA]=1;
//             headA=headA->next;
//         }
//         while(headB!=NULL){
//             if(mpp[headB]==1) return headB;
//             headB=headB->next;
//         }
//         return NULL;
//     }
// };