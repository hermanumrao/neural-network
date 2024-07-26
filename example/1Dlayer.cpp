#include "../include/layer.h"

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int EPOCH_NUM = 1;

float LR = 0.1;

vector<double> fprop(vector<double> values, vector<vector<double>> wts) {
  vector<double> ret;
  for (unsigned int i = 0; i < values.size(); i++) {
    double n_val = 0.0;
    for (unsigned int j = 0; j < wts[i].size(); j++) {
      // cout << wts[j][i] << '*' << values[j] << endl;
      n_val += wts[j][i] * values[j];
    }
    ret.push_back(n_val);
  }
  return ret;
}

double incrementor(double a) { return a + 1.0; }

int main() {
  inp_layer i_lay(1, 1);
  hid_layer h_lay(1, 0.5);
  out_layer o_lay(1, 0.5);
  i_lay.set_weights({{0.5}}, {{1}});
  h_lay.set_weights({{3.0}}, {{1}});

  // vector<vector<double>> data = {
  //     {1.0, 1.0}, {1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0}};
  // vector<double> labels = {0.0, 1.0, 1.0, 0.0};
  //
  vector<double> data = {1.0, 0.0};
  vector<double> labels = {1.0, 0.0};

  int tmp = 0;
  for (int epoch = 0; epoch < EPOCH_NUM; epoch++) {
    double inp1 = data[tmp];
    // forward propagation
    i_lay.set_inputs({inp1});
    h_lay.set_val(fprop(i_lay.get_vals(), i_lay.get_weights()));
    h_lay.activate_layer(incrementor);
    o_lay.set_val(fprop(h_lay.get_act_vals(), h_lay.get_weights()));
    o_lay.activate_layer(incrementor);
    if (epoch % ((int)floor(epoch / 10) + 1) == 0) {
      cout << "Currently on epoch [" << epoch << "/" << EPOCH_NUM
           << "] loss= " << 1 << " LR= " << LR << endl;
    }
    for (auto i : o_lay.get_act_vals())
      cout << i;
  }

  return 0;
}
