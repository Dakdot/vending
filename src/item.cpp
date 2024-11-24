#include "item.h"
#include <stdexcept>

Item::Item(const std::string &name, const float unitPrice,
           const unsigned int startingQuantity)
    : m_Name(name), m_UnitPrice(unitPrice), m_Quantity(startingQuantity) {}

void Item::add(unsigned int amount) { m_Quantity += amount; }

void Item::remove(unsigned int amount) {
  if (m_Quantity - amount < 0) {
    // Guard against an amount that would make the quantity of the item negative
    throw std::invalid_argument("Failed to remove %d from item: there is not "
                                "enough of this item to remove that many.");
    return;
  }

  m_Quantity -= amount;
}