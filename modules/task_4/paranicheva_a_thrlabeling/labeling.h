// Copyright 2021 Paranicheva Alyona
#ifndef MODULES_TASK_4_PARANICHEVA_A_THRLABELING_LABELING_H_
#define MODULES_TASK_4_PARANICHEVA_A_THRLABELING_LABELING_H_

#include <vector>
#include <utility>

std::vector<int> getRandomMatrix(int rows, int cols);
std::pair<std::vector<int>, std::vector<int> > firstMark(std::vector<int>, int, int);
std::vector<int> secondMark(std::vector<int>, int, int, std::vector<int>);
std::vector<int> CLabeling(const std::vector<int>&, int, int);

std::pair<std::vector<int>, std::vector<int> > firstMarkThr(std::vector<int>, int, int);
std::vector<int> CLabelingThr(const std::vector<int>& array, int rows, int cols);
std::vector<int> Transform(const std::vector<int>& array, int rows, int cols);

#endif  // MODULES_TASK_4_PARANICHEVA_A_THRLABELING_LABELING_H_
