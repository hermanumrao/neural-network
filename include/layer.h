#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <iostream>
#include <vector>

class inp_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  inp_layer(int size, double init_val);
  void set_inputs(std::vector<double> vals);
  void set_weights(std::vector<std::vector<double>> w_val,
                   std::vector<std::vector<int>> w_dest);
  std::vector<double> get_vals();
  std::vector<std::vector<double>> get_weights();
};

class hid_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  hid_layer(int size, double init_val);
  void set_val(std::vector<double> vals);
  void activate_layer(double (*func)(double));
  void set_weights(std::vector<std::vector<double>> w_val,
                   std::vector<std::vector<int>> w_dest);
  std::vector<double> get_act_vals();
  std::vector<std::vector<double>> get_weights();
};

class out_layer : neuron {
private:
  std::vector<neuron> neurons;

public:
  out_layer(int size, double init_val);
  void set_val(std::vector<double> vals);
  void activate_layer(double (*func)(double));
  std::vector<double> get_act_vals();
};

#endif // !LAYER_H
