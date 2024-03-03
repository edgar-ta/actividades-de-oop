#include <cstdlib>
#include <iostream>

#include "header/punto.h"
#include "header/circulo.h"
#include "header/cilindro.h"

int main() {
    Cilindro cilindro(3, 4, 3, 2);
    cilindro.imprimir();

    std::cout << "El perímetro es: "    << cilindro.obtener_perimetro() << std::endl;
    std::cout << "El área es: "         << cilindro.obtener_area()      << std::endl;
    std::cout << "El volumen es: "      << cilindro.obtener_volumen()   << std::endl;

    return EXIT_SUCCESS;
}


class Circulo2 {
    protected:
    Punto centro;
    int radio;

    public:
    Circulo2(int x, int y, int radio) : centro(x, y), radio(radio) {};
    Circulo2(Punto centro, int radio) : centro(centro), radio(radio) {};
};

std::ostream& print_value(std::ostream& stream, int value) {
    return stream << value;
}

class WordContainer {
    protected:
    std::string source;

    public:
    WordContainer(const WordContainer& other): source(other.source) {}
    WordContainer(std::string source): source(source) {}

    class Iterator : std::iterator<std::input_iterator_tag, std::string> {
        protected:
        std::size_t index;
        const std::string& source;

        public:
        Iterator(const std::string& source): index(0), source(source) {}
        Iterator(const std::string& source, std::size_t index): index(index), source(source) {}
        Iterator(const WordContainer::Iterator& other): index(0), source(other.source) {}

        WordContainer::Iterator& operator++() {
            if (index >= source.length()) return *this;
            while (!std::isspace(source.at(index)) && (int) index < source.length()) {
                index++;
            }
            if (index >= source.length()) return *this;
            while (std::isspace(source.at(index)) && (int) index < source.length()) {
                index++;
            }
            return *this;
        }

        WordContainer::Iterator& operator++(int) {
            return operator++();
        }

        bool operator==(const WordContainer::Iterator& other) {
            return other.index == this->index && other.source == this->source;
        }

        bool operator!=(const WordContainer::Iterator& other) {
            return !operator==(other);
        }

        std::string operator*() {
            std::size_t end_index = index;
            while ((int) end_index < source.length()) {
                if (!std::isspace(source.at(index))) break;
                end_index++;
            }
            return source.substr(index, end_index - index);
        }
    };

    WordContainer::Iterator begin() const {
        return WordContainer::Iterator(this->source);
    }

    WordContainer::Iterator end() const {
        return WordContainer::Iterator(this->source, this->source.length());
    }
};

// int main() {
//     std::string something = "Hello world there is something going on here";
//     const WordContainer container(something);
//     for (auto word: container) {
//         std::cout << word << std::endl;
//     }

//     // Cilindro cilindro(3, 4, 3, 2);
//     // cilindro.imprimir();

//     // std::cout << "El perímetro es: "    << cilindro.obtener_perimetro() << std::endl;
//     // std::cout << "El área es: "         << cilindro.obtener_area()      << std::endl;
//     // std::cout << "El volumen es: "      << cilindro.obtener_volumen()   << std::endl;

//     return EXIT_SUCCESS;
// }
