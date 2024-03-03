#ifndef RECTANGULO_H
#define RECTANGULO_H

float clamp(float, float, float);

class Rectangulo {
  private:
    float longitud = 1.0f;
    float anchura = 1.0f;

    int id;

  public:
    
    static int contador_de_rectangulos;

    Rectangulo(float, float);
    Rectangulo();
    ~Rectangulo();

    void set_longitud(float);
    void set_anchura(float);

    float get_longitud();
    float get_anchura();

    float get_perimetro();
    float get_area();

    void imprimir_datos();
};

#endif // !RECTANGULO_H
