#include "studentList.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
  studentList sheet[100];
  int memberCount = 0;
  ifstream list("dataSheet.csv");
  if (!list.is_open())
    cout << "ERROR\n";
  // string firstName;
  // string lastName;
  string fullname;
  string IDnum;
  string emailadd;
  string total;
  getline(list, total, '\n');
  int totalMember;
  istringstream(total) >> totalMember;
  while (memberCount < totalMember) {
    // getline(list, firstName, ',');
    // getline(list, lastName, ',');
    getline(list, fullname, ',');
    getline(list, IDnum, ',');
    getline(list, emailadd, '\n');
    // sheet[memberCount].setfname(firstName);
    // sheet[memberCount].setlname(lastName);
    sheet[memberCount].setfullname(fullname);
    if (sheet[memberCount].setID(IDnum))
      ;
    if (sheet[memberCount].setemail(emailadd))
      ;
    memberCount++;
  }
  list.close();
  int signin[100];
  int logged = 0;
  bool found = false;
  bool flag = true;
  while (flag) {
    cout << "+===========================+\n";
    cout << "| 1. Sign In                |\n";
    // cout << "| 2. Change your first name |\n";
    // cout << "| 3. Change your last name  |\n";
    cout << "| 2. Change your name       |\n";
    cout << "| 3. Change your ID         |\n";
    cout << "| 4. Change your email      |\n";
    cout << "| 5. Display signed in      |\n";
    cout << "| 99. Exit                  |\n";
    cout << "+===========================+\n";
    string select;
    cout << "Please enter the number of operation: ";
    getline(cin, select);
    switch (stoi(select)) {
    case 1:
      cout << "Please enter your student ID: ";
      getline(cin, IDnum);
      if (IDnum.length() != 7) {
        cout << "Looks like your ID number is invalid, please try again.\n";
        while (IDnum.length() != 7) {
          cout << "Please enter your student ID: ";
          getline(cin, IDnum);
        }
      }
      for (int i = 0; i < memberCount; i++) {
        if (sheet[i].getID() == IDnum) {
          found = true;
          signin[logged] = i;
          logged++;
          cout << "\nHi! " << sheet[i].getfullname() << ", welcome!\n\n";
        }
      }
      if (!found) {
        cout << "\nLooks like you are not in the record, do you want to create "
                "an account?\nEnter 1 for Yes, 0 for No: ";
        string createSel;
        getline(cin, createSel);
        if (stoi(createSel) == 1) {
          sheet[memberCount].setID(IDnum);
          cout << "Please enter your full name: ";
          // getline(cin, firstName);
          // sheet[memberCount].setfname(firstName);
          // cout << "Please enter your last name: ";
          // getline(cin, lastName);
          // sheet[memberCount].setlname(lastName);
          getline(cin, fullname);
          sheet[memberCount].setfullname(fullname);
          cout << "Please enter your email address: ";
          getline(cin, emailadd);
          if (!sheet[memberCount].setemail(emailadd)) {
            cout << "Sorry, looks like your email is invalid, please try "
                    "again.\n";
            while (!sheet[memberCount].setemail(emailadd)) {
              cout << "Please enter your email address: ";
              getline(cin, emailadd);
            }
          }
          cout << "Great! " << sheet[memberCount].getfullname()
               << ", you all set!\n";
          signin[logged] = memberCount;
          logged++;
          memberCount++;
        } else {
          cout << "Okay, cool.\n";
        }
      }
      found = false;
      break;
    case 2:
      cout << "Please enter your student ID: ";
      getline(cin, IDnum);
      if (IDnum.length() != 7) {
        cout << "Looks like your ID number is invalid, please try again.\n";
        while (IDnum.length() != 7) {
          cout << "Please enter your student ID: ";
          getline(cin, IDnum);
        }
      }
      for (int i = 0; i < memberCount; i++) {
        if (sheet[i].getID() == IDnum) {
          found = true;
          cout << "We found your account: " << sheet[i].getfullname() << endl;
          cout << "Enter new full name: ";
          getline(cin, fullname);
          sheet[i].setfullname(fullname);
          cout << "Great, you all set!\n";
        }
      }
      if (!found)
        cout << "Sorry, looks like your ID is not in the record.\n";
      found = false;
      break;
    // case 3:
    //   cout << "Please enter your student ID: ";
    //   getline(cin, IDnum);
    //   if (IDnum.length() != 7) {
    //     cout << "Looks like your ID number is invalid, please try again.\n";
    //     while (IDnum.length() != 7) {
    //       cout << "Please enter your student ID: ";
    //       getline(cin, IDnum);
    //     }
    //   }
    //   for (int i = 0; i < memberCount; i++) {
    //     if (sheet[i].getID() == IDnum) {
    //       found = true;
    //       cout << "We found your account: " << sheet[i].getfname() << " "
    //            << sheet[i].getlname() << endl;
    //       cout << "Enter new last name: ";
    //       getline(cin, lastName);
    //       sheet[i].setlname(lastName);
    //       cout << "Great, you all set!\n";
    //     }
    //   }
    //   if (!found)
    //     cout << "Sorry, looks like your ID is not in the record.\n";
    //   found = false;
    //   break;
    case 3:
      cout << "Please enter your student ID: ";
      getline(cin, IDnum);
      if (IDnum.length() != 7) {
        cout << "Looks like your ID number is invalid, please try again.\n";
        while (IDnum.length() != 7) {
          cout << "Please enter your student ID: ";
          getline(cin, IDnum);
        }
      }
      for (int i = 0; i < memberCount; i++) {
        if (sheet[i].getID() == IDnum) {
          found = true;
          cout << "We found your account: " << sheet[i].getfullname() << endl;
          cout << "Enter new ID number: ";
          getline(cin, IDnum);
          if (IDnum.length() != 7) {
            cout << "Looks like your ID number is invalid, please try again.\n";
            while (IDnum.length() != 7) {
              cout << "Please enter your student ID: ";
              getline(cin, IDnum);
            }
          }
          sheet[i].setID(IDnum);
          cout << "Great, you all set!\n";
        }
      }
      if (!found)
        cout << "Sorry, looks like your ID is not in the record.\n";
      found = false;
      break;
    case 4:
      cout << "Please enter your student ID: ";
      getline(cin, IDnum);
      if (IDnum.length() != 7) {
        cout << "Looks like your ID number is invalid, please try again.\n";
        while (IDnum.length() != 7) {
          cout << "Please enter your student ID: ";
          getline(cin, IDnum);
        }
      }
      for (int i = 0; i < memberCount; i++) {
        if (sheet[i].getID() == IDnum) {
          found = true;
          cout << "We found your account: " << sheet[i].getfullname() << endl;
          cout << "Enter new email address: ";
          getline(cin, emailadd);
          if (!sheet[i].setemail(emailadd)) {
            cout << "Looks like your email address is invalid, please try "
                    "again.\n";
            while (!sheet[i].setemail(emailadd)) {
              cout << "Enter new email address: ";
              getline(cin, emailadd);
            }
          } else
            ;
          cout << "Great, you all set!\n";
        }
      }
      if (!found)
        cout << "Sorry, looks like your ID is not in the record.\n";
      found = false;
      break;
    case 5:
      for (int i = 0; i < logged; i++)
        sheet[signin[i]].display();
      break;
    case 99:
      flag = false;
      break;
    default:
      cout << "Sorry, the number you enter is invalid.\n";
    }
  }
  ofstream memberSheet;
  if (remove("dataSheet.csv"))
    ;
  memberSheet.open("dataSheet.csv", ios::app);
  memberSheet << memberCount << "\n";
  for (int i = 0; i < memberCount; i++)
    memberSheet << sheet[i].getfullname() << "," << sheet[i].getID() << ","
                << sheet[i].getemail() << "\n";
  memberSheet.close();
  ofstream outData;
  cout << "Enter today's date: ";
  string date;
  getline(cin, date);
  outData.open(date + " Sign In Sheet.csv", ios::app);
  for (int i = 0; i < logged; i++)
    outData << sheet[signin[i]].getfullname() << "," << sheet[signin[i]].getID()
            << "," << sheet[signin[i]].getemail() << "\n";
  outData.close();
  return 0;
}
