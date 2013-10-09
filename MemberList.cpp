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

