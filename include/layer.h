#include "neuron.h"
#include <iostream>
#include <vector>

class inp_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  inp_layer(int size, double init_val);
  void activate_layer(double (*func)(double));
};
