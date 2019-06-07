#include "control.h"
int main()
{
    cout << "loading..." << endl;
    int choice = 1;
    Init();
    typedef void (*ptr)();
    ptr ptrTable[] = {
        SearchByT,
        SearchByV,
        SearchByU,
        SearchByH,
        SearchByS,
        SearchTable,
    };
    while(choice)
    {
        system("cls");
        cout << "Welcome use the tool for engineering thermodynamics!!!" << endl;
        cout << "1.Search by T" << endl;
        cout << "2.Search by v" << endl;
        cout << "3.Search by u" << endl;
        cout << "4.Search by h" << endl;
        cout << "5.Search by s" << endl;
        cout << "6.Search table" << endl;
        cout << "0.exit" << endl;
        cin >> choice;
        if(choice < 0 || choice > 8)
        {
            cout << "Input error!" << endl;
            continue;
        }
        ptrTable[choice - 1]();
        system("pause");
    }
}