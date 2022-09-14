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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Design a full adder with four cases
        //Both l1 and l2 overlap
        //l1 extends beyond l2
        //l2 extends beyond l1
        //There is an outstanding carry
        
        //initialize head pointer
        ListNode *head = new ListNode;
        head->next = nullptr;
        
        //initialize temp pointer
        ListNode *temp = new ListNode;
        temp = head;
        
        //initialize summation variables
        bool adding = true; 
        int carry = 0;
        int sumval = 0;
        while (adding){
            
            //allocate memory for sum node
            ListNode *sum = new ListNode;
            sum->next = nullptr; //sum node is always tail node            
            
            //Both l1 and l2 overlap
            if (l1 != nullptr && l2 != nullptr){
                
                //execute full adder
                sumval = l1->val + l2->val + carry;
                if (sumval >= 10) {sumval -=10; carry = 1;}
                else carry = 0;
                
                //populate sum node
                sum->val = sumval;
                temp->next = sum; //point previous node to sum
                
                temp = temp->next; //slide temp forward
                l1 = l1->next; //slide l1 forward
                l2 = l2->next; //slide l2 forward
                
                //a case was satisfied, so continue adding
                adding = true;
                
            }
            
            //l1 extends beyond l2
            else if (l1 != nullptr){
                
                //execute full adder
                sumval = l1->val + carry;
                if (sumval >= 10) {sumval -=10; carry = 1;}
                else carry = 0;
                
                //populate sum node
                sum->val = sumval;
                temp->next = sum; //point previous node to sum
                
                temp = temp->next; //slide temp forward
                l1 = l1->next; //slide l1 forward
                
                //a case was satisfied, so continue adding
                adding = true;
                
            }
            
            //l2 extends beyond l1
            else if (l2 != nullptr){
                
                //execute full adder
                sumval = l2->val + carry;
                if (sumval >= 10) {sumval -=10; carry = 1;}
                else carry = 0;
                
                //populate sum node
                sum->val = sumval;
                temp->next = sum; //point previous node to sum
                
                temp = temp->next; //slide temp forward
                l2 = l2->next; //slide l1 forward
                
                //a case was satisfied, so continue adding
                adding = true;
                
            }
            
            //There is an outstanding carry
            else if (carry != 0){
                
                //execute full adder
                sumval = carry;
                carry = 0;
                
                //populate sum node
                sum->val = sumval;
                temp->next = sum; //point previous node to sum
                
                //a case was satisfied, so continue adding
                adding = true;
        
            }
            
            //no case was satisfied, stop
            else adding = false;

        }
        head = head->next; //original head node has no data
        return head;
    }
};
