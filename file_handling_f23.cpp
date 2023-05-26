/*Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data.*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student_data
{
    int Roll_number;
    string Name, Address;
    char Division;
    int status;
};

class Database_file
{
private:
    Student_data stud_rec;

public:
    void CreateAFile();
    void AddNewRecord();
    void DisplayFileContent();
    void SearchRecord();
    void ModifyRecord();
    void DeleteRecord();
};

void Database_file::CreateAFile()
{
    ifstream file_exist("Student_data.dat");
    if (file_exist) // validity to check if file needs to be created again or exits already
    {
        cout << "\nFile 'Student_data.dat' already exist in this directory !\nFile contents are...";
        Database_file::DisplayFileContent();
        return;
    }
    fstream file("Student_data.dat", ios::out | ios::binary); // open file in write mode to create new database
    cout << "\nNew file Student_data.dat created..\n";
    AddNewRecord(); // add initial record
    file.close();
}

void Database_file::AddNewRecord()
{
    cout << "\nFill student details :\nRoll No. : ";
    cin >> stud_rec.Roll_number;
    cin.ignore();
    fstream write_file("Student_data.dat", ios::app | ios::binary); // open file in append mode
    fstream read_file("Student_data.dat", ios::in | ios::binary);   // open file in read with different pointer
    Student_data d1;
    read_file.read((char*)&d1,sizeof(d1));
    

}
