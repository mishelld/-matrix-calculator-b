#include <iostream>
#include <string>
#include <vector>

#include <map>

using namespace std;
const int num1 = 47;
const int num2 = 58;

  
namespace zich {
    class Matrix {        
  public:          
    vector<double> vec;
    int row;
    int col;
    Matrix(const vector<double> &vec,const int row,const int col);

        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix operator*(const Matrix &other);
        Matrix &operator++();
        Matrix &operator--();
        Matrix operator++(const int num);
        Matrix operator--(const int num);
        Matrix operator*(const double scalar);
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const Matrix &other);
        Matrix &operator*=(const double scalar);
        friend Matrix operator+(Matrix &other);
        friend Matrix operator-(Matrix &other);
        friend Matrix operator*(const double scalar, Matrix &other);
        bool operator>(const Matrix& other)const;
        bool operator>=(const Matrix& other)const;
        bool operator<(const Matrix& other)const;
        bool operator<=(const Matrix& other)const;
        bool operator==(const Matrix& other)const;
        bool operator!=(const Matrix& other)const;
        friend ostream &operator<<(ostream &os, const Matrix &mat);
        friend istream &operator>>(istream &os, Matrix &mat);
};
void overide(Matrix &mat, Matrix &other);
}