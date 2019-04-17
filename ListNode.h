//
// Created by yz L on 2019-03-16.
//

#ifndef ALG_LISTNODE_H
#define ALG_LISTNODE_H

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
