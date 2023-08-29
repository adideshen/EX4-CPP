#include "Activation.h"
#include <cmath>

Matrix activation::relu (Matrix m)
{
  Matrix new_mat (m.get_rows(), m.get_cols());
  for (int i = 0; i < (m.get_rows() * m.get_cols()); i++)
  {
    if (m[i] >= 0)
    {
      new_mat[i] = m[i];
    }
  }
  return new_mat;
}

Matrix activation::softmax (Matrix m)
{
  Matrix new_mat (m.get_rows(), m.get_cols());
  float sum = 0;
  for (int i = 0; i < (m.get_rows() * m.get_cols()); i++)
  {
    new_mat[i] = std::exp (m[i]);
    sum += std::exp (m[i]);
  }
  new_mat = (1 / sum) * new_mat;
  return new_mat;
}