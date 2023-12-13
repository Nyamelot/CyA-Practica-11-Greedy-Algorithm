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
#include <cstring>

#include "file_reader.h"
#include "point_set.h"
#include "point_types.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_points(argv[1]);
  bool d_option = false;
  if (argc == 3) {
    if (std::string(argv[2]) == "-d") {
      d_option = true;
    } else {
      std::cerr << "Wrong option, try --help for more information" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  std::vector<std::vector<std::string>> text_points = FileReader(input_points);
  CyA::PointVector points = TextToPoint(text_points);
  PointSet euclidean_tree(points);
  euclidean_tree.EMST();
  if (d_option) {
    std::string output_name = "output.dot";
    std::ofstream output_dot(output_name);
    if (output_dot.is_open()) {
      euclidean_tree.WriteDot(output_dot);
      output_dot.close();
    } else {
      std::cerr << "Error opening file: " << output_name << std::endl;
    }
  } else {
    std::string output_name = "output.txt";
    std::ofstream output_txt(output_name);
    if (output_txt.is_open()) {
      euclidean_tree.WriteTree(output_txt);
      output_txt.close();
    } else {
      std::cerr << "Error opening file: " << output_name << std::endl;
    }
  }
  return 0;
}
