#include "PmergeMe.hpp"

int main(const int argc, const char** argv)
{
  PmergeMe Application(argc, argv);
  return Application.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}