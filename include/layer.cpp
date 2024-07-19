#include "layer.h"
#include "neuron.h"
#include <iostream>

inp_layer::inp_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created (Input)" << std::endl;
}

hid_layer::hid_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created(hidden)" << std::endl;
}

void hid_layer::activate_layer(double (*func)(double)) {
  for (auto neuron : neurons) {
    neuron.set_act_val(func(neuron.get_value()));
  }
  std::cout << "Layer has been activated" << std::endl;
}

out_layer::out_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created(output)" << std::endl;
}

void out_layer::activate_layer(double (*func)(double)) {
  for (auto neuron : neurons) {
    neuron.set_act_val(func(neuron.get_value()));
  }
  std::cout << "Layer has been activated" << std::endl;
}
