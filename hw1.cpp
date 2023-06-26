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

// Sigmoid Function :
double sigmoid(double input)
{
    return { 1.0 / (1 + std::exp(-input)) };
}

// Training Function :
std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data,
    double learning_rate, int num_iter)
{
    int real_val {}, predict_val {};
    std::vector<double> weights { 0.0, 0.0, 0.0 };
    int length_wights { static_cast<int>(weights.size()) };
    int length_train { static_cast<int>(train_data.size()) };

    for (int i {}; i < num_iter; i++) { // Number of Iteration
        for (int j {}; j < length_train; j++) { // Training for whole data
            real_val = train_data[j]->at(length_wights - 1);
            predict_val = predict(*train_data[j], weights);
            std::vector<double> bias { 1 };
            for (int k {}; k < length_wights; k++) {
                if (k < 2) {
                    bias.push_back(train_data[j]->at(k));
                }
                weights[k] += learning_rate * (real_val - predict_val) * bias[k]; // formula for updating weights
            }
        }
    }
    return weights;
}

// Predict Function :
int predict(std::vector<double> train_val, std::vector<double> weights)
{
    double sum { weights[0] };
    int length_train = train_val.size();
    for (int i { 1 }; i < length_train; i++) {
        sum += train_val[i - 1] * weights[i]; // output of neuron without activation function
    }

    if (sigmoid(sum) >= 0.5) { // activation function = sigmoid
        return 1;
    } else {
        return 0;
    }
}

// Accuracy Function
double accuracy(std::vector<std::shared_ptr<std::vector<double>>> train_data, std::vector<double> weights)
{
    int length_train { static_cast<int>(train_data.size()) };
    int length_wights { static_cast<int>(weights.size()) };
    double accurate {};

    for (int i {}; i < length_train; i++) { // calculating accuracy of the model
        if (predict(*train_data[i], weights) == (train_data[i]->at(length_wights - 1))) {
            accurate++;
        }
    }
    return accurate / length_train;
}
