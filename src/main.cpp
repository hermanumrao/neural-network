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
    double n_val;
    for (unsigned int j = 0; j < wts[j].size(); j++) {
      n_val += wts[j][i] * values[j];
    }
    ret.push_back(n_val);
  }
  return ret;
}

int main() {
  inp_layer i_lay(1, 1);
  hid_layer h_lay(1, 0.5);
  out_layer o_lay(1, 0.5);
  i_lay.set_weights({{0.5}}, {{1}});
  h_lay.set_weights({{2.0}}, {{1}});

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
    cout << "entry to for loops" << endl;

    h_lay.set_val(fprop(i_lay.get_vals(), i_lay.get_weights()));
    i_lay.set_inputs({inp1});
    if (epoch % ((int)floor(epoch / 10))) {
      cout << "Currently on epoch [" << epoch << "/" << EPOCH_NUM
           << "] loss= " << 1 << " LR= " << 1;
    }
  }

  return 0;
}
