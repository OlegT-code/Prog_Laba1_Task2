#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    static const size_t rows = 5;
    static const size_t columns = 3;

    double** array2D = new double* [rows];
    double* array1D = new double[rows + columns];
    double** ptrArr = array2D;
    int count = 0;

    for (size_t i = 0; i < rows; ++i) // создаём двумерный массив
    {
        *(array2D + i) = new double[columns];
    }

    cout << "[" << endl;
    for (size_t i = 0; i < rows; i++) // заполняем его данными и сразу же выводим
    {
        for (size_t j = 0; j < columns; j++)
        {
            *(*(array2D + i) + j) = sin(i - j) + cos(i + j);
            cout << setprecision(4) << setw(10) << *(*(array2D + i) + j);
        }
        cout << endl << endl;
    }
    cout << setw(35) << "]" << endl;

    for (size_t i = 0; i < columns; i++) { // из двумерного массива создаём одномерный массив
        for (size_t j = 0; j < rows; j++) {
            //*ptrArr++ = *(*(array2D + j) + i);
            *(array1D + count) = *(*(ptrArr + j) + i);
            count++;
        }
    }
    cout << "[  ";
    for (int i = 0; i < 15; i++) { // отображаем данные первого массива
        cout << *(array1D + i) << "  ";
    }
    cout << "]";
}