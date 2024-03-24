#include <iostream>
#include <string>
#include <math.h>
#include ".\Matrix.h"
using namespace std;

//double* create(double* matr, int n, int iskI, int iskJ) {
//    double* matrix = new double[n * (n - 2) + 1];
//    int k, l = 0;
//    for (int i = 0; i < n; i++) {
//        k = 0;
//        if (i != iskI) {
//            for (int j = 0; j < n; j++) {
//                if (j != iskJ) {
//                    elem(matrix, l, k, n - 1) = elem(matr, i, j, n);
//                    k++;
//                }
//            }
//            l++;
//        }
//    }
//    return matrix;
//}
//
//double det_Minors(double *matr, int n)
//{
//    if (n == 1) return matr[0];
//    double S = 0;
//    double el = 1.0;
//    double* minor;
//    for (int j = 0; j < n; j++) {
//        if (elem(matr, 0, j, n) != 0) {
//            minor = create(matr, n, 0, j);
//            S += el * elem(matr, 0, j, n) * det_Minors(minor, n - 1);
//            delete [] minor;
//        }
//        el = -el;
//    }
//    return S;
//}

matrix::matrix()                                  //constructor for matrix
{
    int col, row;
    cout << "vvedite col and row \n";
    cin >> col >> row;
    this->col = col;
    this->row = row;

    size = (this->col * this->row);

    mas = new double[size];
}

matrix::matrix(int valueROW, int valueCOL)       //constructor for matrix 2
{
    col = valueCOL;
    row = valueROW;

    size = (valueROW * valueCOL);

    mas = new double[size] {};
}

matrix::matrix(int valueROW, int valueCOL, const double* arr)
{
    col = valueROW;
    row = valueCOL;
    size = (valueROW * valueCOL);
    mas = new double[size];

    for (int i = 0; i < size; i++)
    {
        this->mas[i] = arr[i];
    }
}

void matrix::fini()                                     //function for int matrix
{
    for (int i = 0; i < this->size; i++)
    {
        // int d;
        cout << "int element " << i + 1 << " of matrix" << " \n";               //cin >> d;
        cin >> this->mas[i];
    }
}

void matrix::fini(int valueROW, int valueCOL)                                     //function for int matrix  '2'
{
    if ((valueROW * valueCOL) == this->size)
    {
        for (int i = 0; i < (valueROW * valueCOL); i++)
        {
            int d;
            cout << "int element " << i + 1 << " of matrix" << " \n";               cin >> d;
            this->mas[i] = d;
        }
    }
    else
    {
        cout << "size of matrix andsize of arr nor equal\n\n";
    }
}

void matrix::fini(int valueROW, int valueCOL, double* arr)                        //function for int matrix  '3'
{
    if ((valueROW * valueCOL) == this->size)
    {
        for (int i = 0; i < (valueROW * valueCOL); i++)
        {
            this->mas[i] = arr[i];
        }
    }
    else
    {
        cout << "size of matrix andsize of arr nor equal\n\n";
    }
}

void matrix::fini(int* n)
{
    if (mas != nullptr)
    {
        delete[]mas;
    }

    mas = new double[size];

    for (int i = 0; i < size; i++)
    {
        mas[i] = n[i];
    }
}

double matrix::get_elem(int i, int j) const
{
    if (i == j) return mas[row + i];
    else if (i == j + 1) return mas[row * 2 + i];
    else if (i + 1 == j) return mas[i];
    else return 0;
}

void matrix::fouti() const                                                    //function for cout matrix
{
                                                               //liney variant
        /*for (int i = 0; i < this->size; i++)
        {
            cout << this->mas[i] << "\t";
        }
        cout << endl;*/

    cout << endl;
    int k = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (k == col)
        {
            cout << endl;
            k = 0;
        }
        cout << this->mas[i]<<"\t";
        k++;
    }
    cout << "\n\n";

    /*if ((this->col != 2 || this->row != 2))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                std::cout << "    " << this->get_elem(i, j) << "\t";
            }
            std::cout << "\n";
        }
    }
    else
    {
        int k = 0;
        for (int i = 0; i < (this->row * this->col); i++)
        {
            if (k == col)
            {
                cout << endl;
                k = 0;
            }
            cout << this->mas[i] << "\t";
            k++;
        }
    }

    cout << "\n\n\n";*/
}

void matrix::funch()                                                         //function for umnozhenie matrix on number
{
    cout << "int number for umnozhenie" << endl;
    int d;                                                 cin >> d;
    for (int i = 0; i < size; i++)
    {

        this->mas[i] = (mas[i] * d);
    }
}

matrix matrix::funch(double num)                                          //function for umnozhenie matrix on number '2'
{
    matrix a(this->col, this->row);

    for (int j = 0; j < this->size; j++)
    {
        a.mas[j] = this->mas[j];
    }

    for (int i = 0; i < this->size; i++)
    {

        a.mas[i] *= num;
    }

    return a;
}

void matrix::func_sum_mat(matrix& f){                                                       //function for sum matrix on matrix
    for (int i = 0; i < size; i++)
    {
        this->mas[i] += f.mas[i];
    }
}

void matrix::func_sum_mat(const double* arr)
{
    for (int i = 0; i < this->size; i++)
    {
        this->mas[i] += arr[i];
    }
}

void matrix::func_sum_mat(const double* arr, int size)
{
    if (this->size == size)
    {
        for (int i = 0; i < this->size; i++)
        {
            this->mas[i] += arr[i];
        }
    }
    else
    {
        cout << "size of matrix andsize of arr nor equal\n\n";
    }
}

void matrix::func_umn_mat(matrix& q)                                       //umnoxhenie two matrix                   
{
    for (int i = 0; i < size; i++)
    {
        this->mas[i] *= q.mas[i];
    }
}

void matrix::func_umn_mat(const double* arr, int size)
{
    if (this->size == size)
    {
        for (int i = 0; i < size; i++)
        {
            this->mas[i] *= arr[i];
        }
    }
    else
    {
        cout << "size of matrix andsize of arr nor equal\n\n";
    }
}

double matrix::func_sled_mat(const matrix& d)                                              //sled matrix of formula: ((i*k)+k)+((i*k)-k); i=rows or column 
{
    if (row == col)
    {
        int k = 0;   int i = 0;   double sum = 0;

        while (i < size - 1)
        {
            i = (row * k) + k;
            sum += d.mas[i];
            k++;
        }

        /* k = 1;   i = 0;
         while (i < size - row)
         {
             i = (row * k) - k;
             sum += d.mas[i];
             k++;
         }*/

        return sum;

    }
    else
    {
        cout << "ne kvadr\n";

    }
    return 0;
}

int matrix::func_get_elem(int j, int i)
{
    int ind = (j * i) - 1;
    cout << "N[i,j]=" << this->mas[ind] << "\n\n";
    return 0;
}

int matrix::func_get_col()
{
    cout << "columns= " << this->col << "\n\n";
    return 0;
}

int matrix::func_get_row()
{
    cout << "rows= " << this->row << "\n\n";
    return 0;
}

double matrix::func_det_matrix()     // opredelitel
{
    double resultat = 0;
    if (this->col == 3 && this->row == 3)
    {
        int k = 0;   int i = 0;   double sum = 1;

        while (i < size - 1)
        {
            i = (row * k) + k;
            sum *= this->mas[i];
            k++;
        }

        sum += (this->mas[2] * this->mas[3] * this->mas[7]) + (this->mas[1] * this->mas[5] * this->mas[6]);
        resultat = sum;
        k = 1;   i = 0; sum = 1;

        while (i < size - row)
        {
            i = (row * k) - k;
            sum *= this->mas[i];
            k++;
        }

        sum += (this->mas[0] * this->mas[5] * this->mas[7]) + (this->mas[8] * this->mas[1] * this->mas[3]);
        return resultat - sum;
    }
    else
    {
        cout << "matrix not 3x3";
        return 0;
    }

}

void matrix::operator-()
{
    return *this * (-1.0);
}

void matrix::operator*(double num)
{
    for (int i = 0; i < this->size; i++)
    {
        this->mas[i] *= num;
    }
}

void matrix:: operator + (const matrix& matr1)
{
    if (this->col == matr1.col && this->row == matr1.row)
    {
        matrix rezult(this->col, this->row);

        for (int i = 0; i < rezult.size; i++)
        {
            rezult.mas[i] += (this->mas[i] + matr1.mas[i]);
        }

        rezult.fouti();

    }
    else
    {
        cout << "errrrrror\n";
    }
}

void matrix:: operator - (const matrix& matr1)
{
    if (this->col == matr1.col && this->row == matr1.row)
    {
        matrix rezult_1(this->col, this->row);

        for (int i = 0; i < rezult_1.size; i++)
        {
            rezult_1.mas[i] += (this->mas[i] - matr1.mas[i]);
        }

        rezult_1.fouti();

    }
    else
    {
        cout << "errrrrror\n";
    }
}

matrix matrix::operator * (const matrix& matr1)
{
    if (this->size == matr1.size)
    {
        /*matrix rezult_2(this->col, this->row);

        for (int i = 0; i < rezult_2.size; i++)
        {
            rezult_2.mas[i] = (this->mas[i] * matr1.mas[i]) + (this->mas[i + 1] * (matr1.mas[(i + 1) * matr1.col])) + (this->mas[i + 2] * matr1.mas[(i + 2) * matr1.col]);
        }

        rezult_2.fouti();*/

        cout << "\nMATRIX1 * MATRIX2\n";

    }else if(matr1.col==1) {
        matrix rezult_3(3, 1);

            for (int i = 0; i < rezult_3.size; i++){
                int temp = 0;
                for (int j = 0; j < rezult_3.size; j++)
                {
                    temp += this->mas[i * rezult_3.size + j] * matr1.mas[j];
                }
                rezult_3.mas[i] = temp;
            } 
            return rezult_3;
    }
    else
    {
        cout << "errrrrror\n";
    }
}

void matrix::operator += (const matrix& matr2)
{
    for (int i = 0; i < this->size; i++)
    {
        this->mas[i] += matr2.mas[i];
    }
}

void matrix::operator -= (const matrix& matr2)
{
    for (int i = 0; i < this->size; i++)
    {
        this->mas[i] -= matr2.mas[i];
    }
}

void matrix::operator = (const matrix& matr2)
{
    for (int i = 0; i < this->size; i++)
    {
        this->mas[i] = matr2.mas[i];
    }
}

std::ostream& operator << (ostream& in, matrix& matr)
{
    /*for (int i = 0; i < matr.row; i++) {
        for (int j = 0; j < matr.row; j++) {
            in << "    " << matr.get_elem(i, j) << "\t";
        }
        in << '\n';
    }*/
    matr.fouti();
    return in;
}

std::istream& operator >> (istream& in, matrix& matr)
{
   /* int size;
    size = matr.col;*/

    matr.fini();
    return in;
}

void matrix::clear(){
}