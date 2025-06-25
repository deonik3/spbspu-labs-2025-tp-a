#include "delimiter.hpp"

std::istream &fedorov::operator>>(std::istream &in, DelimiterStr &&exp)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  for (size_t i = 0; exp.expected[i] != '\0'; ++i)
  {
    in >> DelimiterI{exp.expected[i]};
  }
  return in;
}

std::istream &fedorov::operator>>(std::istream &in, DelimiterI &&exp)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }

  char c = 0;
  in >> c;

  if (in && std::tolower(c) != std::tolower(exp.expected))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
