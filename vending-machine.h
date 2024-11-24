#pragma once

#include "item.h"
#include "user.h"
#include <map>

class VendingMachine {
public:
  void approach(User &user);

  const unsigned int addNewItem(Item &item);
  void dispenseItem(Item &item);

  Item &getItemById(const unsigned int id);

private:
  std::map<unsigned int, Item> m_Items;
};