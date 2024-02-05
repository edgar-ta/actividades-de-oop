#include "parts-worker.h"
#include <cmath>

PartsWorker::PartsWorker(int number_of_pieces, float price_per_piece): number_of_pieces(number_of_pieces), price_per_piece(price_per_piece) {}
void PartsWorker::set_number_of_pieces(int number_of_pieces) { this->number_of_pieces = number_of_pieces; }
int PartsWorker::get_number_of_pieces() { return number_of_pieces; }
void PartsWorker::set_price_per_piece(float price_per_piece) { this->price_per_piece = price_per_piece; }
float PartsWorker::get_price_per_piece() { return price_per_piece; }

float PartsWorker::get_weekly_wage() {
  return number_of_pieces * price_per_piece;
}
PartsWorker* PartsWorker::construct_from_user_input(std::ostream &cout, std::istream &cin) {
  std::cout << "Ingrese el número de piezas y el precio por cada pieza" << std::endl;
  int number_of_pieces; 
  float price_per_piece;
  std::cout << "Número de piezas: ";
  std::cin >> number_of_pieces;
  std::cout << "Precio por pieza: $";
  std::cin >> price_per_piece;
  PartsWorker* parts_worker = new PartsWorker(number_of_pieces, price_per_piece);
  std::cout << "El sueldo semanal del trabajador es: $" << parts_worker->get_weekly_wage() << std::endl;
  return parts_worker;
}



