#include "user.h"
#include "vending-machine.h"

int main() {
  User user(10);
  VendingMachine machine;

  Item sprite("Sprite", 2.50, 1);
  Item coke("Coke", 2.75, 15);
  Item chips("Lay's Chips", 4.00, 7);
  Item popTarts("Pop Tarts", 3.00, 11);

  machine.addNewItem(sprite);
  machine.addNewItem(coke);
  machine.addNewItem(chips);
  machine.addNewItem(popTarts);

  machine.approach(user);

  return 0;
}