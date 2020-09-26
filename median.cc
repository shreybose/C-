// Copyright 2020 Shreya Bose

#include <inc/statistic.h>
#include <inc/median.h>
#include <algorithm>

namespace csce240 {

Median::Median() : std::vector<double>() { /*empty*/ }

void Median::Collect(double num) {
  vector_.push_back(num);
}

double Median::Calculate() const {
  std::vector<double> data;
  for (size_t i = 0; i < vector_.size(); i++)
    data.push_back(vector_[i]);

  int size = data.size();
  double median = 0.0;
  sort(data.begin(), data.end());
  if (size % 2 == 0) {
    median = data[(size/2) - 1] + data[size/2];
    median /= 2;
  } else {
      median = data[size/2];
  }
  return median;
}

}  // namespace csce240
