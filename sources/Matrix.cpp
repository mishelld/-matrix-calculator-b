#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;
namespace zich{
 //constructor
Matrix::Matrix( const vector <double> &vec1,const int row1,const int col1) {
    
        if (row1 * col1!= vec1.size())
        {
             throw invalid_argument("row or col dosent match matrix size");
        }
        if (row1 <= 0 || col1 <= 0)
        {
             throw invalid_argument("row or col is negetive");
        }

    vec = vec1;
    row = row1;
    col = col1;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// a + b operator
    Matrix Matrix ::operator+(const Matrix &other){
     if(this->row!=other.row || this->col!=other.col){
         throw invalid_argument("row or col not equal");
    }
    Matrix copy = *this;
    for(unsigned int i =0;i<this->vec.size();i++){
        copy.vec[i]+=other.vec[i];
    }
    return copy;
}
//++a
    Matrix &Matrix ::operator++(){
    for(unsigned int i =0;i<this->vec.size();i++){
              this->vec[i]+=1;
          }
             return *this;
       }

//a++    
    Matrix Matrix ::operator++(const int num){
            Matrix copy = *this;
             for(unsigned int i =0;i<this->vec.size();i++){
              this->vec[i]+=1;
    }
    return copy;

       }
 //a+=b      
    Matrix  &Matrix ::operator+=(const Matrix &other){
    if(this->row!=other.row || this->col!=other.col){
         throw invalid_argument("row or col not equal");
    }
     for(unsigned int i = 0;i<this->vec.size();i++){
            this->vec[i] = other.vec[i] + this->vec[i];
        }
    return *this;
      }

//a*1
    Matrix operator+(Matrix &other){
     Matrix copy = other;
     for( unsigned int i = 0;i<other.vec.size();i++){
            copy.vec[i]*=1;
        }
        return copy;

      }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//a-b
    Matrix Matrix ::operator-(const Matrix &other){
      if(this->row!=other.row || this->col!=other.col){
         throw invalid_argument("row or col not equal");
    }
     Matrix copy = *this;
     for( unsigned int i = 0;i<this->vec.size();i++){
            copy.vec[i]-=other.vec[i];
        }
        return copy;

 }
//--a 
    Matrix &Matrix ::operator--(){
    for( unsigned int i =0;i<this->vec.size();i++){
        this->vec[i]-=1;
    }
    return *this;


}
//a--
    Matrix Matrix ::operator--(const int num){
    Matrix copy = *this;
    for( unsigned int i =0;i<this->vec.size();i++){
        this->vec[i]-=1;
    }
    return copy;
}
//a-=b
    Matrix &Matrix ::operator-=(const Matrix &other){
      if(this->row!=other.row || this->col!=other.col){
         throw invalid_argument("row or col not equal");
    }
     for( unsigned int i = 0;i<this->vec.size();i++){
            this->vec[i]-=other.vec[i];
        }
        return *this;

}
//-1*a
    Matrix operator-(Matrix &other){
    Matrix copy = other;
     for( unsigned int i = 0;i<other.vec.size();i++){
         if( copy.vec[i]!=0){
            copy.vec[i]*=-1;
         }
        }
        return copy;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//a*b
    Matrix Matrix ::operator*(const Matrix &other){
    if(this->col!=other.row){
         throw invalid_argument("row or col not equal");
    }
    vector <double> temp;
    unsigned int row_b = (unsigned int)other.row;
    unsigned int col_b = (unsigned int)other.col;
    for (unsigned int k = 0;k<this->row;k++){
    for(unsigned int i = 0 ; i<other.col;i++){
     double sum = 0;
    for(unsigned int j = 0;j<other.row;j++){
       sum += this->vec[row_b*k+j] * other.vec[col_b*j+i];
      
     }
     temp.push_back(sum);
   }
  
   }
     Matrix copy{temp,this->row,other.col};
    return copy;
      }
 //a*mat;     
    Matrix Matrix ::operator*(const double scalar){
        Matrix copy = *this;
         
         for(unsigned int i = 0 ; i<this->vec.size();i++){
             if(copy.vec[i]!=0){
             copy.vec[i] *= scalar;
             }
            
         }
          return copy;

        }
//a*=b        
    Matrix &Matrix ::operator*=(const Matrix &other){
          if(this->col!=other.row ){
         throw invalid_argument("row or col not equal");
         }
         *this = (*this * other);
         return *this;
        }
//this*=  a     
    Matrix &Matrix ::operator*=(const double scalar){
         for(unsigned int i = 0 ; i<this->vec.size();i++){
             if(this->vec[i]!=0){
             this->vec[i] *= scalar;
             }
         }
          return *this;
        }
      
//a*this
    Matrix operator*(const double scalar, Matrix &other){
        Matrix copy = other;
         for(unsigned int i = 0 ; i<other.vec.size();i++){
             copy.vec[i] *= scalar;
         }
          return copy;

      }
//this>mat
    bool Matrix :: operator>(const Matrix& other)const{
        if(other.row!=this->row || other.col!=this->col){
         throw invalid_argument("row or col not equal");
          }
        int sum_this =0;
        int sum_other =0;
        for(unsigned i = 0;i<other.vec.size();i++){
            sum_this += other.vec[i];
            sum_other += this->vec[i];

        }
        return (sum_other>sum_this);
      }
//this>=mat      
    bool  Matrix ::operator>=(const Matrix& other)const{
     if(other.row!=this->row || other.col!=this->col){
        throw invalid_argument("row or col not equal");
             }
     return (operator>(other) || operator==(other));
     }

//this<mat     
    bool  Matrix ::  operator<(const Matrix& other)const{
     if(other.row!=this->row || other.col!=this->col){
         throw invalid_argument("row or col not equal");
    }
        int sum_this =0;
        int sum_other =0;
        for(unsigned i = 0;i<other.vec.size();i++){
            sum_this += other.vec[i];
            sum_other += this->vec[i];

        }
        return (sum_other<sum_this);
    }
//this<=mat    
    bool  Matrix ::  operator<=(const Matrix& other)const{
     if(other.row!=this->row || other.col!=this->col){
     throw invalid_argument("row or col not equal");
             }
      return (operator<(other) || operator==(other));
    }  
//this==mat    
    bool  Matrix :: operator==(const Matrix& other)const{
     if(other.row!=this->row || other.col!=this->col){
     throw invalid_argument("row or col not equal");
             }
    for(unsigned i = 0;i<other.vec.size();i++){
        if(other.vec[i]!=this->vec[i]) {
          return false;
          }
        }
        return true;
            }
 //this!=mat           
    bool  Matrix :: operator!=(const Matrix& other)const{
        return (!(operator==(other)));
    }
        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
   //input
    istream &operator>>(istream &os, Matrix &mat){
        char ch = 0;
        string str;
        vector <string> str_copy;       
        vector <double> temp; 
        
        while(ch!='\n'){
            ch = os.get();
            //create vector with the values of the matrix 
            if(ch>num1 && ch<num2){
                int con = ch - '0';
               temp.push_back(con);
            }
            //split the input string without the char ','
            //so it wiil be ex:[1 2 3] [4 5 6]... and not [1 2 3], [4 5 6],.....
            if(ch!=','  && ch!='\n'){
            str+= ch;
            }
            else{
            str_copy.push_back(str);
            str = "";
             }

        }
        string first_row = str_copy.at(0);
        int siz = first_row.size();  

        //if the amount of right bar not equal left bar throw error(check for first row)
        if(first_row.at(0)!='[' && first_row.at(first_row.size()-1)!=']'){
              throw invalid_argument("bad input, no 1");
         }
     
        for (size_t i = 1; i < str_copy.size(); i++)
        {

         string any_row =  str_copy.at(i);
        //if num of col not equal other num of col throw error
         if(any_row.size()!=siz+1){
           
        throw invalid_argument("bad input, not same size");
         }
        //if there is extra space throw error 
         if(any_row.at(0)!=' '){
             throw invalid_argument("bad input, extra space");
         }
         //if the amount of right bar not equal left bar throw error
         if(any_row.at(1)!= '[' && any_row.at(any_row.size()-1)!= ']'){
              throw invalid_argument("bad input, uneven num of bars");
         }
           
        }

        //check num of ch in col
        int col = 0;
        for (size_t i = 0; i <str_copy.at(0).size(); i++)
        {
            char c = first_row.at(i);
            if(c>'0' && c<'9'){
            col++;
            }
        }
        //create new matrix 
        Matrix a(temp,str_copy.size(),col);
        overide(mat, a);
        return os;  
    }


    void overide(Matrix &mat, Matrix &other){
        mat = other;
    }
    //output
    ostream &operator<<(ostream &os, const Matrix &mat) {
      unsigned int k = 0;
      int j = 0;
       for(unsigned int i =0;i<mat.row;i++){
            os << '[';
           for(unsigned int j =0;j<mat.col;j++,k++){
                if(j+1==mat.col){
                os << mat.vec[k];
                }
                else{
                os << mat.vec[k] <<" ";
                 }
                }
                if(i+1==mat.row){
                 os << "]";
                 }
                else{
                os << "]" << '\n';
                 }
                }
        
            
        return os ;
        
      
    }

   

}
     


