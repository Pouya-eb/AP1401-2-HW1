#include "hw1.h"

// Read_CSV Function :
std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename)
{
    // Opening csv file:
    std::ifstream file { filename };
    if (file.fail()) {
        std::cout << "There is a problem in opening the csv file!" << std::endl;
        return static_cast<std::vector<std::shared_ptr<std::vector<double>>>>(1);
    }
    // Reading csv file :
    std::string line;
    std::vector<std::shared_ptr<std::vector<double>>> data;
    if (file.is_open()) {
        while (getline(file, line)) { // Reading data line by line
            std::vector<double> data_lines;
            std::stringstream row { line };
            std::string col;
            while (getline(row, col, ',')) { // Seprating each line by ,
                data_lines.push_back(std::stod(col)); // Casting string to double
            }
            std::shared_ptr<std::vector<double>> tmp = std::make_shared<std::vector<double>>(data_lines);
            data.push_back(tmp); // Ading the number to vector
        }
    }
    file.close();
    return data;
}