#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "userClass.cpp"
using namespace std;

inline bool match(char c, int arr[], int n)
{
    for(int i=0;i<n;i++)
        if(((int)c-'0') == arr[i])
            return true;
    return false;
}

inline int input(int arr[], int n)
{
    char c;
    cin >> c;
    while(!match(c, arr, n))
    {
        cout << "Moi ban nhap lai: ";
        cin >> c;
    }
    return c - '0';
}

inline int generalMenu(){

	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Dang nhap                                  *\n";
	cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1 hoac 9                             *\n";
	cout<<"**************************************************\n";
    int choice[2] = {1,9};
    int number = input(choice, 2);
    return number;
}


inline int residentMenu(){
	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Check in.                        		    *\n";
	cout<<"*  2. Check out.                 	        	*\n";
	cout<<"*  3. Dang xuat                                  *\n";
	cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1,2,3 hoac 9                         *\n";
	cout<<"**************************************************\n";
    int choice[4] = {1,2,3,9};
    int number = input(choice, 4);
    return number;
}

inline int managerMenu(){
	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Check in.                                  *\n";
	cout<<"*  2. Check out.                                 *\n";
	cout<<"*  3. Chinh sua danh sach nguoi dung             *\n";
	cout<<"*  4. Hien thi danh sach ra vao                  *\n";
	cout<<"*  5. Hien thi danh sach quan ly                 *\n";
	cout<<"*  6. Hien thi danh sach nhan vien               *\n";
	cout<<"*  7. Hien thi danh sach nguoi o.                *\n";
	cout<<"*  8. Dang xuat                                  *\n";
	cout<<"*  9. thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1->9                                 *\n";
	cout<<"**************************************************\n";
	int choice[9] = {1,2,3,4,5,6,7,8,9};
    int number = input(choice, 9);
    return number;
}

inline int editMenu(){

    cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Them nguoi dung                            *\n";
	cout<<"*  2. Xoa nguoi dung                             *\n";
	cout<<"*  3. Sua thong tin nguoi dung                   *\n";
	cout<<"*  4. Tro lai                                    *\n";
    cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap lua chon:                            *\n";
	cout<<"**************************************************\n";
	int choice[5] = {1,2,3,4,9};
    int number = input(choice, 5);
    return number;
}

class Command
{
private:
  //  vector<Logs> logs
    vector<USER> usersList;
    USER user;

public:
    int choose;
    Command() //Khoi tao du lieu ban dau
    {
        USER u1("QL0001","Nguyen Duc Manh",30,0,1,false);
        USER u2("QL1002","Nguyen Thi Mai Trang",35,1,1,false);
        USER u3("CD0003","Nguyen Hoa Son",40,0,2,false);
        USER u4("CD0004","Nguyen Van Hieu",20,0,2,false);
        USER u5("CD0005","Nguyen Van Chi",10,0,2,false);
        USER u6("NV1006","Pham Thi Thao",19,1,3,false);
        USER u7("NV2007","Doan Anh Tuan",20,2,3,false);
        USER u8("QL1008","Hoang Thu A",45,1,1,false);
        usersList.push_back(u1);
        usersList.push_back(u2);
        usersList.push_back(u3);
        usersList.push_back(u4);
        usersList.push_back(u5);
        usersList.push_back(u6);
        usersList.push_back(u7);
        usersList.push_back(u8);
    };

    void logIn(); //Thuc hien dang nhap
    bool checkId(); //Kiem tra id nhap vao
    int checkRole(); //Kiem tra role
    void checkIn(); //Thuc hien checkin (status = true)
    void checkOut(); //Thuc hien checkout (status = false)
    void deleteUser(); //Xoa nguoi dung
    void editUser(); //Sua thong tin nguoi dung
    void addUser(); //Them nguoi dung
    void getEmployeeList(); //In ra danh sach nhan vien
    void getResidentList(); //In ra danh sach nguoi o
    void getManagerList(); //In ra danh sach quan ly
    void editing(); //View in ra de edit nguoi dung
    void managerView(); //View in ra danh cho manager
    void residentView(); // View in ra danh cho nguoi o
};

inline void Command::logIn()
{
    user.inPut();
    if(!checkId())
        cout << "Id khong dung, nhan Enter de tiep tuc!" << endl;
    else
        cout << "Ban da dang nhap thanh cong, nhan Enter de tiep tuc!" << endl;
};

inline bool Command::checkId()
{
    for(int i=0;i<usersList.size();i++)
        if(user.getId() == usersList[i].getId())
            return 1;
        return 0;
}

inline int Command::checkRole()
{
    for(int i=0;i<usersList.size();i++)
    {
        if(user.getId() == usersList[i].getId())
            return usersList[i].getRole();
    }
    return 0;
}

inline void Command::checkIn()
{
    if(checkId())
    {
        user.setStatus(true);
        cout<<"Ban da di vao!"<<endl;
        getch();
    }
}

inline void Command::checkOut()
{
    user.setStatus(false);
    cout<<"Ban da di ra!"<<endl;
    getch();
}

inline void Command::deleteUser()
{
    cout<<"Nhap ID nguoi dung can xoa:";
    string deleId;
    cin>>deleId;
    for(int i=0;i<usersList.size();i++){
        if(deleId==usersList[i].getId()){
           usersList.erase(usersList.begin()+i);
        }
    }
}

inline void Command::editUser()
{
    cout<<"Nhap ID nguoi dung can chinh sua:";
    string editId;
    cin>>editId;
    for(int i=0;i<usersList.size();i++)
    {
        if(editId == usersList[i].getId())
        {
            string newId;
            string newName;
            int newAge;
            int newGender;
            int newRole;
            cout<<"Moi ban nhap thong tin chinh sua:\n";
            cout<<"ID: ";
            cin>>newId;
            usersList[i].setId(newId);

            cout<<"Ho va ten: ";
            cin.ignore();
            getline(cin,newName);
            usersList[i].setName(newName);

            cout<<"Tuoi: ";
            cin>>newAge;
            usersList[i].setAge(newAge);

            cout<<"Gioi tinh(0:Nam, 1:Nu): ";
            cin>>newGender;
            usersList[i].setGender(newGender);

            cout<<"Chuc vu(1:Quan ly, 2:Nguoi o, 3:Nhan vien): ";
            cin>>newRole;
            usersList[i].setRole(newRole);
        }
    }
}

inline void Command::addUser()
{
    string addId;
    string addName;
    int addAge;
    int addGender;
    int addRole;
    cout<<"Nhap thong tin nguoi dung muon them"<<endl;
    cout<<"ID: ";
    cin>>addId;

    cout<<"Ho va ten: ";
    cin.ignore();
    getline(cin,addName);

    cout<<"Tuoi: ";
    cin>>addAge;

    cout<<"Gioi tinh: ";
    cin>>addGender;

    cout<<"Chuc vu: ";
    cin>>addRole;

    USER newU(addId,addName,addAge,addGender,addRole,false);
    usersList.push_back(newU);
}

inline void Command::getEmployeeList()
{
    for(int i=0;i<usersList.size();i++)
        if(usersList[i].getRole() == 3)
            usersList[i].outPut();
    cout << "Nhan enter de tiep tuc.";
    getch();
}

inline void Command::getResidentList()
{
    for(int i=0;i<usersList.size();i++)
        if(usersList[i].getRole() == 2)
            usersList[i].outPut();
    cout << "Nhan enter de tiep tuc.";
    getch();
}

inline void Command::getManagerList()
{
    for(int i=0;i<usersList.size();i++)
        if(usersList[i].getRole() == 1)
            usersList[i].outPut();
    cout << "Nhan enter de tiep tuc.";
    getch();
}

inline void Command::editing()
{
    do
    {
        system("cls");
        choose = editMenu();
        system("cls");
        switch(choose)
        {
            case 1:
                addUser(); break;
            case 2:
                deleteUser(); break;
            case 3:
                editUser(); break;
        }
    }
    while(choose != 9 && choose != 4);
}

inline void Command::managerView()
{
    do
    {
        system("cls");
        choose = managerMenu();
        system("cls");
        switch(choose)
        {
            case 1:
                checkIn();break;
            case 2:
                checkOut();break;
            case 3:
                editing();break;
            case 5:
                getManagerList();break;
            case 6:
                getEmployeeList();break;
            case 7:
                getResidentList();break;
        }
    }
    while(choose != 9 && choose !=8);
}

inline void Command::residentView()
{
    do
    {
        system("cls");
        choose = residentMenu();
        system("cls");
        switch(choose)
        {
            case 1:
                checkIn();break;
            case 2:
                checkOut();break;
        }
    }
    while(choose != 9 && choose != 3);
}

















