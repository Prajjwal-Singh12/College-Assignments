//STRASSEN'S MATRIX MULTIPLICATION
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}


template<typename T>
class Matrix 
{
              private:
        int rows;
        int cols;
        vector<vector<T>> matrix;

        Matrix multiply(const Matrix& matrix1, const Matrix& matrix2) 
		{
            if (matrix1.rows == 1) 
            return Matrix(1, 1, matrix1.matrix[0][0] * matrix2.matrix[0][0]); 

            //--------------------------------------------------------------------------//
            // Divide into four segment
            // ---       ---   ---       ---   ---       ---
            // | A11 | A12 |   | B11 | B12 |   | C11 | C12 |
            // |-----|-----| x |-----|-----| = |-----|-----|
            // | A21 | A22 |   | B21 | B22 |   | C21 | C22 |
            // ---       ---   ---       ---   ---       ---
            //
            // ---       ---   ---                                   ---
            // | C11 | C12 |   | M1 + M4 - M5 + M7 |      M3 + M5      | 
            // |-----|-----| = |-------------------|-------------------|
            // | C21 | C22 |   |      M2 + M4      | M1 - M2 + M3 + M6 |
            // ---       ---   ---                                   ---
            // 1, 2, 4, 8, 16 ... 2^n
            // where
            //
            // M1 = (A11 + A22) * (B11 + B22)
            // M2 = (A21 + A22) * B11
            // M3 = A11 * (B12 - B22)
            // M4 = A22 * (B21 - B11)
            // M5 = (A11 + A12) * B22
            // M6 = (A21 - A11) * (B11 + B12)
            // M7 = (A12 - A22) * (B21 + B22)
            //--------------------------------------------------------------------------//
                
            int order = (matrix1.rows >> 1);

            Matrix A11(order, order, 0);
            Matrix A12(order, order, 0);
            Matrix A21(order, order, 0);
            Matrix A22(order, order, 0);

            Matrix B11(order, order, 0);
            Matrix B12(order, order, 0);
            Matrix B21(order, order, 0);
            Matrix B22(order, order, 0);

            Matrix C11(order, order, 0);
            Matrix C12(order, order, 0);
            Matrix C21(order, order, 0);
            Matrix C22(order, order, 0);

            Matrix M1(order, order, 0);
            Matrix M2(order, order, 0);
            Matrix M3(order, order, 0);
            Matrix M4(order, order, 0);
            Matrix M5(order, order, 0);
            Matrix M6(order, order, 0);
            Matrix M7(order, order, 0);


            for (int i = 0; i < matrix1.rows; ++i) 
			{
                for (int j = 0; j < matrix1.cols; ++j) 
				{
                    if (i < order && j < order) {
                        A11[i][j] = matrix1.matrix[i][j];
                        B11[i][j] = matrix2.matrix[i][j];
                    } else if (i >= order && j < order) {
                        A21[i - order][j] = matrix1.matrix[i][j];
                        B21[i - order][j] = matrix2.matrix[i][j];
                    } else if (i < order && j >= order) {
                        A12[i][j - order] = matrix1.matrix[i][j];
                        B12[i][j - order] = matrix2.matrix[i][j];
                    } else {
                        A22[i - order][j - order] = matrix1.matrix[i][j];
                        B22[i - order][j - order] = matrix2.matrix[i][j];
                    }
                }
            }

            M1 = (A11 + A22) * (B11 + B22);
            M2 = (A21 + A22) * B11;
            M3 = A11 * (B12 - B22);
            M4 = A22 * (B21 - B11);
            M5 = (A11 + A12) * B22;
            M6 = (A21 - A11) * (B11 + B12);
            M7 = (A12 - A22) * (B21 + B22);

            C11 = M1 + M4 - M5 + M7;
            C21 = M2 + M4;
            C12 = M3 + M5;
            C22 = M1 - M2 + M3 + M6;

            Matrix mul(2 * order, 2 * order, 0);
            
            for (int i = 0; i < matrix1.rows; ++i) 
			{
                for (int j = 0; j < matrix1.cols; ++j) 
				{
                    if (i < order && j < order) {
                        mul[i][j] = C11[i][j];
                    } else if (i >= order && j < order) {
                        mul[i][j] = C21[i - order][j];
                    } else if (i < order && j >= order) {
                        mul[i][j] = C12[i][j - order];
                    } else {
                        mul[i][j] = C22[i - order][j - order];
                    }
                }
            }

            return mul;
        }

                public:
        Matrix(int rows, int cols) {
            Matrix(rows, cols, 0);
        }

        Matrix(int order) {
            Matrix(order, order, 0);
        }

        Matrix(vector<vector<int>> mat) {
            this -> rows = mat.size();
            this -> cols = mat[0].size();
            this -> matrix = mat;
        }

        Matrix(int rows, int cols, T vals): rows(rows), cols(cols) {
            vector<vector<T>> temp(rows, vector<T>(cols, vals));
            this -> matrix = temp;
        }

        Matrix(const Matrix& matrix) {
            this -> rows = matrix.rows;
            this -> cols = matrix.cols;
            this -> matrix = matrix.matrix;
        }

        int row() const {
            return this -> rows;
        }

        int column() const {
            return this -> cols;
        }

        vector<T>& operator[] (int row) {
            if (row < 0) row = this -> rows + row;
            if (row >= this -> rows || row < 0) {
                throw invalid_argument("Row is out of index");
            }

            return this -> matrix[row];
        }

        Matrix operator* (const Matrix& matrix) {
            if (this -> cols != matrix.rows) {
                throw invalid_argument("Matrixs are not multipliable");
            }

            int order = matrix.rows;
            bool strassen = (matrix.rows == matrix.cols);

            // if its not able to multipliable by strassens do it by traditional way
            if (!strassen) {
                Matrix mul(this -> rows, matrix.cols, 0);
        
                for (int i = 0; i < this -> rows; ++i) {
                    for (int j = 0; j < matrix.cols; ++j) {
                        for (int k = 0; k < matrix.rows; ++j) {
                            mul[i][j] += this -> matrix[i][k] * matrix.matrix[k][j];
                        }
                    }
                }

                return mul;
            }

            return multiply(*(this), matrix);
        }

        Matrix operator+ (const Matrix& matrix) {
            if (this -> rows != matrix.rows || this -> cols != matrix.cols) {
                throw invalid_argument("Incompatible matrix");
            }

            Matrix sum(this -> rows, this -> cols, 0);

            for (int i = 0; i < this -> rows; ++i) {
                for (int j = 0; j < this -> cols; ++j) {
                    sum[i][j] = matrix.matrix[i][j] + this -> matrix[i][j];
                }
            }

            return sum;
        }

        Matrix operator- (const Matrix& matrix) {
            if (this -> rows != matrix.rows || this -> cols != matrix.cols) {
                throw invalid_argument("Incompatible matrix");
            }

            Matrix sub(this -> rows, this -> cols, 0);

            for (int i = 0; i < this -> rows; ++i) {
                for (int j = 0; j < this -> cols; ++j) {
                    sub[i][j] = (this -> matrix[i][j]) - matrix.matrix[i][j];
                }
            }

            return sub;
        }

        string print() const {
            string s = "\n";

            for (auto& row: this -> matrix) {
                s += "   [ ";
                for (auto& element: row) {
                    s += to_string(element) + ", ";
                }

                s += "\b\b ],\n";
            }

            s += "\n";
            return s;
        };

};

int main() 
{
    system("cls");
    Matrix<int> matrix1({
        {5, 8, 21, 10},
        {9, 12, 64, 4},
        {41, 32, 1, 78},
        {0, 34, 9, 55},
    });

    Matrix<int> matrix2({
        {72, 32, 8, 98},
        {3, 0, 20, 11},
        {7, 23, 54, 3},
        {43, 5, 61, 9},
    });

    double startTime = getTimeinMicroSeconds();
    Matrix<int> matrix = matrix1 * matrix2; 
    double endTime = getTimeinMicroSeconds();
    
    double timeTaken = endTime - startTime;
    double machineConstant = timeTaken/pow(4,2.8);
    cout<<"Time taken: "<< timeTaken <<" microseconds"<<endl;
    cout<<"Machine constant: "<< machineConstant <<"\n\n\n";
    
    cout << " Matrix1: ";
    cout << matrix1.print() << endl;
    cout << endl;

    cout << " Matrix2: ";
    cout << matrix2.print() << endl;
    cout << endl;
    
    cout << " Matrix1 X Matrix2: "; 
    cout << matrix.print() << endl;
}