#include <iostream>
#include <bitset>
using namespace std;

//3 вариант

//----------------------------------------------------------------------------- задача #1



short A;
short i;

int main() {

    cin >> A;
    cin >> i;
    if (i < 16){
        short i_bit = ((A >> i) & 1);
        if (i_bit != 0){
            short num1;
            short num2;

            cin >> num1;
            cin >> num2;

            if ((num1 % num2 == 0) || (num2 % num1 == 0)){
                if ((num1 % num2 == 0) && (num2 % num1 != 0)){
                    cout << "Результат деления: " << (num1 / num2) << " = " << bitset<8>(num1 / num2)  << endl;
                }
                if ((num2 % num1 == 0) && (num1 % num2 != 0)){
                    cout << "Результат деления: " << (num2 / num1) << " = " << bitset<8>(num2 / num1)  << endl;
                }
                if ((num1 % num2 == 0) && (num2 % num1 == 0)){
                    cout << "Результат деления: " << (num1 / num2) << " = " << bitset<8>(num1 / num2)  << endl;
                }
            }
            else {
                cout << "Результат произведения: " << (num1 * num2) << " = " << bitset<8>(num1 * num2)  << endl;
        }
        }
        else {
            if (((i + 1) <= 15) || ((i - 1) >= 0)){
                cout << bitset<8>(A ^ (1 << (i + 1)) ^ (1 << (i - 1))) << " = " << (A ^ (1 << (i + 1)) ^ (1 << (i - 1))) <<  endl;
            }

            else if ((i - 1) < 0){
                cout << "(i - 1) бит меньше 0";
            }

            else if ((i + 1) > 15){
                cout << "(i + 1) бит больше 15";
            }
            
        }
    } 
    else {
        cout << "i превышает 16" << endl;
    } 



    //----------------------------------------------------------------------------- задача #2


    // short N;
    // cin >> N;
    // if ((N != 1) | (N != 2) | (N != 4) | (N != 8) | (N != 13) | (N != 51) | (N != 52) | (N != 55) | (N != 61)){
    //     cout << "Ошибочный ввод N";
    // }
    // else{
    //     switch (N){
    //         case 1:
    //             cout << "Неисправность ЭБУ впрыска";
    //             break;
    //         case 2:
    //             cout << "Неисправность ДУТ";
    //             break;
    //         case 4:
    //             cout << "Повышенное напряжение";
    //             break;
    //         case 8:
    //             cout << "Пониженное напряжение";
    //             break;
    //         case 13:
    //             cout << "Отсутствует сигнал датчика кислорода";
    //             break;
    //         case 51:
    //             cout << "Неисправность работы ПЗУ";
    //             break;
    //         case 52:
    //             cout << "Неисправность работы ОЗУ";
    //             break;
    //         case 55:
    //             cout << "Слишком бедная смесь";
    //             break;
    //         case 61:
    //             cout << "Проблемы в работе датчика кислорода";
    //             break;
    //     }
    // }
    return 0;
}






