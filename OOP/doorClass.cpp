
#include <iostream>
#include <iomanip>

using namespace std;
class Door
{
public:
    int type;
    int input()
    {
        char c;
        string input;
        cout << "Cua vao: " << endl;
        cout << "1. Cua phong o" << endl;
        cout << "2. Cua phong quan ly" << endl;
        cout << "3. Cua chinh" << endl;
        cin >> input;
        c = input.at(0);
        type = (int)c - 48;
    }
    bool doorCheckIn(string id)
    {
        string temp = id.substr(0, 2);
        switch (type)
        {
        case 1:
            if (temp == "CD")
            {
                cout << "Cua phong o" << endl;
                return true;
            }
            return false;
            break;
        case 2:
            if (temp == "QL")
            {
                cout << "Cua phong quan ly" << endl;
                return true;
            }
            return false;
            break;
        case 3:
            cout << "Cua chinh" <<endl;
            return true;
            break;
        }
    }
};
