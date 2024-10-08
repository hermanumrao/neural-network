#ifndef NEURON_H
#define NEURON_H
#include <vector>

struct wt_ptr {
  double weight;
  int dest;
};

class neuron {
public:
  neuron();
  neuron(double val);
  neuron(double val, std::vector<double> w_val, std::vector<int> w_dest);
  void set_value(double inp);
  void set_act_val(double res);
  void set_wts(std::vector<double> w_val, std::vector<int> w_dest);
  double get_value();
  double get_act_val();
  std::vector<wt_ptr> get_wts();

private:
  double value;
  std::vector<wt_ptr> weights;
  double act_val;
};

#endif // !NEURON_H
