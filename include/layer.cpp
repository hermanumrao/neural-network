#include "layer.h"
#include "neuron.h"
#include <iostream>

inp_layer::inp_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created" << std::endl;
}
