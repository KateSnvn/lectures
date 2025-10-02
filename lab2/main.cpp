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
    bitset<8>A_bits(A);
    short i_bit = A_bits[i];

    if (i < 8){
        
        if (i_bit != 0){
            int num1;
            int num2;
            cin >> num1;
            cin >> num2;
            if ((num1 % num2 == 0) || (num2 % num1 == 0)){
                if ((num1 % num2 == 0) && (num2 % num1 != 0)){
                    cout << "Результат деления: " << bitset<8>( num1 / num2) << " = " << num1 / num2  << endl;
                }
                if ((num2 % num1 == 0) && (num1 % num2 != 0)){
                    cout << "Результат деления: " << bitset<8>( num2 / num1) << " = " << num2 / num1  << endl;
                }
                if ((num1 % num2 == 0) && (num2 % num1 == 0)){
                    cout << "Результат деления: " << bitset<8>( num1 / num2) << " = " << num1 / num2  << endl;
                }
            }
            else {
                cout << "Результат произведения: " << bitset<8>( num1 * num2) << " = " << num1 * num2  << endl;
            }
            
        }
        
        else if (i_bit == 0){
            cout << stoi((A_bits ^ bitset<8>(1 << (i - 1)) ^ bitset<8>(1 << (i + 1))).to_string(), nullptr, 2) << " = " << (A_bits ^ bitset<8>(1 << (i - 1)) ^ bitset<8>(1 << (i + 1))) << endl;
        } 
        
    }
    else if (i >= 8){
        cout << "i больше 8";
    }
}




//----------------------------------------------------------------------------- задача #2
