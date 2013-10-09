#include <iostream>
#include <fstream>
using namespace std;

ofstream att("5_14_12.txt");

struct MemberNode
{
    string name;
    string position;
    string index;
    bool hasPaid;
    MemberNode* next;
    
    MemberNode(string n, string p, string i, bool b, MemberNode* M)
    {
        this->name = n;
        this->position = p;
        this->index = i;
        this->hasPaid = b;
        this->next = M;
    }
    
};

class MemberList
{
    private:
        MemberNode* head;
    
    void emptyList(MemberNode* l)
    {
        l = head;
        for( ;head; )
        {
            head = head->next;
            delete l;
            l = head;
        }
    }
    public:
        MemberList()
        {
            head = NULL;
        }
    
        MemberList(string n, string p, string i, bool b)
        {
            head = NULL;
            push(n,p,i,b);
        }
    
        ~MemberList()
        {
            emptyList(head);
        }
    
        void push(string n, string p, string i, bool b)
        {
            MemberNode* temp = head;
            MemberNode* newNode = new MemberNode(n,p,i,b,NULL);
            if(!head)
            {
                head = newNode;
            }
            else
            {
                for( ;temp->next; temp = temp->next) {}
                temp->next = newNode;
            }
            
        }
    
        void operator[](const string i)
        {
            MemberNode* temp = head;
            for( ; temp; temp = temp->next)
            {
                if(temp->index == i)
                {
                    cout << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Position: " << temp->position << endl;
                    if(temp->hasPaid) cout << "Member has paid dues." << endl;
                    else if(!temp->hasPaid) cout << "Member has NOT paid dues." << endl;
                    cout << endl;
                    att << temp->name << endl;
                    return;
                }
            }
            
            int pos = i.find('/');
            string firstName = i.substr(pos + 1);
            string lastName = i.substr(0,pos);
            cout << endl;
            cout << "Name: " << firstName << " " << lastName << endl;
            cout << "Not a current member." << endl;
            cout << endl;
            att << firstName << " " << lastName << endl;
        }
    
};

void fillList(MemberList& list)
{
    list.push("Tony Albor", "Vice President", "ALBOR/TONY", true);
    list.push("Ileana Figueroa", "President", "FIGUEROA/ILEANA", true);
    list.push("Maricruz Ayala", "External Affairs", "AYALA/MARICRUZ", true);
    list.push("Andrew Calderon", "Treasurer", "CALDERON/ANDREW", true);
    list.push("Marilyn Sanchez", "Internal Affairs", "SANCHEZ/MARILYN", true);
    list.push("Aracely Calvillo", "Secretary", "CALVILLO/ARACELY", true);
    list.push("Gustavo Blanco", "Webmaster", "BLANCO/GUSTAVO", true);
    list.push("Leopoldo Torres", "Fundraiser", "TORRES/LEOPOLDO", true);
    list.push("Lora Luevano", "Professional Development", "LUEVANO/LORA", true);
    list.push("Jose Figueroa", "Historian", "FIGUEROA/JOSE", true);
    list.push("Jesus Sahagun", "General Member", "SAHAGUN/JESUS", true);
    list.push("Joanna Vasquez", "General Member", "VASQUEZ/JOANNA", true);
}

void header(string s)
{
    att << "Society of Hispanic Professional Engineers" << endl;
    att << "Date: " << s << endl << endl;
    att << "Name:" << endl;
}
    
int main()
{
    MemberList members;
    fillList(members);
    
    string date;
    cout << "Enter the date: ";
    cin >> date;
    header(date);
    
    string s;
    int space;
    string i;
    char exit = 0;
    while(!exit)
    {
        cout << "Slide Card: " << endl;
        cin >> s;
        while(s[0] != '%')
        { 
            if(s == "q")
            {
                exit = 1; 
                break;
            } 
            else cin >> s;
        }       
        space = s.find(" ");
        i = s.substr(19, space-19);
        members[i];
    }
    att.close();
  
    return 0;
}