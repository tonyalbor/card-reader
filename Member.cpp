#include "Member.h"

Member::Member()
: name(""), email(""), phone(0) {}
Member::Member(string n, string e, string p)
: name(n), email(e), phone(p) {}
void Member::print()
{
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phone << endl;
}