#include "../include/layer.h"

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int EPOCH_NUM = 1;

float LR = 0.1;

std::vector<double> fprop(const std::vector<double> &vec,
                          const std::vector<std::vector<double>> &mat) {
  if (vec.size() != mat.size()) {
    throw std::invalid_argument(
        "Vector length must equal the number of rows in the matrix");
  }

  std::vector<double> result(mat[0].size(), 0.0);

  for (size_t j = 0; j < mat[0].size(); ++j) {
    for (size_t i = 0; i < vec.size(); ++i) {
      result[j] += vec[i] * mat[i][j];
    }
  }

  return result;
}
double incrementor(double a) { return a + 1.0; }

int main() {
  inp_layer i_lay(2, 1);
  hid_layer h_lay(2, 0.5);
  out_layer o_lay(1, 0.5);
  i_lay.set_weights({{0.5, -0.5}, {0.5, -0.5}}, {{1, 2}, {1, 2}});
  h_lay.set_weights({{0.2, 0.3}}, {{1, 2}});

  vector<vector<double>> data = {
      {1.0, 1.0}, {1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0}};
  vector<double> labels = {0.0, 1.0, 1.0, 0.0};

  int tmp = 0;
  for (int epoch = 0; epoch < EPOCH_NUM; epoch++) {
    vector<double> inp1 = data[tmp];
    // forward propagation
    i_lay.set_inputs(inp1);
    h_lay.set_val(fprop(i_lay.get_vals(), i_lay.get_weights(2)));
    h_lay.activate_layer(incrementor);
    o_lay.set_val(fprop(h_lay.get_act_vals(), h_lay.get_weights(1)));
    o_lay.activate_layer(incrementor);
    if (epoch % ((int)floor(epoch / 10) + 1) == 0) {
      cout << "Currently on epoch [" << epoch << "/" << EPOCH_NUM
           << "] loss= " << 1 << " LR= " << LR << endl;
    }
    cout << "--end--" << endl;
    for (auto i : o_lay.get_act_vals())
      cout << i;
  }

  return 0;
}
