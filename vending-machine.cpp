#include "vending-machine.h"
#include "input.h"

#include "output.h"

void VendingMachine::approach(User &user) {
  bool running = true;
  bool showWelcome = true;

  while (running) {
    if (showWelcome)
      out::println(
          "Welcome to the vending machine! Check out what's in stock:");
    showWelcome = false; // Only show the welcome on the first iteration

    for (auto &item : m_Items) {
      out::printf("[%d]: %s ($%.2f) - %d left\n", item.first,
                  item.second.getName().c_str(), item.second.getUnitPrice(),
                  item.second.getQuantity());
    }

    out::printf("You have $%.2f. What would you like to purchase?\n",
                user.getBalance());
    int input = in::promptInt("Please enter the ID of the item.");

    if (m_Items.count(input) == 0) {
      out::println(input, "is not a valid ID. Please try again.");
      continue;
    }

    Item &selectedItem = m_Items.at(input);

    if (selectedItem.getQuantity() < 1) {
      out::println("That item is out of stock! Please choose something else.");
      continue;
    }

    if (user.getBalance() < selectedItem.getUnitPrice()) {
      out::println("You don't have enough money for that!");
      continue;
    }

    out::printf("You selected %s for $%.2f.\n", selectedItem.getName().c_str(),
                selectedItem.getUnitPrice());
    const int answer =
        in::promptYesNo("Are you sure you would like to buy one?", VALUE_YES);

    if (answer == VALUE_NO) {
      out::println("Canceled purchase.");
      continue;
    }

    dispenseItem(selectedItem);
    user.withdrawMoney(selectedItem.getUnitPrice());
    out::printf("Enjoy your %s!\n", selectedItem.getName().c_str());
  }
}

const unsigned int VendingMachine::addNewItem(Item &item) {
  unsigned int assignedId = 0;
  for (assignedId = 0; assignedId < m_Items.size(); assignedId++) {
    if (m_Items.count(assignedId) == 0) // If the ID is not being used
      break; // Break out of this loop so we can use it!
  }

  m_Items.emplace(assignedId, item);
  return assignedId;
}

void VendingMachine::dispenseItem(Item &item) { item.remove(1); }

Item &VendingMachine::getItemById(const unsigned int id) {
  return m_Items.at(id);
}