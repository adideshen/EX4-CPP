#include "MlpNetwork.h"


MlpNetwork::MlpNetwork (Matrix* w, Matrix* b)
{
  _weights = w;
  _bias = b;
}

digit MlpNetwork::operator() (const Matrix& x)
{
  Dense dense1(_weights[0], _bias[0], activation::relu);
  Dense dense2(_weights[1], _bias[1], activation::relu);
  Dense dense3(_weights[2], _bias[2], activation::relu);
  Dense dense4(_weights[3], _bias[3], activation::softmax);
  Matrix r1 = dense1(x);
  Matrix r2 = dense2(r1);
  Matrix r3 = dense3(r2);
  Matrix r4 = dense4(r3);
  digit res = {0, 0};
  for (int i = 0; i < (r4.get_rows() * r4.get_cols()) ; i++)
  {
    if (res.probability < r4[i])
    {
      res.value = i;
      res.probability = r4[i];
    }
  }
  return res;
}