// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include <algorithm>
#include <cmath>

#include "point_set.h"
#include "sub_tree.h"
#include "point_types.h"

void PointSet::EMST(void) {
  CyA::ArcVector arc_vector;
  ComputeArcVector(arc_vector);
  forest sub_tree_vector;
  for (const CyA::Point &point : *this) {
    EMST::SubTree sub_tree;
    sub_tree.AddPoint(point);
    sub_tree_vector.push_back(sub_tree);
  }
  for (const CyA::WeighthedArc &weight_arc : arc_vector) {
    int i, j;
    FindIncidentSubtrees(sub_tree_vector, weight_arc.second, i, j);
    if (i != j) {
      MergeSubtrees(sub_tree_vector, weight_arc.second, i, j);
    }
  }
  emst_ = sub_tree_vector[0].GetArcs();
}


void PointSet::ComputeArcVector(CyA::ArcVector &arc_vector) const {
  arc_vector.clear();
  const int n = size();
  for (int i = 0; i < n - 1; ++i) {
    const CyA::Point &point_i = (*this)[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::Point &point_j = (*this)[j];
      const double dist = EuclideanDistance(std::make_pair(point_i, point_j));
      arc_vector.push_back(std::make_pair(dist, std::make_pair(point_i, point_j)));
    }
  }
  std::sort(arc_vector.begin(), arc_vector.end());
}


double PointSet::EuclideanDistance(const CyA::Arc& arc) const {
  return sqrt((arc.second.first + arc.first.first) - (arc.second.second + arc.first.second));
}


void PointSet::FindIncidentSubtrees(const forest& forest, const CyA::Arc &arc, int& i, int& j) const {
  
}

void PointSet::MergeSubtrees(forest& forest, const CyA::Arc &arc, int i, int j) const {

}