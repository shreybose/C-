// Copyright 2020 Shreya Bose

#include <inc/tax.h>
using std::istream;
using std::string;

Tax::Tax(const std::string& code, double percent) {
  if (percent > 0)
  percentage = percent;
  new_code = code;
}

// accessors
const std::string& Tax::code() const {
  return new_code;
}

double Tax::percent() const {
  return percentage;
}
// mutators
void Tax::percent(double new_percent) {
  if (new_percent > 0)
  percentage = new_percent;
}

double Tax::Calculate(double amount) const {
  return amount = amount * percentage/100;
}

std::ostream& Tax::Extract(std::ostream* out) const {
  *out << new_code << ":" << percentage;
  return *out;
}

std::istream& Tax::Insert(std::istream* in) {
  *in >> new_code;
  *in >> percentage;
  return *in;
}


