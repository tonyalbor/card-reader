#include "MemberNode.cpp"

class MemberList
{
    public:
        MemberNode* head;
        void emptyList(MemberNode* l);
    public:
        MemberList();
        MemberList(Member m);
        ~MemberList();
        void push(Member m);
        void printList();
    MemberNode* mergeSort(MemberNode* h, MemberNode* r);
    MemberNode* getMidNode(MemberNode* h, MemberNode* r);
    MemberNode* mergeList(MemberNode* p, MemberNode* q);
};


