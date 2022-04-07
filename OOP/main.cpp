#include <iomanip>
#include "commandClass.cpp"
using namespace std;

int main()
{
    Command command;
    do
    {
        command.choose = generalMenu();
        if(command.choose == 1)
        {
            command.logIn();
            getch();
            system("cls");
        }
        else return 0;

        if(command.checkRole() == 1)
        {
            command.managerView();
        }
        else if(command.checkRole() == 2)
        {
            command.residentView();
        }
        else if(command.checkRole() == 3)
        {
            command.employeeView();
        }
    }
    while(command.choose != 9);
    return 0;
}
