#include "Matrix.h"
#include <stdexcept>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#define DUPLICATE_ERROR "It's not possible to multiply 2 matrix with \
different sizes."
#define SUM_ERROR "It is not possible to sum 2 matrices with different sizes"
#define NEGATIVE_COLS_ROWS "It's not possible to initialize a matrix with 0 \
or negative number of rows and/or columns."
#define ACCESS_ERROR "There is no cell at this location in the matrix."
#define FILE_BIGGER_THAN_MAT "The matrix is larger than the image in the file."
#define STAR_PRINT 0.1

Matrix::Matrix (int rows, int cols) : _rows (rows), _cols(cols)
{
  if ((rows < 1) || (cols < 1))
  {
    throw std::length_error(NEGATIVE_COLS_ROWS);
  }
  _matrix = new float [rows * cols];
  for (int i = 0; i < (rows * cols); i++)
  {
    (*this)[i] = 0;
  }
}

Matrix::Matrix () : Matrix(1, 1) {}

Matrix::Matrix (const Matrix &m) : _rows(m._rows), _cols(m._cols)
{
  _matrix = new float [_rows * _cols];
  for (int i = 0; i < (_rows * _cols); i++)
  {
    (*this)[i] = m[i];
  }
}

Matrix::~Matrix ()
{
  delete[] _matrix;
}

int Matrix::get_rows () const
{
  return _rows;
}

int Matrix::get_cols () const
{
  return _cols;
}

Matrix Matrix::transpose()
{
  auto* new_mat = new float [_rows * _cols];
  int new_rows = _cols;
  int new_cols = _rows;
  for (int i = 0; i < _rows; i++)
  {
    for (int j = 0; j < _cols; j++)
    {
      int old_index = (i * _cols) + j;
      int new_index = (j * _rows) + i;
      new_mat[new_index] = _matrix[old_index];
    }
  }
  delete[] _matrix;
  _matrix = new_mat;
  _rows = new_rows;
  _cols = new_cols;
  return (*this);
}

Matrix Matrix::vectorize ()
{
  _rows = _rows * _cols;
  _cols = 1;
  return (*this);
}

void Matrix::plain_print () const
{
  for (int i = 0; i < (_rows * _cols); i++)
  {
    cout << (*this)[i];
    if (((i + 1) % _cols) == 0)
    {
      cout << endl;
    }
  }
}

Matrix Matrix::dot (Matrix &m)
{
  if ((_rows != m._rows) || (_cols != m._cols))
  {
    throw std::length_error(DUPLICATE_ERROR);
  }
  for (int i = 0; i < (_rows * _cols); i++)
  {
    (*this)[i] *= m[i];
  }
  return (*this);
}

float Matrix::norm ()
{
  float sum = 0;
  for (int i = 0; i < (_rows * _cols); i++)
  {
    sum += powf((*this)[i], 2);
  }
  return sqrtf (sum);
}

Matrix Matrix::operator+ (const Matrix& b)
{
  Matrix c = Matrix(_rows, _cols);
  if ((_rows != b._rows) || (_cols != b._cols))
  {
    throw std::length_error(SUM_ERROR);
  }
  for (int i = 0; i < (_rows * _cols); i++)
  {
    c[i] = (*this)[i] + b[i];
  }
  return c;
}


Matrix& Matrix::operator= (const Matrix& b)
{
  if (this != &b)
  {
      _rows = b._rows;
      _cols = b._cols;
      delete[] _matrix;
      _matrix = new float [_rows * _cols];
      for (int i = 0; i < (_rows * _cols); i++)
      {
        (*this)[i] = b[i];
      }
    }
  return (*this);
}

Matrix Matrix::operator* (const Matrix& b)
{
  Matrix c(_rows, b._cols);
  if (_cols != b._rows)
  {
    throw std::length_error(DUPLICATE_ERROR);
  }
  for (int i = 0; i < _rows; i++)
  {
    for (int j = 0; j < b._cols; j++)
    {
      c(i,j) = 0;
      for (int k = 0; k < _cols; k++)
      {
        c(i, j) += (*this)(i,k) * b(k, j);
      }
    }
  }
  return c;
}

Matrix Matrix::operator* (float c)
{
  Matrix c_mat = *this;
  for (int i = 0; i < (_rows * _cols); i++)
  {
    c_mat[i] = c * (*this)[i];
  }
  return c_mat;
}

Matrix operator* (float c, const Matrix& a)
{
  Matrix c_mat = a;
  for (int i = 0; i < (a._rows * a._cols); i++)
  {
    c_mat[i] = c * a[i];
  }
  return c_mat;
}

Matrix Matrix::operator+= (const Matrix &b)
{
  if ((_rows != b._rows) || (_cols != b._cols))
  {
    throw std::length_error(SUM_ERROR);
  }
  for (int i = 0; i < (_rows * _cols); i++)
  {
    (*this)[i] += b[i];
  }
  return (*this);
}

float Matrix::operator() (int i, int j) const
{
  if ((i >= _rows) || (i < 0) || (j >= _cols) || (j < 0))
  {
    throw std::out_of_range (ACCESS_ERROR);
  }
  int index = (i) * _cols + (j);
  return _matrix[index];
}

float& Matrix::operator() (int i, int j)
{
  if ((i >= _rows) || (i < 0) || (j >= _cols) || (j < 0))
  {
    throw std::out_of_range (ACCESS_ERROR);
  }
  int index = (i) * _cols + (j);
  return _matrix[index];
}

float Matrix::operator[] (int i) const
{
  if ((i >= (_rows * _cols)) || (i < 0))
  {
    throw std::out_of_range (ACCESS_ERROR);
  }
  return _matrix[i];
}

float& Matrix::operator[] (int i)
{
  if ((i >= (_rows * _cols)) || (i < 0))
  {
    throw std::out_of_range (ACCESS_ERROR);
  }
  return _matrix[i];
}

std::ostream& operator<< (std::ostream& s, const Matrix& a)
{
  for (int i = 0; i < (a.get_cols() * a.get_rows()); i++)
  {
    if (a[i] > STAR_PRINT)
    {
      s << "**";
    }
    else
    {
      s << "  ";
    }
    if (((i+1) % a.get_cols()) == 0)
    {
      s << endl;
    }
  }
  return s;
}

std::istream& operator>> (std::istream& s, Matrix& a)
{
  long int matrix_size = (a.get_cols() * a.get_rows()) * sizeof (float);
  s.seekg (0, std::ios_base::end);
  long int file_size = s.tellg();
  s.seekg (0, std::ios_base::beg);
  if (file_size < matrix_size)
  {
    throw std::runtime_error (FILE_BIGGER_THAN_MAT);
  }
  char *temp = (char *)a._matrix;
  s.read (temp, matrix_size);
  return s;
}

