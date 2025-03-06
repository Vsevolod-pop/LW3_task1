
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    string stroka;
    cout << "Введите количество элементов в массиве - n (n - натуральное число) - ";
    getline(cin, stroka);
    int size;
    while (true)
    {
        try
        {
            size = stoi(stroka);
            if ((to_string(size) == stroka) and (size > 0))
            {
                break;
            }
            else
            {
                throw logic_error("Число введено некорректно");
            }
        }
        catch (...)
        {
            cout << "Число введено некорректно. Введите количество элементов в массиве - n (n - натуральное число) - ";
            getline(cin, stroka);
        }
    }
    srand(time(NULL));
    float* arr = new float[size];
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (double)(rand()) / RAND_MAX * (1000 + 1000) - 1000;
    }
    double C;
    cout << "Введите число C - ";
    getline(cin, stroka);
    while (true)
    {
        try
        {
            C = stof(stroka);
            stringstream C1;
            C1 << C;
            if (stroka == "0")
            {
                break;
            }
            if ((C1.str() == stroka.replace(stroka.find(","), 1, ".")) and C != 0)
            {
                break;
            }
            else
            {
                throw logic_error("Число введено некорректно");
            }
        }
        catch (...)
        {
            cout << "Число введено некорректно. Введите количество элементов в массиве - n (n - натуральное число) - " ;
            getline(cin, stroka);
        }
    }
    
    

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " элемент массива равен: " << *(arr + i) << endl;
    }
}
