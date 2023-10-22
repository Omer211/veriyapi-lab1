

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
    //Takes the data from the file and dumps it into a table
    ifstream file;
    string filename;
    cout << "Enter the filename: ";  cin >> filename; cout << "\n";
    file.open(filename);
    int column, row;
    string line;
    if (file.is_open()) {
        
        file >> row >> column;
        getline(file, line);
        cout << "  ";
        for (int i=0, j = 0; i < column; i++, j++) {
            if (j == 10)j = 0;
            cout << j;
        } 
        cout << endl << " " << '+';
        for (int i = 0; i < column; i++)cout << '-';
        cout << '+' << endl;
        for (int i = 0,j=0; i < row; i++,j++) {
            getline(file, line);
            if (j == 10)j = 0;
            cout << j << '|'<<line<<'|'<<j<<endl;
        }
        cout << " " << '+';
        for (int i = 0; i < column; i++)cout << '-';
        cout << '+' << endl<<"  ";
        for (int i = 0, j = 0; i < column; i++, j++) {
            if (j == 10)j = 0;
            cout << j;
        }
        //End of the first table

        //Put the algorithm below here
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, j = 0, k = 0, l = 0, m = 0;








        //End of the main algorithm

        //Second table
        cout << "\n\n\n\n";
        cout << "+- - - - - - + - - - - - - - - + - - - - - - - + -  - - - - - - - +"<<endl;
        cout << "|    BLOB    |    NoOfPixels   |    CoM Row    |    CoM Column    |" << endl;
        cout << "+- - - - - - + - - - - - - - - + - - - - - - - + -  - - - - - - - +" << endl;
        cout << "|           " << a << "|                " << b << "|              " << c << "|                 " << d << '|'<<endl;
        cout << "|           " << e << "|                " << f << "|              " << g << "|                 " << h << '|' << endl;
        cout << "|           " << j << "|                " << k << "|              " << l << "|                 " << m << '|' << endl;
        cout << "+- - - - - - + - - - - - - - - + - - - - - - - + -  - - - - - - - +" << endl;












        //End of the second table
    }









    file.close();
    return 0;
    
}

