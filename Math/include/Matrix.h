#pragma once
#include "C:\Users\Abdullah\Desktop\Fall 21\ELCT 350\cpp-files\Final Projet\C++\Common\include\Exceptions\NotImplementedException.h"
#include "Vector.h"


/*
        | a11 a12 a13 |
 M =    | a21 a22 a23 |
        | a31 a32 a33 | 


  Matrix M = [  [a11,a12,a13], [a21,a22,a23] , [ a31,a32,a33]   ]
            ^ Outer arraye  = specifies  which row  
            ^ Inner array   = specifies  which column

            _numRows= size of outer array  
            _numCols= size of inner array 
*/
namespace ELCT350
{
    namespace Math
    {
        template<typename T>
        class Matrix final
        {
        public:
#pragma region Constructors and Destructors
            Matrix(size_t numRows, size_t numColumns, const T& initialValue = T{})
                : _numRows(0), _numCols(0), _data(nullptr)
            {
                resize(numRows, numColumns);
                initialize(initialValue);

            }

            Matrix(const Matrix<T>& original) :_numRows(0), _numCols(0), _data(nullptr)
            {
                *this = original;
            }

            Matrix(Matrix<T>&& old)
                : _numRows(old._numRows), _numCols(old._numCols), _data(old._data)
            {
                old._numRows = 0;
                old._numCols = 0;
                old._data = nullptr;

            }

            ~Matrix()
            {
                dispose();

            }
#pragma endregion

#pragma region Observers

            void setElement(size_t row, size_t col, T something) {
                _data[row][col] = something;
            }
            T getElement(size_t row, size_t col, T something) {
                return _data[row][col];
            }

            size_t getNumberOfRows() const
            {
                return _numRows;
                // throw Common::NotImplementedException();
            }

            size_t getNumberOfColumns() const
            {
                return _numCols;
                // throw Common::NotImplementedException();
            }

            Vector<T> getRow(size_t rowIndex) const
            {
                // check if the index is in range first 
                if (rowIndex >= _numRows)
                    throw std::out_of_range("index is out of range");

                Vector<T> result(_numCols, NULL);


                for (size_t i = 0; i < result.size(); ++i)
                    result[i] = (_data[rowIndex][i]);
                return result;
                //  throw Common::NotImplementedException();
            }

            Vector<T> getColumn(size_t columnIndex) const
            {
                if (columnIndex >= _numCols)
                    throw std::out_of_range("index is out of range");

                Vector<T> result(_numRows, NULL);
                for (size_t i = 0; i < result.size(); ++i)
                    result[i] = (_data[i][columnIndex]);
                return result;

                // throw Common::NotImplementedException();
            }

            Matrix<T> computeInverse() const
            {
                auto rows = getNumberOfRows();
                if (rows != getNumberOfColumns())
                    throw std::logic_error("Must be a square matrix");

                auto tmpColumns = 2 * rows;
                Matrix<T> tmp(rows, tmpColumns);
                for (size_t row = 0; row < rows; ++row)
                {
                    for (size_t column = 0; column < rows; ++column)
                        tmp(row, column) = (*this)(row, column);
                    tmp(row, row + rows) = 1;
                }

                auto pivot = [&tmp, &rows, &tmpColumns]()
                {
                    for (size_t row = 0, lead = 0; row < rows && lead < tmpColumns; ++row, ++lead)
                    {
                        size_t i = row;
                        while (tmp(i, lead) == T{})
                        {
                            if (++i == rows)
                            {
                                i = row;
                                if (++lead == tmpColumns)
                                    return;
                            }
                        }

                        for (size_t column = 0; column < tmpColumns; ++column)
                            std::swap(tmp(i, column), tmp(row, column));

                        if (tmp(row, lead) != T{})
                        {
                            T f = tmp(row, lead);
                            for (size_t column = 0; column < tmpColumns; ++column)
                                tmp(row, column) /= f;
                        }

                        for (size_t j = 0; j < rows; ++j)
                        {
                            if (j == row)
                                continue;
                            T f = tmp(j, lead);
                            for (size_t column = 0; column < tmpColumns; ++column)
                                tmp(j, column) -= f * tmp(row, column);
                        }
                    }
                };

                pivot();
                Matrix<T> inv(rows, rows);
                for (size_t row = 0; row < rows; ++row)
                {
                    for (size_t column = 0; column < rows; ++column)
                        inv(row, column) = tmp(row, column + rows);
                }
                return inv;
            }
#pragma endregion

#pragma region Operators
#pragma region Observers
            const T& operator()(size_t row, size_t column) const
            {
                return _data[row][column];
                //   throw Common::NotImplementedException();
            }

            Matrix<T> operator-() const
            {
                Matrix<T> negated;
                negated.resize(_numRows, _numCols);
                for (size_t i = 0; i < _numRows; ++i) {
                    for (size_t j = 0; j < _numCols; ++j) {
                        negated[i][j] = -_data[i][j];
                    }

                }

                return negated;
                // throw Common::NotImplementedException();
            }
            Matrix<T> operator-(const Matrix<T>& rhs) const
            {

                checkMatchedSize(rhs);
                Matrix<T> sum(*this);
                sum -= rhs;
                //  cout << sum.getRow(1) << endl;
                return sum;
                //throw Common::NotImplementedException();
            }
            Matrix<T>& operator-=(const Matrix<T>& rhs)
            {

                for (size_t i = 0; i < _numRows; ++i)
                    for (size_t j = 0; j < _numCols; ++j) {
                        _data[i][j] -= rhs(i, j);
                    }
                return *this;
            }
            Matrix<T> operator+(const Matrix<T>& rhs) const
            {
                checkMatchedSize(rhs);
                Matrix<T> sum(*this);
                sum += rhs;
                //  cout << sum.getRow(1) << endl;
                return sum;
                //hrow Common::NotImplementedException();
            }
            Matrix<T>& operator+=(const Matrix<T>& rhs)
            {

                for (size_t i = 0; i < _numRows; ++i)
                    for (size_t j = 0; j < _numCols; ++j) {
                        _data[i][j] += rhs(i, j);
                    }
                return *this;
            }
            void push_M(T& something) {
               
            }

            // two matrices 
            // 
         Matrix<T> operator*(const Matrix<T>& rhs) const
            {
             T sum = T{};
             if (_numCols != rhs._numRows)
                 throw std::logic_error("Size issue");
             Matrix<T> ret(_numRows,rhs._numCols,0); 
             for (size_t i = 0; i < ret._numRows; ++i) {
                 for (size_t j = 0; j < ret._numCols; ++j) {
                     // sum = sum + (_data[i][j]*rhs(j, i));
                     //ret.setElement(i, j, sum);'
                     Vector<T> slicedRow = this->getRow(i);
                     Vector<T> slicedCol = rhs.getColumn(j); 
                     sum = slicedRow.dotProduct(slicedCol);
                     ret(i,j) = sum;
                 }
             }
             return ret;
                // throw Common::NotImplementedException();
            }
         // fsfds sss
                // matrix and a vector 
            Vector<T> operator*(const Vector<T>& rhs) const
            {

                if (_numRows != rhs.size())
                    throw std::logic_error("Size issue");
                Vector<T> ret(rhs.size()); 
                for(size_t i=0; i<_numRows; ++i)
                    for (size_t j = 0; j < _numCols; ++j) {
                        Vector<T> slicedCol = this->getColumn(j);
                        ret[i] = rhs.dotProduct(slicedCol);
                    }
                return ret;
                // throw Common::NotImplementedException();
            }
            
            Matrix<T> operator*(const T& scalar) const
            {
                Matrix<T> product(*this);
                product *= scalar;

                return product;
                // throw Common::NotImplementedException();
            }

            Matrix<T>& operator*=(const T& scalar)
            {

                for (size_t i = 0; i < _numRows; ++i) {
                    for (size_t j = 0; j < _numCols; ++j) {
                        _data[i][j] *= scalar;
                    }
                }

                return *this;
                //throw Common::NotImplementedException();
            }

#pragma endregion

#pragma region Modifiers

            T& operator()(size_t row, size_t column)
            {
                return const_cast<T&>(const_cast<const Matrix<T>*>(this)->operator()(row, column));
            }



            Matrix<T>& operator=(const Matrix<T>& rhs)
            {
                if (_numRows != rhs._numRows || _numCols != rhs._numCols)
                {
                    //  cout << "HHH" << endl;
                    dispose();
                    resize(rhs._numRows, rhs._numCols);
                }

                for (size_t i = 0; i < rhs._numRows; ++i) {
                    for (size_t j = 0; j < rhs._numCols; ++j) {
                        _data[i][j] = rhs(i, j);
                    }
                }
                return *this;
                // throw Common::NotImplementedException();
            }



            Matrix<T>& operator=(Matrix<T>&& old)
            {

                dispose();
                _numRows = old._numRows;
                _numCols = old._numCols;
                _data = old._data;

                old._numRows = 0;
                old._numCols = 0;
                old._data = nullptr;
                return *this;
                //   throw Common::NotImplementedException();
            }



            bool operator==(const Matrix<T>& rhs) const
            {
                if (_numRows != rhs._numRows || _numCols != rhs._numCols)
                    return false;

                for (size_t i = 0; i < _numRows; ++i) {
                    for (size_t j = 0; j < _numCols; ++j) {
                        if (_data[i][j] != rhs(i, j))
                            return false;
                    }
                }
                return true;
                // throw Common::NotImplementedException();
            }

            bool operator!=(const Matrix<T>& rhs) const
            {
                return !(*this == rhs);
                // throw Common::NotImplementedException();
            }
            Matrix<T> operator/(const T& scalar) const
            {
                Matrix<T> quotient(*this);
                quotient /= scalar;

                return quotient;
                //    throw Common::NotImplementedException();
            }

            Matrix<T>& operator/=(const T& scalar)
            {
                for (size_t i = 0; i < _numRows; ++i) {
                    for (size_t j = 0; j < _numCols; ++j) {
                        _data[i][j] /= scalar;
                    }
                }
                return *this;
                //  throw Common::NotImplementedException();
            }

            void resize(size_t numRows, size_t numCols)
            {
                _numRows = numRows;
                _numCols = numCols;
                _data = new T * [_numRows];
                for (size_t i = 0; i < _numRows; ++i) {
                    //  _data[i] = new T * [_numCols];
                    _data[i] = new T[_numCols];
                }
            }

            void dispose()
            {
                if (_data)
                {
                    delete[] _data;
                    _data = nullptr;
                    _numRows = 0;
                    _numCols = 0;
                }
            }
            void initialize(const T& initialValue)
            {
                _data = new T * [_numRows]; // _data points to first elemnt of rows array 
                                            // rows array is an array of pointers, pointing to 
                                            // first index of each row of the matrix
                for (size_t i = 0; i < _numRows; ++i) {
                    //  _data[i] = new T * [_numCols];
                    _data[i] = new T[_numCols];
                }
                for (size_t k = 0; k < _numRows; ++k) {
                    for (size_t s = 0; s < _numCols; ++s) {
                        _data[k][s] = initialValue;
                    }
                }
            }
#pragma endregion
#pragma endregion

            void checkMatchedSize(const Matrix<T>& matrix) const
            {
                if (_numRows != matrix._numRows || _numCols != matrix._numCols)
                    throw std::domain_error("Matrix must have the same size");
            }
        private:
#pragma region vars
            size_t _numRows;
            size_t _numCols;
            T** _data;



#pragma endregion 
        };


#pragma region Operators



        template<typename T>
        std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
        {
            stream << "[ ";
            for (size_t i = 0; i < matrix.getNumberOfRows(); ++i)
                for (size_t j = 0; j < matrix.getNumberOfColumns(); ++j) {
                    stream << matrix[i][j] << ' ';
                }

            stream << ']';

            return stream;
        }
#pragma endregion
    }
}