#include "tools.h"

void v_print(vector<double> v) {
  cout << '{';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << '}' << endl;
}
void vv_print(vector<vector<double>> vv) {
  cout << '{';
  for (int i = 0; i < vv.size(); i++) {
    v_print(vv[i]);
  }
  cout << '}' << endl;
}
void v_print(vector<int> v) {
  cout << '{';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << '}' << endl;
}
