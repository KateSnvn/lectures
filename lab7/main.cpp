#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

//3 вариант

//--------------------------------------------------------------------------------------------------задание 1 

void printMassive(const vector<int>& massive) {
    cout << "[";
    for (int i = 0; i < massive.size(); i++) {
        cout << massive[i];
        if (i + 1 < massive.size()){
            cout << " ";
        } 
    }
    cout << "]" << endl;
}

void pushFront(vector<int>& massive, int num) {
    massive.insert(massive.begin(), num);
}

void pushBack(vector<int>& massive, int num) {
    massive.push_back(num);
}

void clearMassive(vector<int>& massive) {
    massive.clear();
}

vector<int> findIndex(const vector<int>& massive, int num) {
    vector<int> index;
    for (int i = 0; i < massive.size(); i++){
        if (massive[i] == num){
            index.push_back(i);
        } 
    }
    return index;
}

void vrnt(vector<int>& massive) {
    if (massive.empty()){
        return;
    } 

    int max_num = massive[0]; 
    for (int i = 1; i < massive.size(); ++i) {
        if (massive[i] > max_num) {
            max_num = massive[i];
        }
    }

    int cnt = 0;
    for (int i = 1; i < massive.size(); ++i) {
        if (massive[i] == max_num) {
            cnt++;
        }
    }

    vector<int> temp_massive; 
    for (int i = 0; i < massive.size(); ++i) {
        if (massive[i] != max_num) {
            temp_massive.push_back(massive[i]);
        }
    }
    massive = temp_massive;

    if (cnt == 1){
        massive.insert(massive.begin(), max_num);
    }
    else {
        massive.push_back(max_num);
    }
}


//--------------------------------------------------------------------------------------------------задание 2

//по значению:
//1)неэффективно(создается полная копия всего массива)
//2)все изменения останутся в этой копии и пропадут, когда функция завершит работу(исходный массив не изменится)
void sortElements(array<int,10> arr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//по ссылке:
//1)функция работает напрямую с исходным массивом
//2)это самый быстрый способ(не нужно тратить время и память на создание копии)
//3)ссылка должна быть привязана к уже существующему массиву
void sortLinks(array<int,10>& arr) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

//по указателю:
//1)в функцию передается не сам массив, а его адрес(где он находится в памяти)
//2)адрес может быть пустым(равным nullptr), это означает, что он ни на что не указывает
void sortPointer(array<int,10>* arr) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            if ((*arr)[j] > (*arr)[j+1])
                swap((*arr)[j], (*arr)[j+1]);
}




int main() {
    vector<int> massive = {1, -2, 5, 5, 3};

    while (true) {
        cout << "Меню:" << endl;
        cout << "0. Выход" << endl;
        cout << "1. Просмотр массива" << endl;
        cout << "2. Добавить в начало" << endl;
        cout << "3. Добавить в конец" << endl;
        cout << "4. Очистить" << endl;
        cout << "5. Поиск элемента" << endl;
        cout << "6. Задание варианта 3" << endl;
        cout << "7. Сортировки массива (array)" << endl;
        cout << "Ваш выбор: "<< endl;
        
        int point; 
        cin >> point;

        if (point == 0) {
            break;
        }

        else if (point == 1) {
            printMassive(massive);
        }
        else if (point == 2) {
            int num; 
            cout << "Введите число: ";
            cin >> num;
            cout << "До: "; 
            printMassive(massive);
            pushFront(massive, num);
            cout << "После: "; 
            printMassive(massive);
        }
        else if (point == 3) {
            int num;
            cout << "Введите число: ";
            cin >> num;
            cout << "До: "; 
            printMassive(massive);
            pushBack(massive, num);
            cout << "После: ";
            printMassive(massive);
        }
        else if (point == 4) {
            cout << "До: ";
            printMassive(massive);
            clearMassive(massive);
            cout << "После: ";
            printMassive(massive);
        }
        else if (point == 5) {
            int num;
            cout << "Введите элемент: ";
            cin >> num;
            printMassive(findIndex(massive, num));
        }
        else if (point == 6) {
            cout << "До: ";
            printMassive(massive);
            vrnt(massive);
            cout << "После: ";
            printMassive(massive);
        }
        else if (point == 7) {
            array<int,10> arr = {3,-1,5,0,-2,9,7,-3,4,1};
            array<int,10> arr1 = arr, arr2 = arr, arr3 = arr;

            sortElements(arr1);
            sortLinks(arr2);
            sortPointer(&arr3);

            cout << "После sortElements: ";
            for (int i = 0; i < arr1.size(); i++) {
                cout << i << " ";
            }
            cout << "\n";

            cout << "После sortLinks: ";
            for (int i = 0; i < arr2.size(); i++) {
                cout << i << " ";
            }
            cout << "\n";

            cout << "После sortPointer: ";
            for (int i = 0; i < arr3.size(); i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}