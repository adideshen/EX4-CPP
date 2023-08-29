//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4

/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit {
	unsigned int value;
	float probability;
} digit;

const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
									{64,  128},
									{20,  64},
									{10,  20}};
const matrix_dims bias_dims[] = {{128, 1},
								 {64,  1},
								 {20,  1},
								 {10,  1}};

class MlpNetwork
{
 public:
  // constructor
  /**
   * Construct Mlpnetwork.
   * @param w array of weights matrices.
   * @param b array of biases matrices.
   */
  MlpNetwork (Matrix* w, Matrix* b);

  // operators
  /**
   * Applies the entire network on input.
   * @param x input matrix.
   * @return digit struct that holds the guessed number and the probability.
   */
  digit operator() (const Matrix& x);

 private:
  Matrix* _weights;
  Matrix* _bias;
};

#endif // MLPNETWORK_H