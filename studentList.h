#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class studentList {
  private:
    string fname;
    string lname;
    string studentID;
    string email;
  public:
    studentList();
    studentList(string fn, string ln, string ID, string address);
    void setfname(string fn);
    void setlname(string ln);
    bool setID(string ID);
    bool setemail(string address);
    string getfname();
    string getlname();
    string getID();
    string getemail();
    void display();
};

studentList::studentList() {
    fname="N/A";
    lname="N/A";
    studentID="N/A";
    email="N/A";
}
studentList::studentList(string fn, string ln, string ID, string address) {
    fname=fn;
    lname=ln;
    studentID=ID;
    email=address;
}
void studentList::setfname(string fn) {
    fname=fn;
}
void studentList::setlname(string ln) {
    lname=ln;
}
bool studentList::setID(string ID) {
    if(ID.length()==7) {
        studentID=ID;
        return true;
    } else return false;
}
bool studentList::setemail(string address) {
    for(unsigned int i=0; i<address.length(); i++)
        if(address.at(i)=='@') {
            email=address;
            return true;
        }
    return false;
}
string studentList::getfname() {
    return fname;
}
string studentList::getlname() {
    return lname;
}
string studentList::getID() {
    return studentID;
}
string studentList::getemail() {
    return email;
}
void studentList::display() {
    string fullname=fname+" "+lname;
    cout<<left<<setw(25)<<fullname<<left<<setw(10)<<studentID<<left<<setw(30)<<email<<endl;
}
#endif // STUDENTLIST_H
