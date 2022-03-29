#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include "userClass.cpp"
using namespace std;
class Logs{
    private:
        USER user;
        string timeIn;
        string timeOut;
        bool status;
    public:
        Logs(){}
        Logs(USER user, string timeIn){
            this->user = user;
            this->timeIn = timeIn;
            this->timeOut = "Chua di ra";
            this->status = user.getStatus();
        }
    string getLogId(){
        return user.getId();
    }
    void setTimeIn(string timeIn){
        this->timeIn = timeIn;
    }
    void setTimeOut(string timeOut){
        this->timeOut = timeOut;
    }
    string getTimeOut(){
        return this->timeOut;
    }
    string getTimeIn(){
        return this->timeIn;
    }
};
