#include <iostream>
#include <cstdlib>
using namespace std;

//3 вариант

float summa = 0;
bool flag = false;
float max_num = -1;
short max_index;


short res = 1;
short x;

int main(){

    //------------------------------------------------------------------------- задача 1
    short N;
    cin >> N;

    for (short i = 0; i < N; i++){
        float num;
        cin >> num;
        if ((num > -0.36) && (num <= 10.1)){
            flag = true;
            if (num > max_num){
                max_num = num;
                max_index = i + 1;
            }
            summa += num;
        }
    }
    if (flag == false){
            cout << "В последовательности нет чисел из интервала (-0.36; 10.1]";
        }
    else {
        cout << "Сумма всех чисел = " << summa << endl;
        cout << "Наибольшее число = " << max_num << endl;
        cout << "Номер в последовательности наибольшего числа = " << max_index;
    }
    

    //------------------------------------------------------------------------- задача 2
    // // cin >> x;

    // // if (x == 0){
    // //     res = 0;
    // // }

    // // else if (x < 0){
    // //     x = abs(x);
    // //     while (x != 0){
    // //         res *= (x % 10);
    // //         x /= 10;
    // //     }
    // // }

    // // else if (x > 0){
    // //     while (x != 0){
    // //         res *= (x % 10);
    // //         x /= 10;
    // //     }
    // // }
    // // cout << "Произведение цифр: " << res;

    // cin >> x;

    // if (x == 0){
    //     res = 0;
    // }

    // else if (abs(x) < 1000){
    //     while (abs(x) != 0){
    //         res *= (abs(x) % 10);
    //         x = (abs(x) / 10);
    //     }
    // }

    // cout << "Произведение цифр: " << res;

    return 0;
}