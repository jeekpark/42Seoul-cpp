/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 17:53:15 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array
{
public:
					Array(void) : mLength(0), mArray(new T[mLength]) {}
					Array(const unsigned int n) : mLength(n), mArray(new T[mLength]) {}
					~Array(void)
					{
						delete [] mArray;
					}
					Array(const Array& copy) : mLength(copy.mLength), mArray(new T[mLength])
					{
						for (unsigned int i = 0; i < mLength; ++i)
						{
							mArray[i] = copy.mArray[i];
						}
					}
	Array&			operator=(const Array& copy)
					{
						if (this == &copy)
							return *this;
						delete [] mArray;
						mLength = copy.mLength;
						mArray = new T[mLength];
						for (unsigned int i = 0; i < mLength; ++i)
						{
							mArray[i] = copy.mArray[i];
						}
						return *this;
					}
	T&				operator[](const unsigned int i) const
					{
						if (i >= mLength)
							throw std::exception();
						return mArray[i];
					}
	unsigned int	size(void) const
					{
						return mLength;
					}

private:
	unsigned int	mLength;
	T*				mArray;
};


#endif