#include "../header/figura-geometrica.h"

int FiguraGeometrica::contador_de_figuras = 0;

FiguraGeometrica::FiguraGeometrica() {
  FiguraGeometrica::contador_de_figuras++;
}

