
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }

        ListNode * resultList = nullptr;
        ListNode * resultIndex = nullptr;
        int tmp = 0;
        bool bFirst = true;
        while((l1 != nullptr)||(l2 != nullptr)){
            int sum = 0;
            if(l1 != nullptr && l2!= nullptr){
                sum = l1->val + l2->val;
                sum += tmp;
            }else if(l1!= nullptr){
                sum = l1->val+tmp;
            } else if(l2 != nullptr){
                sum = l2->val+tmp;
            }

            tmp = 0;

            ListNode *node = new ListNode(0);
            if (sum < 10){
                node->val = sum;
            }else{
                node->val = sum - 10;
                tmp = 1;
            }

            if(bFirst){
                resultList = node;
                node = nullptr;
                resultIndex = resultList;
                bFirst = false;
            }else{
                resultIndex->next = node;
                resultIndex = node;
            }

            if (l1 != nullptr){
                l1 = l1->next;
            }

            if (l2 != nullptr){
                l2 = l2->next;
            }
        }
        if (tmp == 1){
            ListNode *node = new ListNode(1);
            resultIndex->next = node;
        }

        return resultList;
    }
};

int main(){
    ListNode *list1 = new ListNode(9);
    ListNode *list1node1 = new ListNode(8);
    list1->next = list1node1;
    //ListNode * list1node2 = new ListNode(3);
    //list1node1->next = list1node2;

    ListNode *list2 = new ListNode(1);
    //ListNode *list2node1 = new ListNode(6);
    //list2->next = list2node1;
    //ListNode * list2node2 = new ListNode(4);
    //list2node1->next = list2node2;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(list1,list2);

    while(result != nullptr){
        std::cout<<result->val<<std::endl;
        result = result->next;
    }

}