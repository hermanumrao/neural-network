#include "neuron.h"
#include "tools.h"
#include <iostream>
#include <vector>

neuron::neuron() : value(0.0), act_val(0.0) {}
neuron::neuron(double val) : value(val), act_val(0.0) {}
neuron::neuron(double val, std::vector<double> w_val, std::vector<int> w_dest) {
  set_value(val);
  set_wts(w_val, w_dest);
}

void neuron::set_value(double inp) { value = inp; }
void neuron::set_act_val(double res) { act_val = res; }

void neuron::set_wts(std::vector<double> w_val, std::vector<int> w_dest) {
  if (w_val.size() != w_dest.size())
    std::cerr
        << "weigth vector length and length of destination vector are unequal";
  for (unsigned int i = 0; i < w_val.size(); i++) {
    wt_ptr wtg;
    wtg.weight = w_val[i];
    wtg.dest = w_dest[i];
    weights.push_back(wtg);
  }
}

double neuron::get_value() { return value; }
double neuron::get_act_val() { return act_val; }

std::vector<wt_ptr> neuron::get_wts() { return weights; }
