// Copyright 2020 Shreya Bose

#include <inc/statistic.h>
#include <inc/mean.h>
#include <vector>

namespace csce240 {

Mean::Mean() : std::vector<double>() { /* empty */ }

void Mean::Collect(double num) {
  vector_.push_back(num);
}

double Mean::Calculate() const {
  if (vector_.size() == 0)
    return 0;
  double mean = 0.0;
  for ( size_t i = 0; i < vector_.size(); ++i ) {
    mean += vector_[i];
  }
  mean /= vector_.size();
  return mean;
}
}  // namespace csce240
