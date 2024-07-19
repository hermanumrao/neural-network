#include "neuron.h"
#include <iostream>

neuron::neuron() : value(0.0), act_val(0.0) {}
neuron::neuron(double val) : value(val), act_val(0.0) {}
neuron::neuron(double val, std::vector<double> w_val,
               std::vector<std::vector<int>> w_dest) {
  set_value(val);
  set_weights(w_val, w_dest);
}

void neuron::set_value(double inp) { value = inp; }
void neuron::set_act_val(double res) { act_val = res; }

void neuron::set_weights(std::vector<double> w_val,
                         std::vector<std::vector<int>> w_dest) {
  if (w_val.size() != w_dest.size())
    std::cerr
        << "weigth vector length and length of destination vector are unequal";
  for (int i = 0; i < w_val.size(); i++) {
    wt_ptr wtg;
    wtg.weight = w_val[i];
    wtg.dest = w_dest[i];
    weights.push_back(wtg);
  }
}

double neuron::get_value() { return value; }
