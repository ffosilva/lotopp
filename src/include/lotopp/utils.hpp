/**
 * Lottery C++ Library
 * Filename: utils.hpp
 * 
 * This file contains utility functions header
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#ifndef LOTOPP_UTILS_HPP
#define LOTOPP_UTILS_HPP

#include "lotopp/types.hpp"

#include <cstddef>

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

unsigned int ordx(dezena_t *idx, size_t idx_len);
unsigned int xord(unsigned int sk, dezena_t *idx, size_t idx_len);
} // namespace lotopp

#endif // LOTOPP_UTILS_HPP