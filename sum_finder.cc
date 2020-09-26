// Copyright 2020 Shreya Bose

#include <sum_finder.h>  // NOLINT


size_t** FindSum(
    int sum, const int** matrix, const size_t matrix_size[],
    size_t* sums_found) {
  *sums_found = 0;
  const size_t rows = matrix_size[kRow];

  size_t** ret = nullptr;
  if (rows > 1) {
    ret = ColSum(sum, matrix, matrix_size, sums_found);
  }

  size_t** summation = new size_t*[4];
  for (size_t r = 0; r < 2; ++r) {
    summation[r] = new size_t[4];
  }
    for (size_t i = 0; i < matrix_size[kRow]; ++i) {
      for (size_t j = 0; j < matrix_size[kCol]; ++j) {
        int row = 0;
        for (size_t l = j; l < matrix_size[kCol]; ++l) {
          row += matrix[i][l];
          if (row == sum) {
            summation[*sums_found][0] = i;
            summation[*sums_found][1] = j;
            summation[*sums_found][2] = i;
            summation[*sums_found][3] = l;
            *sums_found += 1;
          }
        }
      }
    }
    size_t** output = new size_t*[*sums_found];
    for (size_t i = 0; i < *sums_found; ++i) {
      output[i] = new size_t[4];
      for (int k = 0; k < 4; ++k) {
        output[i][k] = 0;
      }
    }
    for (int i = 0; i < 2; ++i) {
      output[i] = new size_t[4];
      for (int j = 0; j < 4; ++j) {
        output[i][j] = summation[i][j];
      }
    }

    // deleting each sub array
    for (int d = 0; d < 1; ++d) {
      delete[] summation[d];
    }
    // deleting main array
    delete[] summation;
  return ret;
  return summation;
}

size_t** ColSum(
    int sum, const int** matrix, const size_t matrix_size[],
    size_t* sums_found) {
  *sums_found = 0;
  size_t** summation = new size_t*[4];

  for (int r = 0; r < 2; ++r) {
    summation[r] = new size_t[4];
  }
    for (size_t i = 0; i < matrix_size[kRow]; ++i) {
      for (size_t j = 0; j < matrix_size[kCol]; ++j) {
        int col = 0;
        for (size_t l = j; l < matrix_size[kCol]; ++l) {
          col += matrix[l][i];
          if (col == sum) {
            summation[*sums_found][0] = i;
            summation[*sums_found][1] = l;
            summation[*sums_found][2] = j;
            summation[*sums_found][3] = l;
            *sums_found += 1;
          }
        }
      }
    }
    size_t** output = new size_t*[*sums_found];
    for (size_t i = 0; i < *sums_found; ++i) {
      output[i] = new size_t[4];
      for (int k = 0; k < 4; ++k) {
        output[i][k] = 0;
      }
    }
    for (size_t i = 0; i < *sums_found; ++i) {
      output[i] = new size_t[4];
      for (int j = 0; j < 4; ++j) {
        output[i][j] = summation[i][j];
      }
    }
    for (int d = 0; d < 1; ++d) {
      delete[] summation[d];
    }
    delete[] summation;
  return summation;
}
