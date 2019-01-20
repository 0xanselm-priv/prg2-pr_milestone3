/**
 * Project NeuralNet
 */

#include "NeuralNet.h"
#include <vector>
#include <fstream>

int main()
{
  std::vector<std::size_t> topology = {1,2,3,1};
	NeuralNet nn(topology);
  // std::ofstream os("topology.txt");
  // os << nn;
}