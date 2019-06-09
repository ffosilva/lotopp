/**
 * Lottery C++ Library
 * Filename: utils.cpp
 * 
 * This file contains utility functions implementation
 * 
 * Author: Fábio Silva <fabio.fernando.osilva@gmail.com>
 */

#include <climits>
#include <cstddef>

#include "lotopp/utils.hpp"

namespace lotopp
{
static unsigned long gcd_ui(unsigned long x, unsigned long y)
{
  unsigned long t;
  if (y < x)
  {
    t = x;
    x = y;
    y = t;
  }
  while (y > 0)
  {
    t = y;
    y = x % y;
    x = t; /* y1 <- x0 % y0 ; x1 <- y0 */
  }
  return x;
}

unsigned long comb(unsigned long n, unsigned long k)
{
  unsigned long d, g, r = 1;
  if (k == 0)
    return 1;
  if (k == 1)
    return n;
  if (k >= n)
    return (k == n);
  if (k > n / 2)
    k = n - k;
  for (d = 1; d <= k; d++)
  {
    if (r >= ULONG_MAX / n)
    {                       /* Possible overflow */
      unsigned long nr, dr; /* reduced numerator / denominator */
      g = gcd_ui(n, d);
      nr = n / g;
      dr = d / g;
      g = gcd_ui(r, dr);
      r = r / g;
      dr = dr / g;
      if (r >= ULONG_MAX / nr)
        return 0; /* Unavoidable overflow */
      r *= nr;
      r /= dr;
      n--;
    }
    else
    {
      r *= n--;
      r /= d;
    }
  }
  return r;
}

unsigned int ordx(unsigned int *idx, size_t idx_len)
{
  unsigned int s = 0;
  unsigned int j = 1;
  unsigned int b = 1;

  for (size_t r = 0; r < idx_len; ++r)
  {
    unsigned int i = idx[r];
    i -= 1;

    if (i == r)
      continue;

    while (j < i - r)
    {
      b *= j + r;
      b /= j;
      j += 1;
    }

    b *= i;
    b /= r + 1;
    s += b;
  }

  return s;
}

static unsigned int sord(unsigned int sk, unsigned int *idx, size_t idx_len)
{
  if (idx_len == 0)
  {
    return 0;
  }

  if (idx_len > 1)
  {
    int j = 0;
    int prev_b = 0;
    int b = 1;

    while (b <= sk)
    {
      prev_b = b;
      j += 1;
      b *= (j + idx_len);
      b /= j;
    }

    b = prev_b;

    for (size_t r = idx_len - 1; r > 1; r--)
    {
      idx[r] = j;
      sk -= b;

      b *= r + 1;
      b /= j + r;

      while (b > sk)
      {
        j -= 1;
        b *= j;
        b /= (j + r);
      }
    }

    idx[1] = j;
    sk -= b;
  }

  idx[0] = sk;

  return 0;
}

unsigned int xord(unsigned int sk, unsigned int *idx, size_t idx_len)
{
  unsigned int return_val = sord(sk, idx, idx_len);

  for (size_t i = 0; i < idx_len; i++)
  {
    int r = idx[i];
    idx[i] = i + r + 1;
  }

  return return_val;
}

} // namespace lotopp