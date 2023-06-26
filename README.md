# Advanced Programming - HW1
<p  align="center"> <b>Homework 1 - Spring 2023 Semester <br> Deadline: Wednesday Esfand 17st - 11:59 pm</b> </p>



## Outline

In this homework we are going to implement an algorithm to classified data using **Perceptron** in c++. 
We will be implementing all our functions in `hw1.cpp` and `hw1.h`. remember you should put all declarations in the `.h` and all the implementations in the `.cpp` file.

- A biological neuron receives its input signals from other neurons through dendrites (small fibers). Likewise, a perceptron receives its data from other perceptrons through input neurons that take numbers.

- The connection points between dendrites and biological neurons are called synapses. Likewise, the connections between inputs and perceptrons are called weights. They measure the importance level of each input.

- In a biological neuron, the nucleus produces an output signal based on the signals provided by dendrites. Likewise, the nucleus (colored in blue) in a perceptron performs some calculations based on the input values and produces an output.

- In a biological neuron, the output signal is carried away by the axon. Likewise, the axon in a perceptron is the output value which will be the input for the next perceptrons.

![](/resources/Figure_1.png)

The following image shows a detailed structure of a perceptron. In some contexts, the bias, `b` is denoted by `w0`. The input, `x0` always takes the value 1. So, `b * 1 = b`.

![](/resources/Figure_2.png)

The activation function takes the output of z as its input and calculates the output y based on the type of activation function we use. For now, we use the sigmoid activation function defined below.


$$ sigmoid(z) = \frac{1}{1 + exp(-z)} $$

The entire calculation process can be denoted in the following diagram.

![](/resources/Figure_3.png)

Perceptron use an iterative algorithm to train weights and find optimum ones. This algorithm updates each weight with below equation.
```math
wk[i + 1] = wk[i] + learning\_rate × (real\_value − predicted\_value) × xk
```


## Questions
1. write sigmoid function to measure output of z in Figure 2;

2. At first you need to write function to import data from csv file and store it in vector.
    ```cpp
    std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename);
    ```

3. The inputs of perceptron are bias that is scalar and x, y of data. Now you must train weight with data; so implement train function. num_iter is the number of repeating algorithm. you must repeat 1 equation num_iter times.
    ```cpp
    std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data, double learning_rate, int num_iter);
    ```

4. First use data.csv to train and predict data next use moons.csv.

5. Calculate accuracy of model.($\frac{number\ of\ true\ predictions}{number\ of\ all\ points}$)


<br/>
<p  align="center"> <b>GOOD LUCK</b> </p>
