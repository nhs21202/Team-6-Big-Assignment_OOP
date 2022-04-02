#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Menu
{
private:
    int generalMenu();
    int residentMenu();
    int managerMenu();
    int editMenu();

    bool match();
    int input();
};

inline bool match(int c, int arr[], int n)
{
    for(int i=0;i<n;i++)
        if(c == arr[i])
            return true;
    return false;
}

//inline int inputFormat()
//{
//    string s;
//    getline(cin, s);
//    while(s.length()>1 || atoi(s.c_str())>9 || atoi(s.c_str())<1)
//    {
//        cout << "Moi nhap lai:";
//        getline(cin, s);
//    }
//    return atoi()
//}

inline int input(int arr[], int n)
{
    string s;
    getline(cin, s);
    while(!match(atoi(s.c_str()), arr, n))
    {
        cout << "Moi ban nhap lai: ";
        getline(cin, s);
    }
    return atoi(s.c_str());
}

inline int generalMenu(){

	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Dang nhap                                  *\n";
	cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1 hoac 9                             *\n";
	cout<<"**************************************************\n";
    int choice[2] = {1,9};
    return input(choice, 2);
}


inline int residentMenu(){
	cout<<"************He thong ra vao toa nha***************\n";
	cout<<"**************************************************\n";
	cout<<"*  1. Check in.                                  *\n";
	cout<<"*  2. Check out.                                 *\n";
	cout<<"*  3. Dang xuat                                  *\n";
	cout<<"*  9. Thoat chuong trinh                         *\n";
	cout<<"*  Hay nhap 1,2,3 hoac 9                         *\n";
	cout<<"**************************************************\n";
    int choice[4] = {1,2,3,9};
    return input(choice, 4);
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
    return input(choice, 9);
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
    return input(choice, 5);
}
