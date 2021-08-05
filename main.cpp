//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream>     // It is Used For Basic I/O Operations. 
#include <fstream>      // It is Used For File I/O Operations. 
#include <limits>       // It is Used For Get Numeric Limits. 
#include <cstring>
#include <conio.h>
#include<windows.h>
#include <iomanip>
// It is Used For C String Handling.

using namespace std;


//***************************************************************
//        FUNCTIONs PROTOTYPING THAT USED IN PROJECTS
//****************************************************************


int mainmenu();                     // function that print the Main Menu on Console Screen.
bool validateInput();               // fuction that Validate User Input & Prints Error.
bool isEmpty(ifstream &file);       // function that checks file is empty or not.


int loginprocess();


void operations(int ch);

void empmenu();

void mgrmenu();



//***************************************************************
//                   GLOBAL VARIABLES
//****************************************************************
const char *fileName = "C://ERMS//file.dat";
int logintype;
bool check = true;
int search;
int size;
bool flag;


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class Employee {
private:
    int id, age;
    long long int phoneno;
    char name[100], post[100], department[100], gender[10], city[500];
    double salary;

public:
    // constructor function
    Employee() {
        // Default Initialization Except Garbage Value
        id = 0;
        strcpy(name, "no name");
        strcpy(name, "no post");
        strcpy(name, "no department");
        salary = 0;
    }

    // member function
    void getData();             // function to get Employees Record From User.
    void writeFile();           // function to Write Employees Records in a file that get From User.
    void readFile();            // function to Read Employees Records from a file.
    void showData();            // function to Print All Employees Records that Read From a File.
    void searchData(); // function to search Data from file.
    void updateData(int input); // function to Update Data from file.
    void deleteData(int input); // function to Delete Data from file.
    void sortData();// function to Sorts Employees Data in Desending Order w.r.t Salary.
    void randddep();

    void testdep();

    void traindep();

    void salesdep();

    void accdep();

    void payslip_generator();
};


//***************************************************************
//           DEFINATION OF MEMBER FUNCTIONS OF CLASS
//****************************************************************
void Employee::getData() {
    bool flag = false;

    label1:
    cout << "\tEnter Employee Name : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(name, 100);
    flag = validateInput();
    if (flag)
        goto label1;


    label2:
    cout << "\tEnter Employee Unique ID : ";
    cin >> id;
    flag = validateInput();
    if (flag)
        goto label2;


    label3:
    cout << "\tEnter Employee Gender : ";
    cin >> gender;
    flag = validateInput();
    if (flag)
        goto label3;

    label4:
    cout << "\tEnter Employee Age : ";
    cin >> age;
    flag = validateInput();
    if (flag)
        goto label4;


    label5:
    cout << "\tEnter Employee Role : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(post, 100);
    flag = validateInput();
    if (flag)
        goto label5;


    label6:
    cout << "\tEnter Employee Department : ";
    cin.getline(department, 100);
    flag = validateInput();
    if (flag)
        goto label6;


    label7:
    cout << "\tEnter Employee Salary : ";
    cin >> salary;
    flag = validateInput();
    if (flag)
        goto label7;

    label8:
    cout << "\nEnter Employee Phone number : ";
    cin >> phoneno;
    flag = validateInput();
    if (flag)
        goto label8;

    label9:
    cout << "\nEnter Employee City : ";
    cin >> city;
    flag = validateInput();
    if (flag)
        goto label9;
}

void Employee::writeFile() {
    if (name == "no name" && id == 0) {
        cout << "\tEmployee Record is not initalized" << endl;
    } else {
        fstream file;
        file.open(fileName, ios::out | ios::app | ios::binary);

        file.write((char *) this, sizeof(*this));

        file.close();

        if (!file.good()) {
            // For Check Any Error After Writing the file. For Example File Memory Full, File Format Errors.
            cout << "\tError occurred at writing time!" << endl;
        }
    }
}

void Employee::readFile() {
    ifstream file;
    file.open(fileName, ios::in | ios::binary);

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));
            cout << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                 << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                 << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            cout << endl;
            while (!file.eof()) {
                showData();
                file.read((char *) this, sizeof(*this));
            }

            file.close();
        }
    }
}

void Employee::showData() {


    cout << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8) << left << gender
         << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
         << setw(14) << phoneno << setw(15) << city << endl;


    //    cout << "\tEmployee ID is : ";
    //    cout << id << endl;
    //
    //    cout << "\tEmployee post is : ";
    //    cout << post << endl;
    //
    //    cout << "\tEmployee Department is : ";
    //    cout << department << endl;
    //
    //    cout << "\tEmployee Salary is : ";
    //    cout << salary << endl;


}

void Employee::searchData() {
    bool flag = false;
    int ch;
    char nm[100];
    int input;
    long int phn;
    fstream file;
    file.open(fileName, ios::in | ios::binary);
    cout << "Enter the key on which you want to search\n";
    cout << "1.Name \n 2.ID \n 3.Phone number\n";
    cin >> ch;
    switch (ch) {
        case 1: {
            cout << "Enter the name:";
            cin >> nm;
            if (!file) {
                cout << "\tFile Cannot be Open";
            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                     << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City" << "\n";
                while (!file.eof()) {
                    if (!strcmp(nm, name)) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This ID Does Not Exist";
                }
            }

        }
            break;
        case 2:
            cout << "Enter the ID:";
            cin >> input;

            if (!file) {
                cout << "\tFile Cannot be Open";
            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                     << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
                cout << endl;
                while (!file.eof()) {
                    if (input == id) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This ID Does Not Exist";
                }
            }

            break;
        case 3: {
            cout << "Enter the phone number:";
            cin >> phn;
            if (!file) {
                cout << "\tFile Cannot be Open";
            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                     << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
                cout << endl;

                while (!file.eof()) {
                    if (phn == phoneno) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This ID Does Not Exist";
                }
            }

        }
            break;

    }
}


void Employee::updateData(int input) {
    bool flag = false;
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::ate | ios::binary);

    if (!file) {
        cout << "\tFile Cannot Open Successfully!";
    } else {
        file.seekg(0, ios::beg);
        file.read((char *) this, sizeof(*this));
        while (!file.eof()) {
            if (input == id) {
                showData();
                cout << "\n\tEnter Updated Record :- \n\n";
                getData();
                int position = (-1) * static_cast<int>(sizeof(*this));
                file.seekp(position, ios::cur);
                file.write((char *) this, sizeof(*this));
                flag = true;
            }
            file.read((char *) this, sizeof(*this));
        }

        if (!flag) {
            cout << "\tRecord For This ID Does Not Exist";
        } else {
            cout << "\n\tNew Records Has Been Updated Successfully\n";
        }
    }
}

void Employee::deleteData(int input) {
    int c1, c2;
    bool flag = true;
    ofstream fout;
    ifstream fin;
    fin.open(fileName, ios::in | ios::binary);

    if (!fin) {
        cout << "\tFile Cannot Open Successfully!";
    } else {
        fin.read((char *) this, sizeof(*this));
        fout.open("tempfile.dat", ios::out | ios::binary);
        while (!fin.eof()) {
            if (input != id) {
                fout.write((char *) this, sizeof(*this));
            }
            fin.read((char *) this, sizeof(*this));
        }
        fin.close();
        fout.close();

        fstream f1, f2;
        f1.open(fileName, ios::in | ios::binary);
        f2.open("tempfile.dat", ios::in | ios::binary);

        while (true) {
            c1 = f1.get();
            c2 = f2.get();
            if (c1 != c2) {
                flag = false;
                break;
            }
            if ((c1 == EOF) || (c2 == EOF))
                break;
        }

        f1.close();
        f2.close();

        if (flag) {
            cout << "\tRecord For This ID Does Not Exist";
        } else {
            label:
            fstream file;
            file.open(fileName, ios::in | ios::binary);
            int choice;
            while (file.read((char *) this, sizeof(*this))) {
                if (input == id) {
                    showData();
                }
            }
            file.close();
            cout << "\n\tAre Your Sure to Delete The Above Record\n";
            cout << "\t1 : Yes\n";
            cout << "\t2 : No\n";
            cout << "\tEnter Your Choice : ";
            cin >> choice;
            if (choice == 1) {
                remove(fileName);
                rename("tempfile.dat", fileName);
                cout << "\n\n\tRecord is Deleted Successfully";
            } else if (choice == 2) {
                remove("tempfile.dat");
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tError : Invalid Choice Detected! Please Enter Valid Choice";
                goto label;
            }
        }
    }
}

void Employee::sortData() {
    int ch;
    int size, fileSize, objSize, position;
    Employee *ptr = NULL;

    ifstream file;
    file.open("file.dat", ios::in | ios::binary);

    if (isEmpty(file)) {
        cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
    } else {
        cout << "\n Enter the data on which records are to be sorted:";

        cout << "\n 1.Employee ID\n 2.Name \n 3.Age\n 4.Salary\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                int size, fileSize, objSize, position;
                Employee *ptr = NULL;

                ifstream file;
                file.open("file.dat", ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new Employee[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].id > ptr[j].id) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }

                    cout << "\n\n\t======== Sorted Employee Details With Respect to Salary ========\n\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;   // Explicitly Delete Memory Location From Heap.
                }
                break;
            }

            case 2: {
                int count = 0;
                Employee *ptr = NULL;

                ifstream file;
                ifstream file2;

                file2.open("file.dat", ios::in | ios::binary);
                if (isEmpty(file2)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    while (!file2.eof()) {

                        file2.read((char *) this, sizeof(*this));
                        count++;
                    }
                    count--;
                }


                file.open("file.dat", ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Available to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new Employee[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();


//                    for (int i = 0; i < count; i++) {
//                        for (int j = 0; j < count; j++) {
//                            if (ptr[j - 1].name > ptr[j].name)
//                                swap(ptr[i], ptr[j]);
//                            }
//                        }
//                    }






                    int i = 0, j = 0;
                    for (i = 1; i < count; i++) {
                        for (j = 1; j < count; j++) {
                            if (strcmp(ptr[j - 1].name, ptr[j].name) > 0) {


                                swap(ptr[j], ptr[j - 1]);

                            }
                        }
                    }


                    cout << "\n\n\t======== Sorted Employee Details With Respect to Salary ========\n\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;   // Explicitly Delete Memory Location From Heap.
                }
                break;
            }
            case 3: {
                int size, fileSize, objSize, position;
                Employee *ptr = NULL;

                ifstream file;
                file.open("file.dat", ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new Employee[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].age < ptr[j].age) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }

                    cout << "\n\n\t======== Sorted Employee Details With Respect to Salary ========\n\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;   // Explicitly Delete Memory Location From Heap.
                }
                break;
            }

            case 4: {
                int size, fileSize, objSize, position;
                Employee *ptr = NULL;

                ifstream file;
                file.open("file.dat", ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new Employee[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].id > ptr[j].id) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }

                    cout << "\n\n\t======== Sorted Employee Details With Respect to Salary ========\n\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;   // Explicitly Delete Memory Location From Heap.
                }
                break;
            }
            default:
                cout << "\n Invalid Input ! Please try again !";
        }
    }
}


//***************************************************************
//            FUNCTION DEFINATION USED IN PROJECTS
//****************************************************************
int loginprocess() {

    string uname, pass;
    int ip;

    // system("cls");  !! causing error
    cout << "\n\n <================= Employee Record Management System =================>\n";
    cout << "           .--.                   .---.\n"
            "       .---|__|           .-.     |~~~|\n"
            "    .--|===|--|_          |_|     |~~~|--.\n"
            "    |  |===|  |'\\     .---!~|  .--|   |--|\n"
            "    |%%|   |  |.'\\    |===| |--|%%|   |  |\n"
            "    |%%|   |  |\\.'\\   |   | |__|  |   |  |\n"
            "    |  |   |  | \\  \\  |===| |==|  |   |  |\n"
            "    |  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n"
            "    |  |===|--|   \\.'\\|===|~|--|%%|~~~|--|\n"
            "    ^--^---'--^    `-'`---^-^--^--^---'--'";

    cout << "\n 1. Employee Login \n 2. Manager Log in \n  \n 3.Exit \n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Enter your choice :  \n";
    cin >> logintype;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    switch (logintype) {

        case 1: {
            cout << "\nEmployeee Login\n";
            cout << "\nEnter Employee username : ";
            cin >> uname;
            cout << "\nEnter Employee password : ";
            cin >> pass;

            if (uname != "emp001" || pass != "emp001") {
                cout << "\n Wrong username or password !";
                int ip;
                cout << "\n1.Try again\n2.Exit\nPlease enter your choice : ";
                cin >> ip;
                switch (ip) {
                    case 1:
                        loginprocess();
                        break;
                    case 2:
                        exit(0);
                    default:
                        cout << "\n Invalid input !\n";
                        loginprocess();
                }
                break;
            } else
                // empmenu();
                cout << "\n Login successful !";
            break;
        }
        case 2: {
            cout << "\nManager Login\n";
            cout << "\nEnter Manger  username : ";
            cin >> uname;
            cout << "\nEnter Manager  password : ";
            cin >> pass;
            if (uname != "mgr001" || pass != "mgr001") {
                cout << "\n Wrong username or password !";
                int ip;
                cout << "\n1.Try again\n2.Exit\nPlease enter your choice : ";
                cin >> ip;
                switch (ip) {
                    case 1:
                        loginprocess();
                        break;
                    case 2:
                        exit(0);
                    default:
                        cout << "\n Invalid input !\n";
                        loginprocess();
                }

            } else
                cout << "\n Login successful !";
            break;

        }

        case 3:
            cout << "Thank you for using the system !";
            exit(0);

        default:
            cout << "\nInvalid input ! try again !";
            loginprocess();
    }

    return 1;

}


void mgrmenu() {
    // system("cls"); causing errors
    int choice;

    bool flag;
    cout << "\n\n <================= Employee Managment System =================>\n\n";
    cout << "\tPlease Select Your Choice :- \n";
    cout << "\t1 : Insert Employees Records\n";
    cout << "\t2 : View All Employees Records\n";
    cout << "\t3 : Search Employees Records\n";
    cout << "\t4 : Update Employee Records\n";
    cout << "\t5 : Delete Employee Records\n";
    cout << "\t6 : Sort Employee Records \n";
    cout << "\t7 : Generate Reports\n";
    cout << "\t8 : Payslip Generator";
    cout << "\t9 : Logout \n";
    cout << "\tEnter Your Choice : \n\n\n";
    cin >> choice;
    operations(choice);
    mgrmenu();


}


void empmenu() {

    int choice;
    cout << "\n\n <================= Employee Managment System =================>\n\n";
    cout << "\tPlease Select Your Choice :- \n";
    cout << "\t1 : View All Employees Records\n";
    cout << "\t2 : Search Employees Records\n";
    cout << "\t3 : Sort Employee Records\n";
    cout << "\t4 : Logout \n";
    cout << "\tEnter Your Choice : \n\n\n";
    cin >> choice;

    switch (choice) {
        case 1:
            operations(2);
            break;
        case 2:
            operations(3);
            break;
        case 3:
            operations(6);
            break;
        case 4:
            loginprocess();
            break;
        default:
            cout << "\nInvalid choice !";
            empmenu();
            break;

    }


}

bool validateInput() {
    /* Why do we use:
         1) cin.ignore
         2) cin.clear

         1) To ignore (extract and discard) values that we don't want on the stream.
         2) To clear the internal state of stream. After using cin.clear internal state is set again back to goodbit, which means that there are no 'errors'.

         Long version:
         If something is put on 'stream' (cin) then it must be taken from there. By 'taken' we mean 'used', 'removed', 'extracted' from stream. Stream has a flow. The data is flowing on cin like water on stream. You simply cannot stop the flow of water.
    */

    if (cin.fail()) {
        // Restore input stream
        cin.clear();
        // Clear The All Previous Input Before the '\n' Character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Throwing Error and Again Input Value From User
        cout << "\n\tError : inValid Value Detected! Please Enter Valid Value Again\n\n";

        return true;
    } else {
        return false;
    }
}

bool isEmpty(ifstream &file) {
    /*
    The peek() function looks into the input stream and tells us what the next character is without removing it from the input stream. Moreover, the peek() function can store the character in a designated memory locatio without actually removing it from the stream.
    */

    return (file.peek() == ifstream::traits_type::eof());
}


void operations(int ch) {
    //system("cls"); !!causing error
    int dp;

    Employee *ptr = NULL;
    Employee filedata;

    switch (ch) {
        case 1: //addrecords
        label:
            cout << "\tHow Many Employees Records that You Want to Store : ";
            cin >> size;

            flag = validateInput();

            if (flag) {
                goto label;
            } else {
                ptr = new Employee[size];

                for (int i = 0; i < size; i++) {
                    cout << "\n\n\tEnter the Details For the Employee # " << i + 1 << endl;
                    ptr[i].getData();
                }

                for (int i = 0; i < size; i++) {
                    ptr[i].writeFile();
                }

                delete[] ptr;  // Explicitly Delete Memory Location From Heap.

                cout << "\n\tNew Records Has Been Added Successfully\n";
                break;
            }
        case 2: //view all records

            cout << "\n\n\t=============== Employee Details ==================\n\n";
            filedata.readFile();
            break;
        case 3: //search records
            //cout << "\nPlease Enter Employee Unique ID That you Want to Search its Record : ";
            //
            // cin >> search;
            filedata.searchData();
            break;
        case 4: //update records
            cout << "\tPlease Enter Employee Unique ID That you Want to Update its Record : ";
            cin >> search;
            filedata.updateData(search);
            break;
        case 5: //delete records
            cout << "\tPlease Enter Employee Unique ID you Want to Delete its Record : ";
            cin >> search;
            filedata.deleteData(search);
            break;
        case 6: //sort records
            filedata.sortData();
            break;
        case 7: //report generation
            cout << "Enter the Depart name of which you want the report\n";
            cout << "1.R&D\n2.Testing\n3.Training\n4Sales\n5.Accounts\n";
            cin >> dp;

            switch (dp) {
                case 1:
                    filedata.randddep();
                    break;
                case 2:
                    filedata.testdep();
                    break;
                case 3:
                    filedata.traindep();
                    break;
                case 4:
                    filedata.salesdep();
                    break;
                case 5:
                    filedata.accdep();
                    break;
                default:
                    cout << "Please give correct input " << endl;
            }
            break;

        case 8 :filedata.payslip_generator();
            break;
        case 9:
            cout << "\n\tThank You For Using This Application\n";
            exit(0);
            check = false;
            break; //invalid input
        default:
            cout << "\tInvalid Choice! Please Select Valid Choice.";
            break;
    }
    cout << "\n";
    cout << "\t" << system("pause");
}

void Employee::payslip_generator() {

    int input;
    fstream file;
    float basic_salary, hra, da, i_tax, net_salary;
    file.open(fileName, ios::in | ios::binary);
    cout << "Enter the Employee ID:";
    cin >> input;
    flag = validateInput();
    if(flag){
        cout<<"Enter correct id!!";
        mgrmenu();
    }else{




        if (!file) {
            cout << "\tFile Cannot be Open";
        } else {
            file.read((char *) this, sizeof(*this));
            while (!file.eof()) {
                if (input == id) {


                    basic_salary = salary;
                    hra = 800;
                    da = 0.25 * basic_salary;
                    i_tax = 0.15 * basic_salary;
                    net_salary = basic_salary + da + hra - i_tax;

                    cout<<"\n -------------------------------------- ";
                    cout<<"\n Employee Id     : "<<id;
                    cout<<"\n Employee Name   : "<<name;
                    cout<<"\n Basic Salary    : "<<basic_salary;
                    cout<<"\n HRA             : "<<hra;
                    cout<<"\n DA              : "<<da;
                    cout<<"\n I-Tax           : "<<i_tax;
                    cout<<"\n Net Salary      : "<<net_salary;
                    cout<<"\n -------------------------------------- ";
                    flag = true;
                }
                file.read((char *) this, sizeof(*this));
            }

            file.close();

            if (!flag) {
                cout << "\tRecord For This ID Does Not Exist";
            }
        }
    }




}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main() {


    int flag = loginprocess();
    switch (logintype) {
        case 1:
            empmenu();
            break;
        case 2:
            //  cout<<"case 2 called";
            mgrmenu();
            break;
        default:
            cout << "\nError occurred !";
            exit(0);

    }
}

void Employee::randddep() {
    ifstream file;
    int noofemployee = 0, maleemp = 0, femaleemp = 0, ttlsal = 0, ttlage = 0, highsal = 0, lowsal = 0;
    int x, i;
    char title[20] = "R and D Department";
    file.open(fileName, ios::in | ios::binary);
    fstream report;
    report.open("C://ERMS//rnd_dept_report.txt", ios::out); //writes to the output file
    //report.getline(title,25,'\n');
    //if(report.fail())
    //    break;
    //x=strlen(title);
    report << title;
    report << endl;

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));

            report << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                   << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                   << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            report << "\n";

            while (!file.eof()) {

                if (!strcmp(department, "R&D")) {
                    noofemployee++;

                    report << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8)
                           << left << gender
                           << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
                           << setw(14) << phoneno << setw(15) << city << endl;

                    ttlsal += salary;
                    ttlage += age;

                    if (!strcmp(gender, "M")) {
                        maleemp++;
                    } else {
                        femaleemp++;
                    }

                    if (noofemployee == 1) {
                        highsal = salary;
                        lowsal = salary;
                    }
                    if (salary > highsal) {
                        highsal = salary;
                    }
                    if (salary < lowsal) {
                        lowsal = salary;
                    }
                }

                file.read((char *) this, sizeof(*this));
            }
            report << endl;
            report << "Total no of employees = " << noofemployee;
            report << endl;
            report << "no of male employees = " << maleemp;
            report << endl;
            report << "no of female employees = " << femaleemp << endl;
            report << "Average salary = " << ttlsal / noofemployee << endl;
            report << "Average Age = " << ttlage / noofemployee << endl;
            cout << endl;
            report << "Highest Salary = " << highsal << endl;
            report << "Lowest Salary = " << lowsal << endl;
            report.close();
            file.close();
            cout << "Report generated successfully !";
            return;
        }


    }
}


void Employee::testdep() {
    ifstream file;
    int noofemployee = 0, maleemp = 0, femaleemp = 0, ttlsal = 0, ttlage = 0, highsal = 0, lowsal = 0;
    int x, i;
    char title[20] = "Testing Department";
    file.open(fileName, ios::in | ios::binary);
    fstream report;
    report.open("C://ERMS//test_dept_report.txt", ios::out); //writes to the output file
    //report.getline(title,25,'\n');
    //if(report.fail())
    //    break;
    //x=strlen(title);
    report << title;
    report << endl;

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));

            report << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                   << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
                   << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            report << "\n";

            while (!file.eof()) {

                if (!strcmp(department, "Testing")) {
                    noofemployee++;

                    report << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8)
                           << left << gender
                           << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
                           << setw(14) << phoneno << setw(15) << city << endl;

                    ttlsal += salary;
                    ttlage += age;

                    if (!strcmp(gender, "M")) {
                        maleemp++;
                    } else {
                        femaleemp++;
                    }

                    if (noofemployee == 1) {
                        highsal = salary;
                        lowsal = salary;
                    }
                    if (salary > highsal) {
                        highsal = salary;
                    }
                    if (salary < lowsal) {
                        lowsal = salary;
                    }
                }

                file.read((char *) this, sizeof(*this));
            }
            report << endl;
            report << "Total no of employees = " << noofemployee;
            report << endl;
            report << "No of male employees = " << maleemp;
            report << endl;
            report << "No of female employees = " << femaleemp << endl;
            report << "Average salary = " << ttlsal / noofemployee << endl;
            report << "Average Age = " << ttlage / noofemployee << endl;
            cout << endl;
            report << "Highest Salary = " << highsal << endl;
            report << "Lowest Salary = " << lowsal << endl;
            report.close();
            file.close();
            cout << "Report generated successfully !";
            mgrmenu();
        }


    }
}

void Employee::traindep() {

    ifstream file;
    int noofemployee = 0, maleemp = 0, femaleemp = 0, ttlsal = 0, ttlage = 0, highsal = 0, lowsal = 0;
    int x, i;
    char title[20] = "Training Department";
    file.open(fileName, ios::in | ios::binary);
    fstream report;
    report.open("C://ERMS//training_dept_report.txt", ios::out); //writes to the output file
    //report.getline(title,25,'\n');
    //if(report.fail())
    //    break;
    //x=strlen(title);
    report << title;
    report << endl;

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));

            report << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
            << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
            << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            report << "\n";

            while (!file.eof()) {

                if (!strcmp(department, "Training")) {
                    noofemployee++;

                    report << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8)
                    << left << gender
                    << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
                    << setw(14) << phoneno << setw(15) << city << endl;

                    ttlsal += salary;
                    ttlage += age;

                    if (!strcmp(gender, "M")) {
                        maleemp++;
                    } else {
                        femaleemp++;
                    }

                    if (noofemployee == 1) {
                        highsal = salary;
                        lowsal = salary;
                    }
                    if (salary > highsal) {
                        highsal = salary;
                    }
                    if (salary < lowsal) {
                        lowsal = salary;
                    }
                }

                file.read((char *) this, sizeof(*this));
            }
            report << endl;
            report << "Total no of employees = " << noofemployee;
            report << endl;
            report << "No of male employees = " << maleemp;
            report << endl;
            report << "No of female employees = " << femaleemp << endl;
            report << "Average salary = " << ttlsal / noofemployee << endl;
            report << "Average Age = " << ttlage / noofemployee << endl;
            cout << endl;
            report << "Highest Salary = " << highsal << endl;
            report << "Lowest Salary = " << lowsal << endl;
            report.close();
            file.close();
            cout << "Report generated successfully !";
            mgrmenu();
        }


    }
}

void Employee::accdep() {

    ifstream file;
    int noofemployee = 0, maleemp = 0, femaleemp = 0, ttlsal = 0, ttlage = 0, highsal = 0, lowsal = 0;
    int x, i;
    char title[20] = "Accounts Department";
    file.open(fileName, ios::in | ios::binary);
    fstream report;
    report.open("C://ERMS//acc_dept_report.txt", ios::out); //writes to the output file
    //report.getline(title,25,'\n');
    //if(report.fail())
    //    break;
    //x=strlen(title);
    report << title;
    report << endl;

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));

            report << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
            << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
            << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            report << "\n";

            while (!file.eof()) {

                if (!strcmp(department, "Accounts")) {
                    noofemployee++;

                    report << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8)
                    << left << gender
                    << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
                    << setw(14) << phoneno << setw(15) << city << endl;

                    ttlsal += salary;
                    ttlage += age;

                    if (!strcmp(gender, "M")) {
                        maleemp++;
                    } else {
                        femaleemp++;
                    }

                    if (noofemployee == 1) {
                        highsal = salary;
                        lowsal = salary;
                    }
                    if (salary > highsal) {
                        highsal = salary;
                    }
                    if (salary < lowsal) {
                        lowsal = salary;
                    }
                }

                file.read((char *) this, sizeof(*this));
            }
            report << endl;
            report << "Total no of employees = " << noofemployee;
            report << endl;
            report << "No of male employees = " << maleemp;
            report << endl;
            report << "No of female employees = " << femaleemp << endl;
            report << "Average salary = " << ttlsal / noofemployee << endl;
            report << "Average Age = " << ttlage / noofemployee << endl;
            cout << endl;
            report << "Highest Salary = " << highsal << endl;
            report << "Lowest Salary = " << lowsal << endl;
            report.close();
            file.close();
            cout << "Report generated successfully !";
            mgrmenu();
        }


    }



}

void Employee::salesdep() {

    ifstream file;
    int noofemployee = 0, maleemp = 0, femaleemp = 0, ttlsal = 0, ttlage = 0, highsal = 0, lowsal = 0;
    int x, i;
    char title[20] = "Sales Department";
    file.open(fileName, ios::in | ios::binary);
    fstream report;
    report.open("C://ERMS//sales_dept_report.txt", ios::out); //writes to the output file
    //report.getline(title,25,'\n');
    //if(report.fail())
    //    break;
    //x=strlen(title);
    report << title;
    report << endl;

    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));

            report << setw(12) << left << "Employee ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
            << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left << "Department"
            << setw(10) << "Salary" << setw(15) << "Phoneno" << setw(14) << "City";
            report << "\n";

            while (!file.eof()) {

                if (!strcmp(department, "Sales")) {
                    noofemployee++;

                    report << setw(12) << left << id << setw(20) << left << name << setw(5) << left << age << setw(8)
                    << left << gender
                    << setw(20) << left << post << setw(15) << left << department << setw(10) << salary
                    << setw(14) << phoneno << setw(15) << city << endl;

                    ttlsal += salary;
                    ttlage += age;

                    if (!strcmp(gender, "M")) {
                        maleemp++;
                    } else {
                        femaleemp++;
                    }

                    if (noofemployee == 1) {
                        highsal = salary;
                        lowsal = salary;
                    }
                    if (salary > highsal) {
                        highsal = salary;
                    }
                    if (salary < lowsal) {
                        lowsal = salary;
                    }
                }

                file.read((char *) this, sizeof(*this));
            }
            report << endl;
            report << "Total no of employees = " << noofemployee;
            report << endl;
            report << "No of male employees = " << maleemp;
            report << endl;
            report << "No of female employees = " << femaleemp << endl;
            report << "Average salary = " << ttlsal / noofemployee << endl;
            report << "Average Age = " << ttlage / noofemployee << endl;
            cout << endl;
            report << "Highest Salary = " << highsal << endl;
            report << "Lowest Salary = " << lowsal << endl;
            report.close();
            file.close();
            cout << "Report generated successfully !";
            mgrmenu();
        }


    }



}