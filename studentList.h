#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class studentList {
private:
  // string fname;
  // string lname;
  string fullname;
  string studentID;
  string email;

public:
  studentList();
  // studentList(string fn, string ln, string ID, string address);
  // void setfname(string fn);
  // void setlname(string ln);
  studentList(string fn, string ID, string address);
  void setfullname(string fn);
  bool setID(string ID);
  bool setemail(string address);
  // string getfname();
  // string getlname();
  string getfullname();
  string getID();
  string getemail();
  void display();
};

studentList::studentList() {
  // fname = "N/A";
  // lname = "N/A";
  fullname = "N/A";
  studentID = "N/A";
  email = "N/A";
}
// studentList::studentList(string fn, string ln, string ID, string address) {
//     fname=fn;
//     lname=ln;
//     studentID=ID;
//     email=address;
// }
// void studentList::setfname(string fn) {
//     fname=fn;
// }
// void studentList::setlname(string ln) {
//     lname=ln;
// }
void studentList::setfullname(string fn) { fullname = fn; }
bool studentList::setID(string ID) {
  if (ID.length() == 7) {
    studentID = ID;
    return true;
  } else
    return false;
}
bool studentList::setemail(string address) {
  for (unsigned int i = 0; i < address.length(); i++)
    if (address.at(i) == '@') {
      email = address;
      return true;
    }
  return false;
}
// string studentList::getfname() {
//     return fname;
// }
// string studentList::getlname() {
//     return lname;
// }
string studentList::getfullname() { return fullname; }
string studentList::getID() { return studentID; }
string studentList::getemail() { return email; }
void studentList::display() {
  cout << left << setw(25) << fullname << left << setw(10) << studentID << left
       << setw(30) << email << endl;
}
#endif // STUDENTLIST_H