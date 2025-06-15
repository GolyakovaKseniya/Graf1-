#include "Header.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    while (true)
    {
        cout << "1. Создать граф с клавиатуры"<<endl;
        cout << "2. Случайный граф"<<endl;
        cout << "0. Выход"<<endl;
        cout << "Выберите действие: "<<endl;

        int choice;
        choice = getValidIntegerInput();
        switch (choice) 
        {
        case 1:
            createGraphManually();
            calculateDegrees();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            generateRandomGraph();
            calculateDegrees();
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор!\n";
        }
    }
}