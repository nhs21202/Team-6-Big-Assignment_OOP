
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "userClass.cpp"
#include "logClass.cpp"
//#include "manager.cpp"
using namespace std;

class Command
{
private:
    vector<USER> usersList;
    vector<Logs> logsList;
    USER user;

public:
    Command()
    {
        /*
        1.QL
        2.CD
        3.NV

        gioi tinh 1:Nữ, 2:Nam
        */
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

    void logIn()
    {
        user.inPut();
        checkIn();
        if(checkRole()== 2)
            cout << " voi tu cach nguoi o\n";
        else if(checkRole() == 1)
            cout << " voi tu cach quan ly\n";

    };

    bool checkId()
    {
        for(int i=0;i<usersList.size();i++)
            if(user.getId() == usersList[i].getId())
                return 1;
            return 0;
    }

    int checkRole()
    {
        for(int i=0;i<usersList.size();i++)
        {
            if(user.getId() == usersList[i].getId())
                return usersList[i].getRole();
        }
        return 0;
    }
    void checkIn(){
        if(checkId()){
        user.setStatus(true);
        cout<<"Ban da di vao!"<<endl;
        logsList.push_back(Logs(user,currentDateTime()));
        }
    }
    void checkOut(){
        if((user.getId()==Logs.getLogId()) && checkId()){
            cout<<"Ban da di ra!"<<endl;
            user.setStatus(false);
            Logs.setTimeOut(currentDateTime());
        }
    }

    void deleteUser(){
        cout<<"Nhap ID nguoi dung can xoa:";
        string deleId;
        cin>>deleId;
        for(int i=0;i<usersList.size();i++){
            if(deleId==usersList[i].getId()){
               usersList.erase(usersList.begin()+i);
            }
        }
        cout<<"Nguoi dung "<<deleId<<" da duoc xoa khoi he thong!\n";
        cout<<"Nhan enter de tiep tuc:";
    }
    void editUser(){
        cout<<"Nhap ID nguoi dung can chinh sua:";
        string editId;
        cin>>editId;
        for(int i=0;i<usersList.size();i++){
            if(editId == usersList[i].getId()){
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

                cout<<"Gioi tinh(0-Nam; 1-Nu): ";
                cin>>newGender;
                usersList[i].setGender(newGender);

                cout<<"Chuc vu(1-Quan ly; 2-Cu dan; 3-Nhan vien): ";
                cin>>newRole;
                usersList[i].setRole(newRole);
            }
        }
        cout<<"Nguoi dung "<<editId<<" da duoc chinh sua!\n";
        cout<<"Nhan enter de tiep tuc:";
    }

    void addUser(){
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

		cout<<"Gioi tinh(0-Nam; 1-Nu): ";
		cin>>addGender;

		cout<<"Chuc vu(1-Quan ly; 2-Cu dan; 3-Nhan vien): ";
		cin>>addRole;

        USER newU(addId,addName,addAge,addGender,addRole,false);
        usersList.push_back(newU);

        cout<<"Nguoi dung "<<addId<<" da duoc them vao he thong!\n";
        cout<<"Nhan enter de tiep tuc";
    }
    void getEmployeeList()
    {
        for(int i=0;i<usersList.size();i++)
            if(usersList[i].getRole() == 3)
                usersList[i].outPut();
        cout << "Nhan enter de tiep tuc.";
    }

    void getResidentList()
    {
        for(int i=0;i<usersList.size();i++)
            if(usersList[i].getRole() == 2)
                usersList[i].outPut();
        cout << "Nhan enter de tiep tuc.";
    }

    void getManagerList()
    {
        for(int i=0;i<usersList.size();i++)
            if(usersList[i].getRole() == 1)
                usersList[i].outPut();
        cout << "Nhan enter de tiep tuc.";
    }
    string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *gmtime(&now);
    tstruct.tm_hour += 7;
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
};
