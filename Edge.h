/**
 * Project NeuralNet
 */


#ifndef _EDGE_H
#define _EDGE_H

#include <iostream>

class Node;

class Edge {
 public: 
  Edge(double learning_rate, double momentum, Node* root)
      : learning_rate_(learning_rate), momentum_(momentum), head_(root), tail_(root) {}
  Edge(double learning_rate, double momentum, double weight, Node* root)
      : learning_rate_(learning_rate), momentum_(momentum), weight_(weight), head_(root), tail_(root) {}

  void set_weight(double value) { weight_ = value; }
  double weight() { return weight_; }
  void PassActivation(double activation);
  void PassDelta(double delta);
  void UpdateGradient();
  Node* tail() { return tail_; }
  Node* head() { return head_; }
  void set_head(Node* value) { head_ = value; }
  void set_tail(Node* value) { tail_ = value; }
  void UpdateWeight();
 private: 
  friend std::ostream& operator<<(std::ostream& stream, const Edge & layer);
  double gradient_;
  double old_gradient_;
  double weight_;
  double learning_rate_;
  double momentum_;
  Node* head_;
  Node* tail_;
};

#endif //_EDGE_H