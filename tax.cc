// Copyright 2020 Shreya Bose

#include <inc/tax.h>
using std::istream;
using std::string;

namespace csce240 {

Tax::Tax() {
  code_ = "";
  percent_ = 0.0;
}

Tax::Tax(const std::string& code, double percent) {
  if (percent > 0)
  percent_ = percent;
  code_ = code;
}

// accessors
const std::string& Tax::code() const {
  return code_;
}

double Tax::percent() const {
  return percent_;
}

double Tax::operator*(double rhs) const {
  rhs = rhs* percent_/100;
  return rhs;
}

double operator*(double lhs, const Tax& rhs) {
  return lhs * rhs;
}

std::ostream& Tax::Extract(std::ostream* out) const {
  *out << code_ << ":" << percent_;
  return *out;
}

std::ostream& operator<<(std::ostream& lhs, const Tax& rhs) {
  return rhs.Extract(&lhs);
}

std::istream& Tax::Insert(std::istream* in) {
  *in >> code_ >> percent_;
  return *in;
}


std::istream& operator>>(std::istream& lhs, Tax& rhs) {
  return rhs.Insert(&lhs);
}

}  // namespace csce240
