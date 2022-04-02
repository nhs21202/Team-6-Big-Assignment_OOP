#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "userClass.cpp"
#include "menuClass.cpp"
#include "dateTime.cpp"
// #include "logClass.cpp"
using namespace std;

class Command
{
private:
    vector<USER> usersList;
    USER user;
    DateTime dateTime;
    vector<USER> logList;      // truy xuat
    vector<string> timeLogIn;  // song song
    vector<string> timeLogOut; // ca 3 cai

public:
    int choose;
    Command() // Khoi tao du lieu ban dau
    {
        USER u1("QL0001", "Nguyen Duc Manh", 30, 0, 1, false);
        USER u2("QL1002", "Nguyen Thi Mai Trang", 35, 1, 1, false);
        USER u3("CD0003", "Nguyen Hoa Son", 40, 0, 2, false);
        USER u4("CD0004", "Nguyen Van Hieu", 20, 0, 2, false);
        USER u5("CD0005", "Nguyen Van Chi", 10, 0, 2, false);
        USER u6("NV1006", "Pham Thi Thao", 19, 1, 3, false);
        USER u7("NV2007", "Doan Anh Tuan", 20, 2, 3, false);
        USER u8("QL1008", "Hoang Thu A", 45, 1, 1, false);
        usersList.push_back(u1);
        usersList.push_back(u2);
        usersList.push_back(u3);
        usersList.push_back(u4);
        usersList.push_back(u5);
        usersList.push_back(u6);
        usersList.push_back(u7);
        usersList.push_back(u8);
    };

    void logIn();                // Thuc hien dang nhap
    bool checkId();              // Kiem tra id nhap vao
    int checkRole();             // Kiem tra role
    void checkIn();              // Thuc hien checkin (status = true)
    void checkOut();             // Thuc hien checkout (status = false)
    void deleteUser();           // Xoa nguoi dung
    void editUser();             // Sua thong tin nguoi dung
    void addUser();              // Them nguoi dung
    void getEmployeeList();      // In ra danh sach nhan vien
    void getResidentList();      // In ra danh sach nguoi o
    void getManagerList();       // In ra danh sach quan ly
    void editing();              // View in ra de edit nguoi dung
    void managerView();          // View in ra danh cho manager
    void residentView();         // View in ra danh cho nguoi o
    USER getCurrentUser(string); // Su dung de quan ly thoi gian vao ra
    int getIndexById(string);    // Su dung de quan ly thoi gian vao ra
    void getLogList();           // Danh sach thoi gian vao ra
    void tableTitle();           // Tieu de bang cho cac danh sach

};

inline int Command::getIndexById(string id)
{
    for (int i = 0; i < logList.size(); i++) // run userLogList 1 round
    {
        if (logList[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

inline USER Command::getCurrentUser(string id)
{
    char lastChar = id.at(id.length() - 1); // lay phan tu cuoi cung
    int index = (int)lastChar - '1';
    return usersList.at(index);
}

inline void Command::getLogList() {
    cout<<"----------------------------------------------DANH SACH RA VAO--------------------------------------------\n\n";
    cout<<"==========================================================================================================\n";
    cout<<"|"<<setw(8)<<"ID   "<<"|"<< setw(20) << "HO VA TEN     " <<"|"<< setw(11)<<"CHUC VU  " <<"|"<< setw(31) << "Thoi gian vao         " <<"|"<< setw(30) << "Thoi gian ra         "<<"|"<<endl;
    cout<<"==========================================================================================================\n";

    for (int i = 0; i < logList.size(); i++)
    {
        cout<<"|"<<setw(8)<<logList[i].getId()<<"|"<< setw(20) << logList[i].getName() <<"|"<< setw(11) << logList[i].toStringRole()<<"|"<< setw(31) << timeLogIn[i] <<"|"<< setw(30) << timeLogOut[i] <<"|"<<endl;
        cout<<"==========================================================================================================\n";
    }
    cout << "Nhan enter de tiep tuc.";
    getch();

}

inline void Command::logIn()
{
    user.inPut();
    if (!checkId())
        cout << "Id khong dung, nhan Enter de tiep tuc!" << endl;
    else
        cout << "Ban da dang nhap thanh cong, nhan Enter de tiep tuc!" << endl;
};

inline bool Command::checkId()
{
    for (int i = 0; i < usersList.size(); i++)
        if (user.getId() == usersList[i].getId())
            return 1;
    return 0;
}

inline int Command::checkRole()
{
    for (int i = 0; i < usersList.size(); i++)
    {
        if (user.getId() == usersList[i].getId())
            return usersList[i].getRole();
    }
    return 0;
}

inline void Command::checkIn()
{
    if (checkId())
    {
        user.setStatus(true);
        string time = dateTime.currentDateTime();
        int index = getIndexById(user.getId()); // tim xem user da co trong ds log chua
        if (index != -1)
        {
            timeLogIn[index] = time;
            cout << "Ban da di vao!" << endl;
            cout << setw(12) << "Thoi Gian: " << setw(30) << time << endl;
        }
        else
        {
            USER currentUser = getCurrentUser(user.getId());
            logList.push_back(currentUser);
            timeLogIn.push_back(time);
            timeLogOut.push_back("NUll");
            cout << "Ban da di vao!" << endl;
            cout << setw(12) << "Id: " << setw(30) << currentUser.getId() << endl;
            cout << setw(12) << "Ho va Ten: " << setw(30) << currentUser.getName() << endl;
            cout << setw(12) << "Thoi Gian: " << setw(30) << time << endl;
        }
        getch();
    }
}

inline void Command::checkOut()
{
    user.setStatus(false);
    string time = dateTime.currentDateTime();
    int index = getIndexById(user.getId());
    if (index != -1)
    {
        timeLogOut[index] = time;
        cout << "Ban da di ra!" << endl;
        cout << setw(12) << "Thoi Gian: " << setw(30) << time << endl;
    }
    else
    {
        cout << "Khong hop le, Ban dang o ben ngoai" << endl;
        cout << setw(12) << "Thoi Gian: " << setw(30) << time << endl;
    }
    getch();
}

inline void Command::deleteUser()
{
    cout << "Nhap ID nguoi dung can xoa:";
    string deleId;
    cin >> deleId;
    for (int i = 0; i < usersList.size(); i++)
    {
        if (deleId == usersList[i].getId())
        {
            usersList.erase(usersList.begin() + i);
        }
    }
}

inline void Command::editUser()
{
    cout << "Nhap ID nguoi dung can chinh sua:";
    string editId;
    cin >> editId;
    for (int i = 0; i < usersList.size(); i++)
    {
        if (editId == usersList[i].getId())
        {
            string newName;
            int newAge;
            int newGender;
            int newRole;
            cout << "Moi ban nhap thong tin chinh sua:\n";
            cout << "Ho va ten: ";
            cin.ignore();
            getline(cin, newName);
            usersList[i].setName(newName);

            cout << "Tuoi: ";
            cin >> newAge;
            usersList[i].setAge(newAge);

            cout << "Gioi tinh(0:Nam, 1:Nu): ";
            cin >> newGender;
            usersList[i].setGender(newGender);

            cout << "Chuc vu(1:Quan ly, 2:Nguoi o, 3:Nhan vien): ";
            cin >> newRole;
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
    cout << "Nhap thong tin nguoi dung muon them" << endl;
    cout << "ID: ";
    cin >> addId;

    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin, addName);

    cout << "Tuoi: ";
    cin >> addAge;

    cout << "Gioi tinh: ";
    cin >> addGender;

    cout << "Chuc vu: ";
    cin >> addRole;

    USER newU(addId, addName, addAge, addGender, addRole, false);
    usersList.push_back(newU);
}

inline void Command::getEmployeeList()
{
    cout<<"---------------------DANH SACH NHAN VIEN----------------------\n"<<endl;
    tableTitle();
    for (int i = 0; i < usersList.size(); i++)
        if (usersList[i].getRole() == 3)
            usersList[i].outPut();
    cout << "Nhan enter de tiep tuc.";
    getch();
}

inline void Command::getResidentList()
{
     cout<<"---------------------DANH SACH CU DAN----------------------\n"<<endl;
    tableTitle();
    for (int i = 0; i < usersList.size(); i++)
        if (usersList[i].getRole() == 2)
            usersList[i].outPut();
    cout << "Nhan enter de tiep tuc.";
    getch();
}

inline void Command::getManagerList()
{
     cout<<"---------------------DANH SACH QUAN LY----------------------\n"<<endl;
    tableTitle();
    for (int i = 0; i < usersList.size(); i++)
        if (usersList[i].getRole() == 1)
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
        switch (choose)
        {
        case 1:
            addUser();
            break;
        case 2:
            deleteUser();
            break;
        case 3:
            editUser();
            break;
        }
    } while (choose != 9 && choose != 4);
}

inline void Command::managerView()
{
    do
    {
        system("cls");
        choose = managerMenu();
        system("cls");
        switch (choose)
        {
        case 1:
            checkIn();
            break;
        case 2:
            checkOut();
            break;
        case 3:
            editing();
            break;
        case 4:
            getLogList();
            break;
        case 5:
            getManagerList();
            break;
        case 6:
            getEmployeeList();
            break;
        case 7:
            getResidentList();
            break;
        }
    } while (choose != 9 && choose != 8);
}

inline void Command::residentView()
{
    do
    {
        system("cls");
        choose = residentMenu();
        system("cls");
        switch (choose)
        {
        case 1:
            checkIn();
            break;
        case 2:
            checkOut();
            break;
        }
    } while (choose != 9 && choose != 3);
}
inline void Command:: tableTitle(){
    cout<<"==============================================================\n";
    cout<<"|"<<setw(8)<<"ID   ";
	cout<<"|"<<setw(20)<<"HO VA TEN     ";
 	cout<<"|"<<setw(6)<<"TUOI ";
 	cout<<"|"<<setw(11)<<"GIOI TINH ";
 	cout<<"|"<<setw(11)<<"CHUC VU  "<<"|"<<endl;
 	cout<<"=============================================================="<<endl;
}
