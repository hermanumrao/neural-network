#ifndef NEURON_H
#define NEURON_H
#include <vector>

struct wt_ptr {
  double weight;
  std::vector<int> dest;
};

class neuron {
public:
  neuron();
  neuron(double val);
  neuron(double val, std::vector<double> w_val,
         std::vector<std::vector<int>> w_dest);
  void set_value(double inp);
  void set_act_val(double res);
  void set_weights(std::vector<double> w_val,
                   std::vector<std::vector<int>> w_dest);
  double get_value();

private:
  double value;
  std::vector<wt_ptr> weights;
  double act_val;
};

#endif // !NEURON_H
