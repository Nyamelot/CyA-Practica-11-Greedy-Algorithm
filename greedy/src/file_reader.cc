// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <optional>
#include <exception>

#include "point_types.h"
#include "file_reader.h"

const std::string kTitle = "P011-Greedy-Algorithm";
const std::string kHelpText =
"  \n\033[1m>> Example:\033[0m"\
"    ./a.out input.txt -d\n"\
  
"  \033[1m>> Parameters:\033[0m\n"\
"     - \033[1minput.txt:\033[0m is the file with the points to be input\n"\
"     - \033[1m-d:\033[0m is an option to generate a file in graphviz format\n"\
  
"  \033[1m>> Output:\033[0m\n"\
"    The program will output the result an Euclidian Minimum Spanning Tree"\
" of the input points.\n";


void Usage(int argc, char* argv[]) {
  const std::string kHelp = "--help";
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.txt -d"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) {
    std::cout << kTitle << std::endl;
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc > 3) || ((argc < 2))) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.txt -d"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}


// CyA::PointVector FileReader(std::ifstream& input_files) {
//   CyA::PointVector points;
//   std::string text_line;
//   std::getline(input_files, text_line);
//   int points_amount = stoi(text_line);
//   while (!input_files.eof()) {
//     std::getline(input_files, text_line);
//     std::stringstream number;
//     std::optional<double> point_x;
//     std::optional<double> point_y;
//     for (const auto& character : text_line) {
//       if (character == ' ') {
//         number.seekp(0, std::ios::end);
//         auto offset = number.tellp();
//         if (offset != 0) {
//           if (!point_x.has_value()) {
//             double aux;
//             number >> aux;
//             point_x = aux;
//           } else if (!point_y.has_value()) {
//             double aux;
//             number >> aux;
//             point_y = aux;
//           } else {
//             throw std::runtime_error("Invalid Input File Format");
//           }
//         } else {
//           continue;
//         }
//       }
//       if (std::isdigit(character)) {
//         number << character;
//         continue;
//       }
//       points.emplace_back(point_x.value(), point_y.value());
//     }
//   }
//   return points;
// }

std::vector<std::string> Split(const std::string& input_string, const char querry_char) {
  std::vector<std::string> characters;
  std::stringstream character;
  for (char symbol : input_string) {
    if (symbol != querry_char) {
      character << symbol;
      continue;
    }
    characters.emplace_back(character.str());
    character.str(std::string());
  }
  characters.emplace_back(character.str());
  return characters;
}

std::vector<std::vector<std::string>> FileReader(std::ifstream& input_files) {
  std::vector<std::vector<std::string>> text_file;
  std::string text_line;
  while (!input_files.eof()) {
    std::getline(input_files, text_line);
    text_file.emplace_back(Split(text_line, ' '));
  }
  return text_file;
}

CyA::PointVector TextToPoint(const std::vector<std::vector<std::string>>& text_point) {
  CyA::PointVector points;
  int point_amount = stoi(text_point[0][0]);
  for (int i = 1; text_point.size(); i++) {
    points.emplace_back(std::stod(text_point[i][0]), std::stod(text_point[i][1]));
  }
  if(points.size() < point_amount) {
    std::cerr << "The input points are less than expected" << std::endl;
    exit(EXIT_FAILURE);
  } else if (points.size() > point_amount) {
    std::cerr << "The input points are more than expected" << std::endl;
    exit(EXIT_FAILURE);
  } else {
    return points;
  }
}
