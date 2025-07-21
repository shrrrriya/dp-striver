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
    void deleteNode(ListNode* node) {
        while(node->next!=nullptr){
            ListNode*temp=node->next;
            node->val=temp->val;
            if(temp->next==nullptr){
                node->next=nullptr; break;
            }
            node=node->next;
        }
    }
};

// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         while(node->next!=nullptr){
//             ListNode*temp=node->next;
//             node->val=temp->val;
//             if(temp->next==nullptr){  
//                 node->next=nullptr;
//                 delete temp;
//                 break;
//             }
//             node=node->next;
//         }
//     }
// };