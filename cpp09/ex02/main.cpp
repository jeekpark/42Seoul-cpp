/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:14:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:20:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
void merge(std::vector<int>& vec, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (i = 0; i < n1; ++i)
    L[i] = vec[left + i];
  for (j = 0; j < n2; j++)
    R[i] = vec[mid + 1 + j];

  i = 0; j = 0; k = left;
  while ()
}


void mergeSort(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

int main(int argc, char** argv)
{

    return 0;
}