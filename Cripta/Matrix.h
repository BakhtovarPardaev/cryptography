#pragma once
using namespace std;

class matrix
{
public:

    double* mas;
    int col;
    int row;
    int size;

    matrix();                                                                        //constructor for matrix

    matrix(int valueROW, int valueCOL);                                              //constructor for matrix '2'

    matrix(int valueROW, int valueCOL, const double* arr);                           //constructor for matrix '3'

    void fini();                                                                     //function for int matrix

    void fini(int i, int j);                                                         //function for int matrix '2'

    void fini(int valueROW, int valueCOL, double* arr);                              //function for int matrix '3'

    void fini(int *size);                                                             //function for int matrix '4'

    double get_elem(int i, int j) const;                                             //vspomogat func for function for cout matrix

    void fouti() const;                                                              //function for cout matrix

    void funch();                                                                    //function for umnozhenie matrix on number

    matrix funch(double num);                                                        //function for umnozhenie matrix on number '2'

    void func_sum_mat(matrix& f);                                                    //function for sum matrix on matrix

    void func_sum_mat(const double* are);                                            //function for sum matrix on mas

    void func_sum_mat(const double* arr, int size);                                  //function for sum matrix on mas '2'

    void func_umn_mat(matrix& q);                                                    //umnoxhenie two matrix

    void func_umn_mat(const double* arr, int size);                                  //umnoxhenie matrix on mas

    double func_sled_mat(const matrix& d);                                           //sled matrix of formula: ((i*k)+k); i=rows or column 

    int func_get_elem(int j, int i);

    int func_get_col();

    int func_get_row();

    double func_det_matrix();        //for 3x3

    void operator-();

    void operator += (const matrix& matr2);

    void operator -= (const matrix& matr2);

    void operator = (const matrix& matr2);

    void operator*(double num);

    void operator + (const matrix& matr1);

    void operator - (const matrix& matr1);

    matrix operator*(const matrix& matr1);

    friend std::ostream& operator << (std::ostream& out, matrix& matr);

    friend std::istream& operator >> (std::istream& in, matrix& matr);
    void clear();


    ~matrix()                                                                //destructor on matrix
    {
        delete[] mas;
    }
};
