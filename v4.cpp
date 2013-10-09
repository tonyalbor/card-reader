#include <fstream>
#include <vector>
#include "MemberList.cpp"

fstream memberFile("Members.csv");
ofstream attendanceFile;

void readFile(vector<string>& n, vector<string>& e, vector<string>& p)
{
    int j,k,l;
    
    string line;
    getline(memberFile,line); // Read past first line
    for(int i = 0; getline(memberFile,line); ++i)
    {
        for(j = 0; j < line.size(); ++j)
        {
            if(line[j] == ',')
            {
                n.push_back(line.substr(0,j));
                ++j;
                break;
            }
        }
        for(k = 0; k < line.size(); ++k)
        {
            if(line[k+j] == ',')
            {
                e.push_back(line.substr(j,k));
                ++k;
                break;
            }
        }
        p.push_back(line.substr(j+k));
    }
}

string readCard()
{
    string s;
    cout << "Swipe card (enter 'quit' to exit): ";
    cin >> s;
    return s;
}

string extractName(string s)
{
    return s.substr(19);
}

string getFirstName(string s)
{
    int i = s.find("/");
    return s.substr(i+1);
}

string getLastName(string s)
{
    int i = s.find("/");
    return s.substr(0,i);
}

string concatenate(string a, string b)
{
    return a + " " + b;
}

string nameOnCard()
{
    string s = readCard();
    if(s == "quit" || s == "jk")
        return s;
    
    s = extractName(s);
    string temp1 = getFirstName(s);
    string temp2 = getLastName(s);
    s = concatenate(temp1,temp2);
    return s;
}


void printVector(vector<string>& v)
{
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    cout << endl;
}

void fillList(MemberList& l, vector<string>& n, vector<string>& e, vector<string>& p)
{
    for(int i = 0; i < n.size(); ++i)
        l.push(Member(n[i],e[i],p[i]));
}

bool checkList(MemberList& l, string n)
{
    MemberNode* t;
    for(t = l.head; t->next; t = t->next)
    {
        if(t->member.name == n)
        {
            t->member.print();
            attendanceFile << t->member.name << "," << t->member.email << "," << t->member.phone << endl;
            return true;
        }
    }
    cout << "Name: " << n << endl;
    cout << "Member not found." << endl;
    cout << "Please enter UCR email address: ";
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    string e;
    getline(cin,e);//getline
    cout << "Please enter Phone Number: ";
    string p;
    getline(cin,p);// getline
    
    memberFile.clear();
    
    attendanceFile << n << "," << e << "," << p << endl;
    memberFile << endl << n << "," << e << "," << p;
    
    return false;
}

/*
MemberNode* tail(MemberList l)
{
    MemberNode* t = l.head;
    for( ;t->next; t = t->next ) {}
    
    
    return t;
}
*/

void makeAttendanceFile()
{
    cout << "Enter Date (followed with .csv): ";
    string date;
    cin >> date;
    
   // memberFile.open("Members.csv");
    attendanceFile.open(date.c_str());
    
    string d = date.substr(0,date.size()-4);
    
    attendanceFile << d << endl;
    attendanceFile << "NAME,EMAIL,PHONE" << endl;
}

int main()
{
    makeAttendanceFile();
    vector<string>names;
    vector<string>emails;
    vector<string>numbers;

    readFile(names,emails,numbers);
    
    MemberList currentMembers;
    MemberList attendanceList;
    fillList(currentMembers,names,emails,numbers);
    
    string tempName;
    bool exit = 0;
    for( ;!exit; )
    {
        tempName = nameOnCard();
        if(tempName == "quit")
        {
            exit = 1;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            break;
        }
        else
        {
            if(checkList(currentMembers,tempName)) {}
            else
            {
                //add to attendance list
            }
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
    }
    
    
    
    return 0;
}



