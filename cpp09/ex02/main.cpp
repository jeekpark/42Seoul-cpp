#include "PmergeMe.hpp"

int main(const int argc, const char** argv)
{
  PmergeMe application(argc, argv);
  return application.run() ? 0 : 1;
}