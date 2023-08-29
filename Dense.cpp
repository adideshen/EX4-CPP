#include "Dense.h"

Dense::Dense (const Matrix& w, const Matrix& b, func_a a) : _weights(w),
_bias(b), _activation_func(a) {}

Matrix Dense::get_weights () const
{
  return _weights;
}

Matrix Dense::get_bias () const
{
  return _bias;
}

func_a Dense::get_activation ()
{
  return _activation_func;
}

Matrix Dense::operator() (const Matrix& x)
{
  return (_activation_func ((_weights * x) + _bias));
}
