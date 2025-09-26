#include <iostream>
using namespace std;

//3 вариант

unsigned short num1; 
unsigned short num2;
/*
По условию нужно найти сумму, разность, произведение 2х неотрицательных чисел. 
Выбрала тип данных unsigned short.
Так как unsigned указывает, что переменная может хранить только неотрицательные значения.
short для оптимизации кода, так как short по объему памяти заминает меньшее количество байт
*/


short size_short = sizeof(short) * 8;
short min_short = -pow(2, 15);
short max_short = pow(2, 15) - 1;


int main() {
    cout << "short занимает " << size_short << " бит, минимальное значение = " << min_short << ", максимальное значение = " << max_short << endl;
    
    
    cin >> num1;
    cin >> num2;


    unsigned short res1 = num1 + num2;
    short res2 = num1 - num2;
    /*
    Для разности выбрала тип данных short (без unsigned), так как есть вероятность получить отрицательное значение (num1 < num2)
    */
    unsigned short res3 = num1 * num2;
    float res4 = float(num1) / num2;
    /*
    Для частного выбрала тип данных float, так как есть вероятность получить нецелое значение
    */


    cout << "Сумма: " << res1 << endl;
    cout << "Разность: " << res2 << endl;
    cout << "Произведение: " << res3 << endl;
    cout << "Частное: " << res4 << endl;

}
