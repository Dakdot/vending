#pragma once

#include "output.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#define VALUE_YES 1
#define VALUE_NO 0

namespace in {

inline std::string promptString(const std::string &message) {
  out::println(message);
  out::print("(string) >");
  std::string input;
  std::getline(std::cin, input);
  return input;
}

inline std::string promptString(const std::string &message,
                                const std::string &defaultValue) {
  std::string input = promptString(message);
  if (input.empty())
    return defaultValue;
  return input;
}

inline int promptInt(const std::string &message) {
  unsigned int attempts = 0;
  while (true) {
    if (attempts % 3 == 0) // On every third attempt
      out::println(message);

    out::print("(numeric) > ");
    std::string input;
    std::getline(std::cin, input);
    try {
      int value = std::stoi(input);
      return value;
    } catch (const std::exception &e) {
      out::println("Invalid input: please type a number and try again.");
    }
    attempts++;
  }
}

inline int promptInt(const std::string &message, const int defaultValue) {
  out::println(message);
  out::print("(numeric) > ");
  std::string input;
  std::getline(std::cin, input);
  try {
    int value = std::stoi(input);
    return value;
  } catch (const std::exception &e) {
    return defaultValue;
  }
}

inline unsigned char promptYesNo(const std::string &message) {
  unsigned int attempts = 0;
  while (true) {
    if (attempts % 3 == 0) // On every third attempt
      out::println(message);

    out::print("(type y/n) > ");
    std::string input;
    std::getline(std::cin, input);
    if (input.find("y") != std::string::npos ||
        input.find("Y") != std::string::npos)
      return VALUE_YES;

    if (input.find("n") != std::string::npos ||
        input.find("N") != std::string::npos)
      return VALUE_NO;

    out::println("Invalid input. Please type 'Y' or 'N' and try again.");
    attempts++;
  }
}

inline unsigned char promptYesNo(const std::string &message,
                                 const int defaultValue) {
  // Guard against random ints being input into this function
  if (defaultValue != VALUE_YES && defaultValue != VALUE_NO)
    throw std::invalid_argument("Invalid argument to promptYesNo()");

  out::println(message);
  out::printf("(type %s) > ", (defaultValue == VALUE_YES ? "Y/n" : "y/N"));
  std::string input;
  std::getline(std::cin, input);
  if (input.find("y") != std::string::npos ||
      input.find("Y") != std::string::npos)
    return VALUE_YES;

  if (input.find("n") != std::string::npos ||
      input.find("N") != std::string::npos)
    return VALUE_NO;

  return defaultValue;
}

} // namespace in