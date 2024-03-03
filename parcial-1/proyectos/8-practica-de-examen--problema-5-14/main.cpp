#include <array>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

inline std::vector<ItemCount> get_item_counts(const std::vector<Item> items);
void print_introductory_message();
float get_total_cost(const std::vector<ItemCount>& item_counts);
void print_item_count_summary(const std::vector<ItemCount>& item_counts);

struct Item {
  float unitary_price;
  std::string name;

  Item(float unitary_price, std::string name): 
    unitary_price(unitary_price), name(name) 
  {}

  Item(): unitary_price(0) {}
};

struct ItemCount {
  const Item item;
  uint32_t count;

  ItemCount(const Item item, uint32_t count): 
    item(item), count(count) 
  {}

  ItemCount(): count(0) {}
};


int main (int argc, char *argv[]) {
  const std::vector<Item> items {
    Item( 5.0f, "Plátano macho"),
    Item(10.0f, "Manzana golden select")
  };

  std::vector<ItemCount> item_counts = get_item_counts(items);
  
  print_introductory_message();

  while (true) {
    std::cout << "Seleccione uno de los siguientes productos (usando su número de producto) para añadir a su carrito; ingrese -1 para salir del programa" << std::endl;
    print_item_count_summary(item_counts);

    int selected_item_number = 0;
    std::cout << "Número del producto: ";
    std::cin >> selected_item_number;
    if (
        selected_item_number < 0 || 
        selected_item_number >= item_counts.size()
    ) {
      if (selected_item_number == -1) { 
        std::cout << "Terminando el ciclo de productos a integrar" << std::endl;
        break; 
      }
      std::cout << "El número de producto ingresado es inválido" << std::endl;
      continue;
    }

    int amount = 0;
    std::cout << "Cantidad del producto: ";
    std::cin >> amount;
    if (amount <= 0) {
      std::cout << "La cantidad de producto ingresado es inválido" << std::endl;
      continue;
    }

    auto& item_count = item_counts[selected_item_number];
    item_count.count += amount;
  }

  print_item_count_summary(item_counts);

  return EXIT_SUCCESS;
}

inline std::vector<ItemCount> get_item_counts(const std::vector<Item> items) {
  std::vector<ItemCount> item_counts(0);
  for (auto i = 0; i < items.size(); i++) {
    item_counts.push_back(ItemCount(items.at(i), 0));
  }
  return item_counts;
}

void print_introductory_message() {
  std::cout << "Ingrese el número de producto a comprar y la cantidad deseada para calcular el total a pagar" << std::endl;
}

float get_total_cost(const std::vector<ItemCount>& item_counts) {
  float total_cost = 0;
  for (auto& item_count: item_counts) {
    total_cost += item_count.count * item_count.item.unitary_price;
  }
  return total_cost;
}

void print_item_count_summary(const std::vector<ItemCount>& item_counts) {
  for (auto& item_count: item_counts) {
    std::cout << "\"" << item_count.item.name << "\"" << " ... $" << item_count.item.unitary_price << " (" << item_count.count << ")" << std::endl;
  }
  std::cout << "El total hasta ahora es: $" << get_total_cost(item_counts) << std::endl;
}
