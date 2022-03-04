#include <bits/stdc++.h>

using namespace std;

void input_arr (float arr[][250], int &row, int &column){
    cout << "enter row, column: ";
    cin >> row >> column;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> arr[i][j];
}

void print_arr (float arr[][250], int row, int column){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void swap (float &a, float &b){
    float tmp = a;
    a = b;
    b = tmp;
}

void swap_row (float arr[][250], int cur_row, int target_row, int column){
    for (int i = 0; i < column; i++)
        swap (arr[cur_row][i], arr[target_row][i]);
}

void transfer_data (float arr[][250], float arr_clone[][250], int row, int column){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr_clone[i][j] = arr[i][j];
}

void subtract (float arr[][250], int cur_row, int target_row, float target, int column){
    for (int i = 0; i < column; i++){
        arr [cur_row][i] -= (arr[target_row][i]*target);
    }
}

float not0 (float arr[][250], int cur_row, int cur_column, int row){
    for (int i = cur_row; i < row; i++){
        if (arr[i][cur_column] != 0)
            return i;
    }
    return -1;
}

int count0_line (float arr[][250], int column, int cur_row){
    int count = 0;
    for (int i = 0; i < column; i++){
        if (i > 1){
            if (arr[cur_row][i] != 0)
                break;
        }

        if (arr[cur_row][i] == 0)
            count++;
    }
    return count;
}

void echelon (float arr[][250], int row, int column){
    for (int i = 0; i < row; i++){
        if (arr[i][i] == 0){
            int line = not0 (arr, i, i, row); // finding divisor
            if (line == -1) // all number in column i == 0 (1)
                continue;
            else
                swap_row (arr, i, line, column);
        }
        for (int j = row -1; j > i; j--){
            float target = arr[j][i] / arr[i][i];
            subtract (arr, j, i, target, column);
        }
        print_arr (arr, row, column);
        cout << endl;
    }

// this part is not finished yet
//    for (int k = 0; k < row -1; k++){
//        for (int i = row -1; i > 0; i--){
//            int ci = count0_line(arr, column, i);
//            int ci1 = count0_line(arr, column, i-1);
//
//            if (ci == ci1){
//                float target = arr[i][ci] / arr[i-1][ci1];
//                subtract (arr, i, i-1, target, column);
//            }
//        }
//    }
}

int main(){

    float A[250][250];
    float A_clone[250][250];

    int row, column;

    input_arr (A, row, column);

    print_arr (A, row, column);
    cout << endl;

    cout << "\nma tran bac thang\n";

    transfer_data (A, A_clone, row, column);
    echelon (A_clone, row, column);
    print_arr (A_clone, row, column);

    return 0;
}
