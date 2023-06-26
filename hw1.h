#ifndef HW1_H
#define HW1_H

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename);
double sigmoid(double input);
std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data,
    double learning_rate, int num_iter);
int predict(std::vector<double> train_val, std::vector<double> weights);
double accuracy(std::vector<std::shared_ptr<std::vector<double>>> train_data,
    std::vector<double> weights);
#endif