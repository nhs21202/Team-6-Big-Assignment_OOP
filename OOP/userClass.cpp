#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include<windows.h>
using namespace std;
class USER{
	/*
	1. quan ly
	2. cu dan
	3. khach
	 */

	/*id dạng:2 chữ, 4 số, 2 chữ viết hoa viết tắt Role
	quản lí: QL
	cư dân: CD
	khách: KK
	chữ số thứ nhất là giới tính: Nam:0, Nữ:1,Khác:2
	3 chữ số còn lại để gì cũng được(để theo thứ tự 001 002 003,.. cho dễ quản lý)
	*/
	protected:
		string id;
		string name;
		int age;
		int gender;
		int role;
		bool status;
	public:
		USER(){}
		USER(string id, string name, int _age, int _gender, int _role, bool _status)
		{
            this->id = id;
            this->name = name;
		    age = _age;
		    gender = _gender;
		    role = _role;
		    status = _status;
		}
		void setId(string id);
		string getId();

		void setRole(int role);
		int getRole();

		void setName(string name);
		string getName();

		void setAge(int age);
		int getAge();

		void setGender(int gender);
		int getGender();

		void setStatus(bool status);
		bool getStatus();

		void inPut();   // nhap du lieu
		void outPut();  // xuat du lieu

		string toStringGender();
		string toStringRole();
};

inline void USER::setId(string id){
	this->id=id;
}
inline string USER::getId(){
	return this->id;
}

inline int USER::getRole(){
    return this-> role;
}
 inline void USER::setRole(int role){
	this->role = role;
}

 inline void USER::setName(string name){
	this->name= name;
}
inline string USER::getName(){
    return this->name;
}

 inline void USER::setAge(int age){
	this-> age = age;
}
inline int USER::getAge(){
    return this->age;
}

 inline void USER::setGender(int gender){
	this->gender = gender;
}
inline int USER::getGender(){
    return this->gender;
}

 inline void USER::setStatus(bool status){
	this->status = status;
}
inline bool USER::getStatus(){
    return this->status;
}

 inline string USER::toStringGender(){
     string alter;
    switch(gender){
    case 0:
        alter="Nam";
        break;
    case 1:
        alter = "Nu";
        break;
    default:
        alter = "Khac";
    }
    return alter;
 }

 inline string USER::toStringRole(){
    string alter1;
    switch(role){
        case 1:
            alter1 = "Quan ly";
            break;
        case 2:
            alter1 = "Cu dan";
            break;
        case 3:
            alter1 = "Nhan vien";
            break;
    }
    return alter1;
 }
 inline void USER::inPut(){
	cout<<"Nhap ID nguoi dung: ";
	cin.ignore();
	getline(cin,id);
}
 inline void USER::outPut(){
	cout<<"id : "<<id<<endl;
	cout<<"name : "<<name<<endl;
 	cout<<"age : "<<age<<endl;
 	cout<<"gender : "<<toStringGender()<<endl;
 	cout<<"role : "<<toStringRole()<<endl;
 	cout<<endl;
 }
