// Copyright 2020 Shreya Bose

#ifndef INC_MEDIAN_H_  // NO LINT
#define INC_MEDIAN_H_  // NO LINT


/* This child of the Statistic class should be a concrete class---that is, it
 * should implement both Collect and Calculate methods from the parent class
 * Statistic. I will let you decide how to implement those methods.
 * 
 * The Calculate method should return the median of data gathered by the Collect
 * method. You are free to implement both methods by any means you choose.
 */

#include <inc/statistic.h>
#include <vector>


namespace csce240 {

class Median : public std::vector<double>, public Statistic {
 public:
  Median();

  void Collect(double num);

  double Calculate() const;

 protected:
  std::vector<double> vector_;
};
}  // namespace csce240
#endif  // INC_MEDIAN_H_
