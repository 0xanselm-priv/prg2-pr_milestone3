/**
 * Project NeuralNet
 */


#ifndef _LAYER_H
#define _LAYER_H
#include <vector>
#include "Node.h"

class Layer {
 public: 
  Layer(std::size_t num, std::function<double(double)> activation_function, std::function<double(double)> activation_function_diff);
  
  friend std::ostream& operator<<(std::ostream& stream, const Layer& elem);
  void set_out_weights(std::vector< std::vector <double> > weights);
  void PassActivations() { for(auto node : nodes_) node.PassActivations(node.post_activation()); }
  void PassDeltas() { for(auto node : nodes_) node.PassDeltas(node.post_delta()); }
  void UpdateActivations() { for(auto node : nodes_) node.UpdateActivation(); }
  void UpdateDeltas() { for(auto node : nodes_) node.UpdateDelta(); }
  std::vector<Node> nodes() { return nodes_; }
 private:
  std::vector<Node> nodes_;
};


#endif //_LAYER_H