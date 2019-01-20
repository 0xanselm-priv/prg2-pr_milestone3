/**
 * Project NeuralNet
 */


#include "Layer.h"
#include <vector>
#include "Node.h"

Layer::Layer(std::size_t num, std::function<double(double)> activation_function, std::function<double(double)> activation_function_diff)
    : nodes_(std::vector<Node>(num, Node(activation_function, activation_function_diff)))
{
  nodes_.push_back(Node([](double value) { return 1; }, [](double value) { return 0; }));
}

std::ostream& operator<<(std::ostream& stream, const Layer& elem)
{
  for(Node node : elem.nodes_)
  {
    for(auto weight : node.out_weights())
    {
      stream << weight;
    }
    stream << std::endl;
  }
  return stream;
}

void Layer::set_out_weights(std::vector< std::vector <double> > weights)
{
  for(std::size_t i = 0; i < weights.size(); ++i)
  {
    for(std::size_t j = 0; j < weights.size(); ++j)
    {
      nodes_[i].out_edges()[j].set_weight(weights[i][j]);
    }
    
  }
}