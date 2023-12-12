// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include <fstream>
#include <optional>
#include <string>
#include <vector>

#include "file_reader.h"
#include "point_set.h"
#include "point_types.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_points(argv[1]);
  std::string d_option = argv[2];
  std::vector<std::vector<std::string>> text_points = FileReader(input_points);
  for(const auto& line : text_points) {
    for(const auto& character : line) {
      std::cout << character << std::endl;
    }
  }
  CyA::PointVector points = TextToPoint(text_points);
  PointSet euclidean_tree(points);
  euclidean_tree.EMST();
  if (!d_option.empty()) {
    std::string output_name = "output.dot";
    std::ofstream output_dot(output_name);
    if (output_dot.is_open()) {
      euclidean_tree.WriteDot(output_dot);
      output_dot.close();
    } else {
      std::cerr << "Error opening file: " << output_name << std::endl;
    }
  } else {
    euclidean_tree.WriteTree(std::cout);
  }
  return 0;
}
