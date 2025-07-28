/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1; // either intersection node or NULL
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

//OPTIMISED
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         //CALCULATE THE LENGTH OF headA
//         ListNode*temp=headA;
//         int sizeA=0;
//         while(temp!=NULL){
//             sizeA++;
//             temp=temp->next;
//         }
//         temp=headB;
//         int sizeB=0;
//         while(temp!=NULL){
//             sizeB++;
//             temp=temp->next;
//         }
//         if(sizeA>sizeB){
//             int n=sizeA-sizeB;
//             for(int i=0;i<n;i++){
//                 headA=headA->next;
//             }
//         }else{
//             int n=sizeB-sizeA;
//             for(int i=0;i<n;i++){
//                 headB=headB->next;
//             }   
//         }
//         while(headA!=NULL){
//             if(headA==headB) return headA;
//             headA=headA->next;
//             headB=headB->next;
//         }
//         return NULL;
//     }
// };