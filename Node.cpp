/**
 * Project NeuralNet
 */


#include "Node.h"
#include "Edge.h"
#include <vector>

void Node::PassActivations(double activation) {
  for(Edge & edge : out_edges_)
  {
    edge.PassActivation(activation);
  }
}

void Node::PassDeltas(double delta) {
  for(Edge & edge : in_edges_)
  {
    edge.PassDelta(delta);
  }
}

void Node::UpdateDelta() {
  post_delta_ = pre_delta_*activ_function_diff_(pre_activation_);
}

void Node::UpdateActivation() {
  post_activation_ = activ_function_diff_(pre_activation_);
}

// void Node::Clear()
// {
//   pre_activation_ = 0;
//   post_activation_ = 0;
//   pre_delta_ = 0;
//   post_delta_ = 0;
// }

void Node::AddPreDelta(double value)
{
  pre_delta_ += value;
}


void Node::AddPreActivation(double value)
{
  pre_activation_ += value;
}

std::vector<double> Node::out_weights() {
  std::vector<double> out_weights = {};
  std::transform(out_edges_.begin(), out_edges_.end(), std::back_inserter(out_weights), [](Edge e){ return e.weight(); });
  return out_weights;
}

void Node::set_out_weights(std::vector<double> weights)
{
  for (std::size_t index = 0; index < weights.size(); ++index)
  {
    out_edges_[index].set_weight(weights[index]);
  }
}