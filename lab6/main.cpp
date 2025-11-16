#include <iostream>
#include <cstdlib> 
using namespace std;

//3 вариант

//--------------------------------------------------------------------------------------------------задание 1 

int* find_zero(int** matrix, int rows, int cols, int& zero_cnt) {
    int* has_zero = (int*)calloc(cols, sizeof(int));
    zero_cnt = 0;
    
    for(int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                has_zero[j] = 1;
                zero_cnt++;
                break;
            }
        }
    }

    int* zero_cols = (int*)malloc(zero_cnt * sizeof(int));
    int index = 0;
    for(int j = 0; j < cols; j++) {
        if (has_zero[j] == 1) {
            zero_cols[index++] = j;
        }
    }
    free(has_zero);

    return zero_cols;
}

int** remove_cols(int** matrix, int rows, int& cols, int* zero_cols, int zero_cnt) {
    if (zero_cnt == 0) {
        return matrix;
    }
    
    int new_cols = cols - zero_cnt;
    
    int** new_matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_matrix[i] = (int*)malloc(new_cols * sizeof(int));
        
        int new_j = 0;
        for (int j = 0; j < cols; j++) {
            bool skip = false;
            for (int k = 0; k < zero_cnt; k++) {
                if (j == zero_cols[k]) {
                    skip = true;
                    break;
                }
            }
            
            if (!skip) {
                new_matrix[i][new_j++] = matrix[i][j];
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    cols = new_cols; 

    return new_matrix;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------------------------------------------задание 2
/*
void pointers() {
        float a, b;
        cin >> a;
        cin >> b;

        float* p_a = new float(a);
        float* p_b = new float(b);

        *p_a *= 3;

        float num_a = *p_a;
        *p_a = *p_b;
        *p_b = num_a;

        a = *p_a;
        b = *p_b;

        cout << "A = " << a << ", B = " << b << endl;
        
        delete p_a;
        delete p_b;
    }
*/
//-----------------------------------------------------------------------------------------------------------


int main() {

    int rows = 2;
    int cols = 2;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    int a, b, c, d;
    do {
        cout << "A для добавления снизу" << endl;
        cin >> a;
        cout << "B для добавления справа" << endl;
        cin >> b;

        if((a < 0) || (b < 0)) {
            cout << "A, B - отрицательные. Повторите ввод" << endl;
        }
    } while((a < 0) || (b < 0));

    cout << "Введите C" << endl;
    cin >> c;
    cout << "Введите D" << endl;
    cin >> d;

    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
    int new_rows = 2 + a;
    int new_cols = 2 + b;

    int** new_matrix = (int**)calloc(new_rows, sizeof(int*));
    for(int i = 0; i < new_rows; i++) {
        new_matrix[i] = (int*)calloc(new_cols, sizeof(int));
    }

    for(int i = 0; i < new_rows; i++) {
        for(int j = 0; j < new_cols; j++) {
            if((i < 2) && (j < 2)) {
                new_matrix[i][j] = matrix[i][j];
            }
            else {
                new_matrix[i][j] = (((i - 1) * c) + ((j - 1) * d));
            }
        }
    }

    int zero_cnt;
    int* zero_cols = find_zero(new_matrix, new_rows, new_cols, zero_cnt);

    int current_cols = new_cols;
    int** final_matrix = remove_cols(new_matrix, new_rows, current_cols, zero_cols, zero_cnt);

    print_matrix(final_matrix, new_rows, current_cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    free(zero_cols);

    for (int i = 0; i < new_rows; i++) {
        free(final_matrix[i]);
    }
    free(final_matrix);



    //--------------------------------------------------------------------------------------------------задание 2
    /*
    pointers();
    */
    //------------------------------------------------------------------------------------------------------------

    return 0;
}