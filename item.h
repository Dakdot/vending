#pragma once

#include <string>

class Item {
public:
  Item(const std::string &name, const float unitPrice,
       const unsigned int startingQuantity);

  void add(unsigned int amount);
  void remove(unsigned int amount);

  inline const float getUnitPrice() const { return m_UnitPrice; }
  inline const std::string &getName() const { return m_Name; }
  inline const unsigned int getQuantity() const { return m_Quantity; }

private:
  const std::string &m_Name;
  const float m_UnitPrice;
  unsigned int m_Quantity;
};