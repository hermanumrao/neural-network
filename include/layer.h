#include "neuron.h"
#include <iostream>
#include <vector>

class inp_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  inp_layer(int size, double init_val);
};

class hid_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  hid_layer(int size, double init_val);
  void activate_layer(double (*func)(double));
};

class out_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  out_layer(int size, double init_val);
  void activate_layer(double (*func)(double));
};
