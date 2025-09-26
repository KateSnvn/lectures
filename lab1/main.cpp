#include <iostream>
using namespace std;

//3 вариант

unsigned short num1; 
unsigned short num2;
/*
По условию нужно найти сумму, разность, произведение, частное 2х неотрицательных чисел. 
Выбрала тип данных unsigned short.
Так как unsigned указывает, что переменная может хранить только неотрицательные значения.
short для оптимизации кода, так как short по объему памяти заминает меньшее количество байт
*/


short size_short = sizeof(short) * 8;
short min_short = -pow(2, sizeof(short) * 8 - 1);
short max_short = pow(2, sizeof(short) * 8 - 1) - 1;

short size_unsigned_short = sizeof(short) * 8;
short min_unsigned_short = 0;
unsigned short max_unsigned_short = pow(2, sizeof(short) * 8) - 1;

float size_float = sizeof(float) * 8;
float min_float = numeric_limits<float>::lowest();
float max_float = numeric_limits<float>::max();


int main() {
    cout << "short занимает " << size_short << " бит, минимальное значение = " << min_short << ", максимальное значение = " << max_short << endl;
    cout << "unsigned short занимает " << size_unsigned_short << " бит, минимальное значение = " << min_unsigned_short << ", максимальное значение = " << max_unsigned_short << endl;
    cout << "float занимает " << size_float << " бит, минимальное значение = " << min_float << ", максимальное значение = " << max_float << endl;
    
    
    cin >> num1;
    cin >> num2;


    unsigned short res1 = num1 + num2;
    short res2 = num1 - num2;
    short res3 = num2 - num1;
    /*
    Для разности выбрала тип данных short (без unsigned), так как есть вероятность получить отрицательное значение (num1 < num2)
    */
    unsigned short res4 = num1 * num2;
    float res5 = float(num1) / num2;
    /*
    Для частного выбрала тип данных float, так как есть вероятность получить нецелое значение
    */


    cout << "Сумма: " << res1 << endl;
    cout << "Попарная разность: " << res2 << ", " << res3 << endl;
    cout << "Произведение: " << res4 << endl;
    cout << "Частное: " << res5 << endl;

}
