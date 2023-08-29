// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <ostream>
/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
	int rows, cols;
} matrix_dims;

class Matrix
{
 public:
  //constructors and destructor
  /**
   * Default constructor, construct matrix of size 1x1 with element 0.
   */
  Matrix ();

  /**
   * Construct matrix of size rows*cols with elements 0.
   * @param rows num of rows.
   * @param cols num of columns.
   */
  Matrix (int rows, int cols);

  /**
   * Copy constructor, constructs matrix from another Matrix m.
   * @param m
   */
  Matrix (const Matrix &m);

  /**
   * Destructor.
   */
  ~Matrix ();

  //getters
  /**
   * @return the amount of rows as int.
   */
  int get_rows () const;

  /**
   * @return the amount of cols as int
   */
  int get_cols () const;

  //functions
  /**
   * Transforms a matrix into its transpose matrix
   * @return the transposed matrix.
   */
  Matrix transpose ();

  /**
   * Transforms a matrix into a column vector.
   * @return the vector.
   */
  Matrix vectorize ();

  /**
   * Prints matrix's elements.
   */
  void plain_print() const;

  /**
   * Returns a matrix which is the elementwise
   * multiplication(Hadamard product) of this matrix and
   * another matrix m
   * @param m
   * @return
   */
  Matrix dot (Matrix& m);

  /**
   * @return the Frobenius norm of the given matrix.
   */
  float norm ();

  //operators
  /**
   * Matrix addition
   */
  Matrix operator+ (const Matrix& b);

  /**
   * Assignment operator
   */
  Matrix& operator= (const Matrix& b);

  /**
   * Matrix multiplication
   */
  Matrix operator* (const Matrix& b);

  /**
   * Scalar multiplication on the right
   * @param c scalar
   * @return the multiplied matrix.
   */
  Matrix operator* (float c);

  /**
   * Scalar multiplication on the left
   * @param c scalar
   * @param a matrix
   * @return the multiplied matrix.
   */
  friend Matrix operator* (float c, const Matrix& a);

  /**
   * Matrix addition accumulation
   */
  Matrix operator+= (const Matrix& b);

  /**
   * Parenthesis indexing. will return the i,j element in the matrix.
   */
  float operator() (int i, int j) const;

  /**
   * Parenthesis indexing, will return the i,j element in the matrix.
   */
  float& operator() (int i, int j);

  /**
   * Brackets indexing, will return the i'th element
   */
  float operator[] (int i) const;

  /**
 * Brackets indexing, will return the i'th element.
 */
  float& operator[] (int i);

  /**
   * Output stream, pretty export of matrix as per section.
   */
  friend std::ostream& operator<< (std::ostream& s, const Matrix& a);

  /**
   * Input stream, Fills matrix elements: has to read input stream fully,
   * otherwise it's throw an error.
   */
  friend std::istream& operator>> (std::istream& s, Matrix& a);

 private:
  int _rows;
  int _cols;
  float* _matrix;
};

#endif //MATRIX_H