//
// Created by yz L on 2019-03-16.
//
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
#ifndef ALG_LISTNODE_H
#define ALG_LISTNODE_H

#include <iostream>

#include "singleton.h"

template <typename T>
class ListNode {
public:
    ListNode<T>* next;
    T nData;

    ListNode(T data) :next(nullptr){
        this->nData = data;
    }
};

class CListReverse {
    friend class CSingleton<CListReverse>;

public:
    /**
     * list reverse
     * @tparam T
     * @param pHead
     * @return
     */
    template <typename T>
    ListNode<T>* reverse(ListNode<T>* pHead);

    /**
     * k group list reverse
     * @tparam T
     * @param pHead
     * @param k
     * @return
     */
    template <typename T>
    ListNode<T>* reverseKGroup(ListNode<T>* pHead, int k);

    /**
     * print list,  * type is value type, & is reference.
     * @tparam T
     * @param pHead
     */
    template <typename T>
    void printList(ListNode<T>* pHead);

private:
    /**
     * sub function, reverse k group
     * @tparam T
     * @param pHead
     * @param k
     * @param pGroupNextNode
     * @return
     */
    template <typename T>
    ListNode<T>* reverseGroup(ListNode<T>* pHead,int k,ListNode<T>*& pGroupNextNode);
};


template <typename T>
ListNode<T>* CListReverse::reverse(ListNode<T>* pHead) {
    ListNode<T>* pTail = nullptr;
    ListNode<T>* pNext = nullptr;
    while (pHead != nullptr) {
        pNext = pHead->next;
        pHead->next = pTail;
        pTail = pHead;
        pHead = pNext;
    }

    return pTail;
}

template <typename T>
ListNode<T>* CListReverse::reverseKGroup(ListNode<T>* pHead, int k) {
    // After reverse for K Group，the last node of the group is the header of current list.
    // init it.
    ListNode<T>* pGroupLastNode = pHead;
    // next node after group be reversed.
    ListNode<T>* pGroupNextNode = nullptr;

    // firstly, reverse K group ,get the new header that list will be reversed.
    ListNode<T>* pNewHeader = reverseGroup(pHead,k,pGroupNextNode);
    while (pGroupNextNode != nullptr) {
        ListNode<T>* pPreGroupHeader = pGroupNextNode;
        ListNode<T>* pGroupHeader = reverseGroup(pPreGroupHeader,k,pGroupNextNode);
        pGroupLastNode->next = pGroupHeader;
        pGroupLastNode = pPreGroupHeader;
    }

    return pNewHeader;
}

template <typename T>
ListNode<T>* CListReverse::reverseGroup(ListNode<T>* pHead,int k,ListNode<T>*& pGroupNextNode) {
    //Count the left length of list, if it less to K, do not reverse
    int leftNodeNum =0;
    ListNode<T>* pRoot = pHead;
    while (pRoot != nullptr && leftNodeNum < k) {
        ++leftNodeNum;
        pRoot = pRoot->next;
    }
    if (leftNodeNum < k) {
        pGroupNextNode = nullptr;
        return pHead;
    }

    // exec K nodes reverse of list.
    ListNode<T>* pTail = nullptr;
    ListNode<T>* pNext = nullptr;
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

template <typename T>
void CListReverse::printList(ListNode<T>* pHead) {
    // pointer is value type, header won't be destroyed.
    while (pHead != nullptr) {
        std::cout<<pHead->nData<<", ";
        pHead = pHead->next;
    }
    std::cout<<std::endl;
}

#endif //ALG_LISTNODE_H
