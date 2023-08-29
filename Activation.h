#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

typedef Matrix (*func_a)(Matrix);

/**
 * This namespace include 2 activation function.
 */
namespace activation
{
  Matrix relu (Matrix m);
  Matrix softmax (Matrix m);
}

#endif //ACTIVATION_H