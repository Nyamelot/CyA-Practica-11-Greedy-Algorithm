// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "point_types.h"

void Usage(int argc, char* argv[]);
std::vector<std::vector<std::string>> FileReader(std::ifstream& input_files);
CyA::PointVector TextToPoint(const std::vector<std::vector<std::string>>& text_point);

