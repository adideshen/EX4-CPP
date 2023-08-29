#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

class Dense
{
 public:
  //constructor
  /**
   * Construct a dense.
   * @param w matrix of weights.
   * @param b matrix of bias.
   * @param a activation func.
   */
  Dense (const Matrix& w, const Matrix& b, func_a a);

  //getters
  /**
   * @return the weights of this layer.
   */
  Matrix get_weights () const;

  /**
   * @return the bias of this layer.
   */
  Matrix get_bias () const;

  /**
   * @return the activation function of this layer
   */
  func_a get_activation ();

  //operators
  /**
   * Applies the layer on input and returns output matrix.
   * @param x input matrix.
   * @return output matrix.
   */
  Matrix operator() (const Matrix& x) ;

 private:
  Matrix _weights;
  Matrix _bias;
  func_a _activation_func;
};

#endif //DENSE_H
