/**
 * Lottery C++ Library
 * Filename: Utils.hpp
 * 
 * This file contains utility functions
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#ifndef LOTOPP_UTILS_HPP
#define LOTOPP_UTILS_HPP

namespace lotopp
{
/**
 * The number of combinations of N things taken k at a time.
 * This is often expressed as "N choose k".
 * @param n number of things
 * @param k number of elements taken
 * @return the total number of combinations
 * 
 * NOTE: if k > n, then a 0 is returned.
 */
unsigned long comb(unsigned long n, unsigned long k);

unsigned int ordx(unsigned int *idx, size_t idx_len);
unsigned int xord(unsigned int sk, unsigned int *idx, size_t idx_len);
} // namespace lotopp

#endif