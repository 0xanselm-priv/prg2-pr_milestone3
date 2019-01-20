/**
 * Project NeuralNet
 */


#ifndef _NEURALNET_H
#define _NEURALNET_H
#include <vector>
#include <iostream>
#include <math.h>
#include "Layer.h"

class NeuralNet {
 public: 
  NeuralNet(std::vector<std::size_t> topology_, 
    std::function<double(double)> hidden_activation_function=[](double x)->double { return 1/(1 + exp(-x)); }, 
    std::function<double(double)> hidden_activation_function_diff=[](double x)->double { return exp(-x)/pow(1+exp(-x),2); }, 
    double learning_rate=1, 
    double momentum=0);
  NeuralNet(std::string filename);

  void Learn(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs, std::size_t epochs = 1);
  friend std::ostream& operator<<(std::ostream& stream, const NeuralNet& elem);
 private: 
  void forward_(std::vector<double> inputs);
  void backward_(std::vector<double> outputs);
  double learning_rate_;
  double momentum_;
  std::vector<std::size_t> topology_;
  std::vector<Layer> layers_;
};

#endif //_NEURALNET_H