#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int countblobAl(int** mat, int row, int col, int old_num, int new_num, int x, int y, int& comRow, int& comCol);
static int c = 0;

int main() {
    string nameoffile;
    cout << "Enter name of txt file (with .txt): ";
    cin >> nameoffile;
    char ch;
    int s = 0, row, col, number, num, count_number, p = 0, i, x, cou = 0;
    fstream fileof_data(nameoffile, ios::in);

    int** mat = nullptr;

    if (!fileof_data.is_open()) {
        cout << "FAIL" << endl;
        return 1;
    }
    else {
        fileof_data >> num;
        row = num;
        fileof_data >> num;
        col = num;
        cout << "Row:" << row << " Col:" << col << endl << "  ";

        while (p < col) {
            cout << p % 10;
            p++;
        }

        mat = new int* [row]; // Matrisi burada dinamik olarak oluþtur
        for (int i = 0; i < row; ++i) {
            mat[i] = new int[col];
        }

        while (fileof_data.get(ch)) { // Tek karakter okuma iþlemi
            cout << ch;
            if (ch == '\n') {
                if (s / col != row) {
                    cout << s / col << " ";
                }
                continue;
            }

            if (ch == ' ' || ch == 'x') {
                if (ch == 'x') {
                    number = 1;
                }
                else if (ch == ' ') {
                    number = 0;
                }
                mat[s / col][s % col] = number;
                s++;

                if (s / col == row) {
                    break; // Matrisin sonunu kontrol et
                }
            }
        }
    }

    int x_coor, y_coor;
    cout << endl << "--------------------------------------------------------" << endl;
    cout << "BLOB  |  NoOfPixels  |  CoM Row  |  CoM Column" << endl;
    cout << endl << "--------------------------------------------------------" << endl;
    for (x_coor = 0; x_coor < row; x_coor++) {
        for (y_coor = 0; y_coor < col; y_coor++) {
            if (mat[x_coor][y_coor] == 1) {
                c = 0; // Her yeni blob için sýfýrla
                int comRow = 0;
                int comCol = 0;
                count_number = countblobAl(mat, row, col, 1, 2, x_coor, y_coor, comRow, comCol);
                cou++;

                float comRowFloat = static_cast<float>(comRow) / count_number;
                float comColFloat = static_cast<float>(comCol) / count_number;

                cout << endl << "   " << cou << "   |       " << count_number
                    << "    |    " << setprecision(3) << comRowFloat
                    << "      |  " << setprecision(3) << comColFloat << endl;
            }
        }
    }

    // Çýktýlarýnýzda hata var

    for (int i = 0; i < row; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}

int countblobAl(int** mat, int row, int col, int old_num, int new_num, int x, int y, int& comRow, int& comCol) {
    if (x >= row || x < 0) {
        return 0;
    }
    if (y >= col || y < 0) {
        return 0;
    }
    if (mat[x][y] != old_num) {
        return 0;
    }
    mat[x][y] = new_num;
    c++;
    comRow += x; // CoM hesaplamasýný burada güncelle
    comCol += y;
    countblobAl(mat, row, col, old_num, new_num, x + 1, y, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x + 1, y + 1, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x - 1, y, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x - 1, y - 1, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x, y + 1, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x - 1, y + 1, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x, y - 1, comRow, comCol);
    countblobAl(mat, row, col, old_num, new_num, x + 1, y - 1, comRow, comCol);
    return c;
}
