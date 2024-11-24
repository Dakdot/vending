#pragma once

#include <stdexcept>
class User {
public:
  inline User(float startingAmount) : m_Balance(startingAmount) {}

  inline const float getBalance() const { return m_Balance; }

  inline void depositMoney(float amount) {
    if (amount < 0)
      throw std::invalid_argument("Deposit amount cannot be negative.");
    m_Balance += amount;
  }

  inline void withdrawMoney(float amount) {
    if (amount < 0)
      throw std::invalid_argument("Withdraw amount cannot be negative.");
    if (m_Balance - amount < 0)
      throw std::runtime_error("User does not have enough money to withdraw.");
    m_Balance -= amount;
  }

private:
  float m_Balance = 0.0f;
};