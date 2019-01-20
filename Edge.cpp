/**
 * Project NeuralNet
 */


#include "Edge.h"
#include "Node.h"
#include <iostream>

void Edge::PassDelta(double delta)
{
  tail_->AddPreDelta(weight_ * delta);
  old_gradient_ = gradient_;
  gradient_ = learning_rate_ * delta * tail_->post_activation();
  old_gradient_ =  (1-momentum_) * gradient_ + momentum_ * old_gradient_;
  weight_ += old_gradient_;
}

void Edge::PassActivation(double activation)
{
  head_->AddPreActivation(weight_ * activation);
}

std::ostream& operator<<(std::ostream& stream, const Edge & edge)
{
  return stream << edge.weight_;
}

void Edge::UpdateWeight()
{
  weight_ += (1-momentum_) * gradient_ + momentum_ * old_gradient_;
}