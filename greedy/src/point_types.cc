// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include "point_types.h"

#include <iomanip>

std::ostream& operator<<(std::ostream& os, const CyA::PointVector& point_vector) {
  os << point_vector.size() << std::endl;
  for (const CyA::Point &point : point_vector) {
    os << point << std::endl;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::Point& point) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << point.first << "\t" 
  << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << point.second;
  return os;
}

std::istream& operator>>(std::istream& is, CyA::PointVector& point_vector) {
  int n;
  is >> n;
  point_vector.clear();
  for (int i = 0; i < n; ++i) {
    CyA::Point point;
    is >> point;
    point_vector.push_back(point);
  }
  return is;
}

std::istream& operator>>(std::istream& is, CyA::Point& point) {
  is >> point.first >> point.second;
  return is;
}