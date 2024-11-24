#pragma once

#include <cstdio>
#include <iostream>
#include <string>

namespace out {
template <typename T> inline void println(T value) {
  std::cout << value << std::endl;
}

template <typename T> inline void print(T value) { std::cout << value; }

template <typename T, typename... Args>
inline void println(T value, Args... args) {
  std::cout << value << " ";
  print(args...);
  std::cout << std::endl;
}

template <typename T, typename... Args>
inline void print(T value, Args... args) {
  std::cout << value << " ";
  print(args...);
}

template <typename... Args>
inline void printf(const std::string &format, Args... args) {
  std::printf(format.c_str(), args...);
}

} // namespace out