#include "MemberNode.h"

MemberNode::MemberNode(Member m, MemberNode* n)
: member(m), next(n) {}