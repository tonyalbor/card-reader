#include "MemberList.h"

void MemberList::emptyList(MemberNode* l)
{
    l = head;
    for( ;head; )
    {
        head = head->next;
        delete l;
        l = head;
    }
}

MemberList::MemberList()
: head(NULL) {}

MemberList::MemberList(Member m)
: head (NULL)
{
    push(m);
}

MemberList::~MemberList()
{
    emptyList(head);
}

void MemberList::push(Member m)
{
    MemberNode* temp = head;
    MemberNode* newNode = new MemberNode(m,NULL);
    if(!head)
        head = newNode;
    else
    {
        for( ;temp->next; temp = temp->next) {}
        temp->next = newNode;
    }
}

void MemberList::printList()
{
    MemberNode* temp;
    for(temp = head; temp; temp = temp->next)
    {
        temp->member.print();
            
    }
}
/*
MemberNode* MemberList::mergeSort(MemberNode* h, MemberNode* r)
{
    if(h == r)
    {
        h->next = NULL;
        return h;
    }
    MemberNode* mid = getMidNode(h,r);
    MemberNode* right = mergeSort(mid->next,r);
    MemberNode* left = mergeSort(h,mid);
    return mergeList(left,right);
}

MemberNode* MemberList::getMidNode(MemberNode* h, MemberNode* r)
{
    MemberNode* temp1;
    MemberNode* temp2;
    temp1 = temp2 = h;
    
    while(temp2 != r && temp2->next != r)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}

MemberNode* MemberList::mergeList(MemberNode* p, MemberNode* q)
{
    if(!p) return q;
    if(!q) return p;
    
    MemberNode* newNode;
    if(p->member.name <= q->member.name)
    {
        newNode = p;
        newNode->next = mergeList(p->next,q);
    }
    else
    {
        newNode = q;
        newNode->next = mergeList(p,q->next);
    }
    return newNode;
}
*/

/*
Node mergeSort(Node head, Node rear) {
    if (head == rear) {
        head.next = null;
        return head;
    }
    Node mid = getMidNode(head, rear);
    Node right = mergeSort(mid.next, rear); // Compute right half first
    Node left = mergeSort(head, mid); // Compute left
    return mergeList(left, right);
}

Node getMidNode(Node head, Node rear) {
    Node it1, it2;
    it1 = it2 = head;
    while (it2 != rear && it2.next != rear) {
        it1 = it1.next;
        it2 = it2.next.next;
    }
    return it1;
}

Node mergeList(Node p, Node q) {
    if (p == null)  return q;
    if (q == null)  return p;
    
    Node N;
    if (p.info <= q.info) {
        N = p;
        N.next = mergeList(p.next, q);
    } else {
        N = q;
        N.next = mergeList(p, q.next);
    }
    return N;
}



*/



