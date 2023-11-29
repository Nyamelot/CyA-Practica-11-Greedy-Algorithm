// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA {
  using Point = std::pair<double, double>;

  using Line = std::pair<Point, Point>;
  using PointVector = std::vector<Point>;

  using Arc = std::pair<Point, Point>;
  using WeighthedArc = std::pair<double, Arc>;
  using ArcVector = std::vector<WeighthedArc>;

  using PointCollection = std::set<Point>;

  using Tree = std::vector<Arc>;
}

std::ostream& operator<<(std::ostream& os, const CyA::PointVector& point_vector);
std::ostream& operator<<(std::ostream& os, const CyA::Point& point);

std::istream& operator>>(std::istream& is, CyA::PointVector& point_vector);
std::istream& operator>>(std::istream& is, CyA::Point& point);
