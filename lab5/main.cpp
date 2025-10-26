#include <iostream>
using namespace std;

//3 вариант

void operations(int num1, int num2){
    if ((num1 % num2) == 0){
        cout << (num1 / num2);
    }

    else if ((num2 % num1) == 0){
        cout << (num2 / num1);
    }

    else if (num1 == num2){
        cout << (num1 / num2);
    }

    else if (((num1 % num2) != 0) && ((num2 % num1) != 0)){
        cout << (num1 * num2);
    }
}

void operations(int num1, int num2, int num3) {
    if ((num1 == num2) && (num2 == num3)){
        cout << 1;
    }
    else {
        cout << -1;
    }
}

void func1(){
    int nums[3];
    for (int i = 0; i < 3; i++){
        cin >> nums[i];
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++){
        if (nums[i] != 0){
            cnt++;
        }
    }

    switch (cnt){
        case 2:{
            int two_nums[2];
            int count = 0;
            for (int i = 0; i < 3; i++){
                if (nums[i] != 0){
                    two_nums[count] = nums[i];
                    count++;
                }
            }
            operations(two_nums[0], two_nums[1]);
            break;
        }
        case 3:{
            operations(nums[0], nums[1], nums[2]);
            break;
        }
    }
}

void func2(){
    unsigned short num1; 
    unsigned short num2;

    cin >> num1;
    cin >> num2;

    unsigned short res1 = num1 + num2;
    short res2 = num1 - num2;
    short res3 = num2 - num1;

    unsigned short res4 = num1 * num2;
    float res5 = float(num1) / num2;


    cout << "Сумма: " << res1 << endl;
    cout << "Попарная разность: " << res2 << ", " << res3 << endl;
    cout << "Произведение: " << res4 << endl;
    cout << "Частное: " << res5 << endl;
}



int main(){
    short func;
    cin >> func;

    switch (func){
        case 1:{
            func1();
            break;
        }

        case 2:{
            func2();
            break;
        }
    }
    return 0;
}
