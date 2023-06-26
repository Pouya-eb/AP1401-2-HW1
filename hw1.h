#ifndef HW1_H
#define HW1_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename);

#endif