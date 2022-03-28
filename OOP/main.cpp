#include <bits/stdc++.h>
#include <iomanip>
#include "commandClass.cpp"

using namespace std;

int input(int SMALL, int BIG)
{
    char c;
    cin >> c;
    int number = (int)c - 48;
    while (number > BIG || number < SMALL)
    {
        cout << "Enter number: " << SMALL << " -> " << BIG << endl;
        cin >> c;
        number = (int)c -48;
    }
    return number;
}
int editMenu(){

    cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Them nguoi dung                            *\n";
	cout<<"*  2. Xoa nguoi dung               	        	*\n";
	cout<<"*  3. Sua thong tin nguoi dung                   *\n";
    cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"* hay nhap lua chon:                             *\n";
	cout<<"**************************************************\n";
	int number = input(1,4);
	return number;

}
int residentMenu(){
	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Check in.                        		    *\n";
	cout<<"*  2. Check out.                 	        	*\n";
	cout<<"*  3. thoat chuong trinh                         *\n";
	cout<<"* hay nhap lua chon:                             *\n";
	cout<<"**************************************************\n";
    int number = input(1,3);
    return number;
}

int managerMenu(){
	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Check in.                                  *\n";
	cout<<"*  2. Check out.                                 *\n";
	cout<<"*  3. Chinh sua danh sach nguoi dung             *\n";
	cout<<"*  4. Hien thi danh sach ra vao                  *\n";
	cout<<"*  5. Hien thi danh sach quan ly                 *\n";
	cout<<"*  6. Hien thi danh sach nhan vien               *\n";
	cout<<"*  7. Hien thi danh sach nguoi o.                *\n";
	cout<<"*  8. thoat chuong trinh                         *\n";
	cout<<"* hay nhap 1->8                                  *\n";
	cout<<"**************************************************\n";
	int number = input(1,8);
	return number;
}

int generalMenu(){

	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Dang nhap                                  *\n";
	cout<<"*  2. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1-> 2                                *\n";
	cout<<"**************************************************\n";
    int number = input(1,2);
    return number;
}

int main()
{
    Command command;
    int choose = generalMenu();
    if(choose == 1)
        command.logIn();
    else
        return 0;


    if(command.checkRole() == 1)
    {
        do
        {
            system("cls");
            choose = managerMenu();
            system("cls");
            switch(choose)
            {
                case 1:
                    command.checkIn();break;
                case 2:
                    command.checkOut();break;
//                case 4:
//                   Danh sach ra vao
                case 5:
                    command.getManagerList();break;

//                case 6:
//                    command.getIOLogs();break;
                case 6:
                    command.getEmployeeList();break;
                case 7:
                    command.getResidentList();break;
            }
            if(choose==3){
                do{
                   system("cls");
                    choose = editMenu();
                    system("cls");
                    switch(choose){
                        case 1:
                            command.addUser(); break;
                        case 2:
                            command.deleteUser(); break;
                        case 3:
                            command.editUser(); break;
                    }
                }while(choose != 4);
            }
            getch();
        }while(choose != 8);
    }
    else if(command.checkRole() == 2)
    {
        do
        {
            system("cls");
            choose = residentMenu();
            system("cls");
            switch(choose)
            {
                case 1:
                    command.checkIn();break;
                case 2:
                    command.checkOut();break;
            }
            getch();
        }while(choose != 3);
    }

    return 0;


}
