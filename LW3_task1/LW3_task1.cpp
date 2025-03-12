
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
    int n;
    while (true)
    {
        try
        {
            n = stoi(stroka);
            if ((to_string(n) == stroka) and (n > 0))
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
    float* arr = new float[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = (double)(rand()) / RAND_MAX * (10 + 10) - 10;
    }
    double C;
    cout << "Введите число C - ";
    getline(cin, stroka);
    while (true)
    {
        if (stroka.find(".") != string::npos)
            stroka.replace(stroka.find("."), 1, ",");
        try
        {
            if (stroka == "")
            {
                throw logic_error("Число введено некорректно");
            }
            if (stroka == "0")
            {
                C = 0;
                break;
            }
            if ((stroka[1] != ',' and stroka[0] == '0') or (stroka[0] == '-' and stroka[1] == '0' and stroka[2] != ','))
            {
                throw logic_error("Число введено некорректно");
            }
            int flag = 0;
            for (int i = 0; i < stroka.length(); i++)
            {
                if (stroka[i] == '-' and i == 0)
                {
                    continue;
                }
                if (stroka[i] == ',')
                {
                    flag++;
                    if (flag > 1)
                    {
                        throw logic_error("Число введено некорректно");
                    }
                    else
                    {
                        continue;
                    }
                }
                if (!isdigit(stroka[i]))
                {
                    throw logic_error("Число введено некорректно");
                }
            }
            C = stof(stroka);
            break;
        }
        catch (...)
        {
            cout << "Число введено некорректно. Введите количество элементов в массиве - n (n - натуральное число) - ";
            getline(cin, stroka);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " элемент исходного массива равен: " << *(arr + i) << endl;
    }
    int countC = 0;
    int summ = 0;
    int schetchik = 0;
    float* arr_new = new float[n];
    float max = -99999999.0;
    int min_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                }
                if (arr[j] < 0)
                {
                    min_i = j;
                }
            }
        }
        if (arr[i] < C)
        {
            countC++;
        }
        if (i > min_i)
        {
            summ += int(arr[i]);
        }
    }
    int j = n-1;
    for (int i = 0; i < n; i++)
    {
        if ((max * 0.8 < arr[i]) and (arr[i] < max))
        {
            arr_new[schetchik] = arr[i];
            schetchik++;
        }
        else
        {
            arr_new[j] = arr[i];
            j--;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " элемент нового массива равен: " << arr_new[i] << endl;
    }
    cout << endl;
    cout << "Количество элементов массива меньших С - " << countC << endl << "Сумма целых частей элементов массива, расположенных после последнего отрицательного элемента - " << summ << endl;
}
