/**
 * Project NeuralNet
 */


#ifndef _NODE_H
#define _NODE_H

#include <vector>
#include <iostream>
#include "Edge.h"

// class Node;

// class Input : Node {
//  public:
//   std::vector<double> out_weights();
//   void set_out_weights(std::vector<double> weights);
//   void PassActivations();
//  private:
//   double input_;
//   std::vector<Hidden> out_edges_;
// }

// class Output : Node {
//  public: 
//   void UpdateActivation();
//   void set_post_activation(double value) { post_activation_ = value; }
//   void UpdateDelta();
//   void PassDelta();
//   double ComputeCost(std::vector<double> outputs)
//  private:
//   std::vector<Hidden> in_edges_;
//   double pre_activation_;
//   double post_activation_;

// }
class Node {
  public:
  Node(std::function<double(double)> activ_function, 
    std::function<double(double)> activ_function_diff)
      : activ_function_(activ_function), activ_function_diff_(activ_function_diff) {}
  void PassActivations(double activation);
  void PassDeltas(double delta);
  void UpdateActivation();
  void UpdateDelta();

  void AddPreDelta(double value);
  void AddPreActivation(double value);
  std::vector<double> out_weights();
  void set_out_weights(std::vector<double> weights);
  double post_activation() { return post_activation_; }
  double post_delta() { return post_delta_; }
  std::vector<Edge> out_edges() { return out_edges_; }
  std::vector<Edge> in_edges() { return in_edges_; }
  void set_post_activation(double value) { post_activation_ = value; }
  void set_post_delta(double value) { post_delta_ = value; }
 private: 
  std::vector<Edge> out_edges_;
  std::vector<Edge> in_edges_;
  std::function<double(double)> activ_function_;
  std::function<double(double)> activ_function_diff_;
  double pre_activation_;
  double post_activation_;
  double pre_delta_;
  double post_delta_;
};

#endif //_NODE_H