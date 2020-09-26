// Copyright 2020   Shreya Bose

#include "../hw2/parse_scores.h"  // NOLINT

double GetGrade(int student_id, int grade_no, const char* file_name) {
  ifstream reader;
  reader.open(file_name);
  if ( !reader.is_open() ) {
    return -3.0;
  }
  int num_of_students;
  reader >> num_of_students;
  int entered_id;
  int entered_grade_count;
  for ( int j = 0; j < num_of_students; ++j ) {
    reader >> entered_id;
    reader >> entered_grade_count;
    for (int i = 0; i < entered_grade_count; ++i) {
      double grade;
      reader >> grade;
      if ( entered_id == student_id && grade_no == i + 1 ) {
        return grade;
      }
    }
    if (entered_id == student_id)
    return -2.0;
  }
  return -1.0;
}

int GetMaxGradeStudentId(const char* file_name) {
  ifstream reader;
  reader.open(file_name);
  if ( !reader.is_open() ) {
    return -3.0;
  }
  int num_of_students;
  reader >> num_of_students;
//  cout << num_of_students << endl;
  int entered_id;
  double max_grade = 0.0;
  int highest = 0;

  for (int i = 0; i < num_of_students; ++i) {
    reader >> entered_id;
    int entered_grade_count;
    reader >> entered_grade_count;
    if ( entered_grade_count == 0)
      return -2.0;
//  cout << entered_grade_count << endl;
    double grade, sum = 0.0;
    for (int j = 0; j < entered_grade_count; ++j) {
      reader >> grade;
      sum += grade;
//      cout << sum << endl;
      double avg = 0.0;
      avg = sum/entered_grade_count;
      if ( avg > max_grade ) {
        max_grade = avg;
        highest = entered_id;
      }
    }
    if ( num_of_students == 0)
    return -1.0;
  }
  return highest;
}

double GetAvgGrade(const char* file_name) {
  ifstream reader;
  reader.open(file_name);
  if ( !reader.is_open() ) {
    return -3.0;
  }
  int num_of_students;
  reader >> num_of_students;
  if ( num_of_students == 0)
    return -1.0;

  double average = 0.0;
  double total = 0.0;
  int entered_id;
  int entered_grade_count;
  for (int i = 0; i < num_of_students; ++i) {
    reader >> entered_id;
    reader >> entered_grade_count;
    if ( entered_grade_count == 0)
      return -2.0;
    total = total + entered_grade_count;
    for (int j = 0; j < entered_grade_count; ++j) {
    double grade;
    reader >> grade;
    average = average + grade;
    }
  }
  return (average/total);
}

