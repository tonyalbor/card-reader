#include "Member.cpp"

struct MemberNode
{
    Member member;
    MemberNode* next;
    
    MemberNode(Member m, MemberNode* n);
};