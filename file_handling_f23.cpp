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
    void AddNewRecord(Student_data rec1);
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
    AddNewRecord(stud_rec); // add initial record
    file.close();
}

void Database_file::AddNewRecord(Student_data rec1)
{
    int n,i,k;
    fstream file("Student_data.dat", ios::out | ios::in);
    rec1.status=0;
    file.seekg(0,ios::end);
    n= file.tellg()/sizeof(Student_data);

    if(n==0)
    {
        file.write((char*)&rec1,sizeof(Student_data));
        file.close();
        return;
    }
    i = n-1;

    while(i>=0)
    {
        file.seekg(i*sizeof(Student_data),ios::beg);
        file.read((char*)&stud_rec,sizeof(Student_data));
        if(stud_rec.Roll_number>rec1.Roll_number)
        {
            file.seekp(i+1*sizeof(Student_data),ios::beg);
            file.write((char*)&stud_rec,sizeof(Student_data));
        }
        else
            break;
        i--;
    }
    i++;
    file.seekp(i*sizeof(Student_data),ios::beg);
    file.write((char*)&rec1,sizeof(Student_data));
    file.close();    
}

void Database_file::DisplayFileContent()
{
    int i = 1,n;
    fstream file("Student_data.dat", ios::in | ios::binary);
    file.seekg(0,ios::end);
    n=file.tellg()/sizeof(Student_data);
    file.seekg(0,ios::beg);
    for(i=1;i<=n;i++)
    {
        file.read((char*)&stud_rec,sizeof(stud_rec));
        if(stud_rec.status==0)
        cout<<stud_rec.Roll_number<<" "<<stud_rec.Name<<" "<<stud_rec.Division<<" "<<stud_rec.Address<<endl;
        else
        cout<<"Record deleted"<<endl;
    }
    file.close();
}

void Database_file::DeleteRecord()
{
    int i,n;
    fstream file("Student_data.dat", ios::out | ios::in);
    file.seekg(0,ios::)
    

}










