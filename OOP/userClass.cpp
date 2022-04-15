#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include<windows.h>
#pragma once

using namespace std;
class PEOPLE{
    protected:
		string id;
		string name;
		int age;
		int gender;
		int role;
		bool status;
	public:

        PEOPLE(){};
        PEOPLE(string id, string name, int age, int gender, int role, bool status){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->role = role;
            this->status = status;

        };
};

class MANAGER: virtual public PEOPLE{
    private:
        string address;
    public:
        string getAdress(){
            return this->address;
        }
        void setAddress(string address){
            this->address = address;
        }

        MANAGER(){};
        MANAGER(string id, string name, int age, int gender, int role, bool status, string address){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->role = role;
            this->status = status;
            this->address = address;
        };
};

class EMPLOYEE:virtual public PEOPLE{
    private:
        string department;
    public:
        EMPLOYEE(){};
        void setDepartment(string department){
            this->department = department;
        }
        string getDepartment(){
            return this->department;
        }
        EMPLOYEE(string id, string name, int age, int gender, int role, bool status, string department){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->role = role;
            this->status = status;
            this->department = department;
        };
};
class RESIDENT:virtual public PEOPLE{
    private:
        string roomNumber;
    public:

        void setRoomNumber(string roomNumber){
            this->roomNumber = roomNumber;
        }
        string getRoomNumber(){
            return this->roomNumber;
        }
        RESIDENT(){};
        RESIDENT(string id, string name, int age, int gender, int role, bool status, string roomNumber){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->role = role;
            this->status = status;
            this->roomNumber = roomNumber;
        };
};

class USER: public MANAGER, public EMPLOYEE, public RESIDENT{
	private:

	public:

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

		USER(){};
		USER(string id, string name, int _age, int _gender, int _role, bool _status)
		{
            this->id = id;
            this->name = name;
            this->age = _age;
		    this->gender = _gender;
		    this->role = _role;
		    this->status = _status;
		}
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
	getline(cin,id);
}
 inline void USER::outPut(){

	cout<<"|"<<setw(8)<<id;
	cout<<"|"<<setw(20)<<name;
 	cout<<"|"<<setw(6)<<age;
 	cout<<"|"<<setw(11)<<toStringGender();
 	cout<<"|"<<setw(11)<<toStringRole()<<"|"<<endl;
 	cout<<"=============================================================="<<endl;
 }
