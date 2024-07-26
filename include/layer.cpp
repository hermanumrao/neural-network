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
  for (unsigned int i = 0; i < neurons.size(); i++) {
    neurons[i].set_act_val(func(neurons[i].get_value()));
  }
}
void hid_layer::set_weights(std::vector<std::vector<double>> w_val,
                            std::vector<std::vector<int>> w_dest) {
  if (w_val.size() != w_dest.size())
    std::cerr << "error encountered while setting weights in input layer";
  for (unsigned int i = 0; i < w_val.size(); i++) {
    neurons[i].set_wts(w_val[i], {w_dest[i]});
  }
}
std::vector<double> hid_layer::get_act_vals() {
  std::vector<double> acts;
  for (auto neuron : neurons) {
    acts.push_back(neuron.get_act_val());
  }
  return acts;
}
std::vector<std::vector<double>> hid_layer::get_weights() {
  std::vector<std::vector<double>> wts;
  for (auto neuron : neurons) {
    wts.push_back(neuron.get_wts());
  }
  return wts;
}

out_layer::out_layer(int size, double init_val) {
  for (int i = -0; i < size; i++)
    neurons.push_back(neuron(init_val));
  std::cout << "new layer has been created(output)" << std::endl;
}
void out_layer::set_val(std::vector<double> vals) {
  for (unsigned int i = 0; i < vals.size(); i++) {
    neurons[i].set_value(vals[i]);
  }
}
void out_layer::activate_layer(double (*func)(double)) {
  for (unsigned int i = 0; i < neurons.size(); i++) {
    neurons[i].set_act_val(func(neurons[i].get_value()));
  }
}
std::vector<double> out_layer::get_act_vals() {
  std::vector<double> acts;
  for (auto neuron : neurons) {
    acts.push_back(neuron.get_act_val());
  }
  return acts;
}
