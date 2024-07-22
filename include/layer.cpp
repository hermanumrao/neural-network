#include "layer.h"
#include <iostream>
#include <vector>

inp_layer::inp_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created (Input)" << std::endl;
}
void inp_layer::set_inputs(std::vector<double> vals) {
  for (unsigned int i = 0; i < vals.size(); i++) {
    neurons[i].set_value(vals[i]);
  }
}
void inp_layer::set_weights(std::vector<std::vector<double>> w_val,
                            std::vector<std::vector<int>> w_dest) {
  if (w_val.size() != w_dest.size())
    std::cerr << "error encountered while setting weights in input layer";
  for (unsigned int i = 0; i < w_val.size(); i++) {
    neurons[i].set_wts(w_val[i], {w_dest[i]});
  }
}
std::vector<double> inp_layer::get_vals() {
  std::vector<double> vals;
  for (auto neuron : neurons) {
    vals.push_back(neuron.get_value());
  }
  return vals;
}

std::vector<std::vector<double>> inp_layer::get_weights() {
  std::vector<std::vector<double>> wts;
  for (auto neuron : neurons) {
    wts.push_back(neuron.get_wts());
  }
  return wts;
}

hid_layer::hid_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created(hidden)" << std::endl;
}
void hid_layer::set_val(std::vector<double> vals) {
  for (unsigned int i = 0; i < vals.size(); i++) {
    neurons[i].set_value(vals[i]);
  }
}
void hid_layer::activate_layer(double (*func)(double)) {
  for (auto neuron : neurons) {
    neuron.set_act_val(func(neuron.get_value()));
  }
  std::cout << "Layer has been activated" << std::endl;
}
void hid_layer::set_weights(std::vector<std::vector<double>> w_val,
                            std::vector<std::vector<int>> w_dest) {
  if (w_val.size() != w_dest.size())
    std::cerr << "error encountered while setting weights in input layer";
  for (unsigned int i = 0; i < w_val.size(); i++) {
    neurons[i].set_wts(w_val[i], {w_dest[i]});
  }
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
