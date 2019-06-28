//
// Created by yz L on 2019-03-16.
//

#ifndef ALG_LISTNODE_H
#define ALG_LISTNODE_H

/**
 * 25. Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

https://leetcode-cn.com/problems/reverse-nodes-in-k-group
 */

class ListNode {
public:
    ListNode* next;
    int nData;
    ListNode(int data) :next(nullptr){
        this->nData = data;
    }
};

ListNode* reverse(ListNode* pHead) {
    ListNode* pTail = nullptr;
    ListNode* pNext = nullptr;
    while (pHead != nullptr) {
        pNext = pHead->next;
        pHead->next = pTail;
        pTail = pHead;
        pHead = pNext;
    }

    return pTail;
}


ListNode* reverseGroup(ListNode* pHead,int k,ListNode*& pGroupNextNode) {
    int leaveNodeNum =0;
    ListNode* pRoot = pHead;
    while (pRoot != nullptr && leaveNodeNum < k) {
        leaveNodeNum++;
        pRoot = pRoot->next;
    }
    if (leaveNodeNum < k) {
        pGroupNextNode = nullptr;
        return pHead;
    }

    ListNode* pTail = nullptr;
    ListNode* pNext = nullptr;
    int reverseNum =0;
    while (pHead != nullptr) {
        pNext = pHead->next;
        pHead->next = pTail;
        pTail = pHead;
        pHead = pNext;
        reverseNum++;
        if (reverseNum == k) {
            pGroupNextNode = pHead;
            break;
        }
    }

    return pTail;
}


ListNode* reverseKGroup(ListNode* pHead, int k) {
    ListNode* pGroupLastNode = pHead;
    ListNode* pGroupNextNode = nullptr;

    ListNode* pNewHeader = reverseGroup(pHead,k,pGroupNextNode);
    while (pGroupNextNode != nullptr) {
        ListNode* pPreGroupHeader = pGroupNextNode;
        ListNode* pGroupHeader = reverseGroup(pPreGroupHeader,k,pGroupNextNode);
        pGroupLastNode->next = pGroupHeader;
        pGroupLastNode = pPreGroupHeader;
    }

    return pNewHeader;
}




#endif //ALG_LISTNODE_H
