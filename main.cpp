// Header Files
#include <iostream> // For Basic I/O
using namespace std;

int mainmenu(); // fn that prints main menu on the output console


bool validateInput();

// class used in pgrm
class Employee
{

};




int main() {
   mainmenu();
    return 0;
}

int mainmenu(){

    int choice;
    bool flag;
    cout << "\n\n <================= Employee Managment System =================>\n\n";
    cout << "\tPlease Select Your Choice :- \n";
    cout << "\t1 : Insert Employees Records\n";
    cout << "\t2 : View All Employees Records\n";
    cout << "\t3 : Search Employees Records\n";
    cout << "\t4 : Update Employee Records\n";
    cout << "\t5 : Delete Employee Records\n";
    cout << "\t6 : Exit Application\n";
    label:
    cout << "\tEnter Your Choice : ";
    cin >> choice;

    flag = validateInput();
    if (flag)
        goto label;
    else
        return choice;

}

bool validateInput() {
    //TODO
    return false;
}
