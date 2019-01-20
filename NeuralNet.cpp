/**
 * Project NeuralNet
 */


#include "NeuralNet.h"
#include "Layer.h"
#include "Node.h"
#include <math.h>

NeuralNet::NeuralNet(
    std::vector<std::size_t> topology, 
    std::function<double(double)> activation_function, 
    std::function<double(double)> activation_function_diff, 
    double learning_rate, 
    double momentum)
    : topology_(topology), learning_rate_(learning_rate), momentum_(momentum), layers_(std::vector<Layer>())
{
  for(std::size_t size : topology_)
  {
    layers_.push_back(Layer(size, activation_function, activation_function_diff));
  }
  for(std::size_t layer_num = 0; layer_num < topology_.size() - 1; ++layer_num)
  {
    for(std::size_t tail_num = 0; tail_num < layers_[layer_num].nodes().size(); ++tail_num)
    {
      layers_[layer_num].nodes()[tail_num].out_edges() = std::vector<Edge>(topology_[layer_num+1], Edge(learning_rate, momentum, &layers_[layer_num].nodes()[tail_num]));
      for(std::size_t head_num = 0; head_num < layers_[layer_num+1].nodes().size(); ++head_num)
      {
        layers_[layer_num].nodes()[tail_num].out_edges()[head_num].set_tail(&layers_[layer_num+1].nodes()[head_num]);
        layers_[layer_num].nodes()[tail_num].out_edges()[tail_num].set_head(&(layers_[layer_num+1].nodes()[head_num]));
      }
    }
  }
}

NeuralNet::NeuralNet(std::string filename) 
    : topology_(std::vector<std::size_t>{})
{
//   std::string line;
//   std::ifstream f(filename);
//   if (in)
//   {
//     std::getline(f, line);
//   }
//   std::stringstream ss(line);
//   std::size_t value;
//   while(ss >> value)
//     topology_.push_back(value);
//   for(std::size_t i = 0; i < in_num)
//   {
//     for(std::size_t j = 0; j < topology_[0])
//     {
//       std::getline(f, line);
//       std::stringstream ss(line);
//       std::double value;
//       ss >> value;
//       
//     }
//  }
}


void NeuralNet::forward_(std::vector<double> inputs) {
  for(std::size_t i = 0; i < inputs.size(); ++i)
  {
    layers_[0].nodes()[i].set_post_activation(inputs[i]);
  }
  layers_[0].PassActivations();
  for(std::size_t i = 1; i < layers_.size() -1; ++i)
  {
    layers_[i].UpdateActivations();
    layers_[i].PassActivations();
  }
  layers_.back().UpdateActivations();
}

void NeuralNet::backward_(std::vector<double> outputs) {
  for(std::size_t i = 0; i < outputs.size(); ++i)
  {
    layers_.back().nodes()[i].set_post_delta(layers_.back().nodes()[i].post_activation() - outputs[i]);
  }
  layers_.back().PassDeltas();
  for (std::size_t i = layers_.size()-2; i > 0; --i)
  {
    layers_[i].UpdateDeltas();
    layers_[i].PassDeltas();
  }
}

std::ostream& operator<<(std::ostream& stream, const NeuralNet& elem)
{
  for(auto size : elem.topology_)
  {
    stream << size;
  }
  stream << std::endl;
  for(auto layer : elem.layers_)
  {
    stream << layer;
  }
  return stream << std::endl;
}

void NeuralNet::Learn(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs, std::size_t epochs)
{
  for(std::size_t j = 0; j < epochs; ++j)
  {
    for(std::size_t i = 0; i < inputs.size(); ++i)
    {
      forward_(inputs[i]);
      backward_(outputs[i]);
    }
  }
}


