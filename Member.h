#include <iostream>
using namespace std;

class Member
{
    public:
        string name;
        string email;
        string phone;
    
    public:
        Member();
        Member(string n, string e, string p);
        void print();
};