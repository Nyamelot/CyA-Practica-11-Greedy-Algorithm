// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include "point_set.h"
#include "sub_tree.h"
#include "point_types.h"

void PointSet::EMST(void) {
  CyA::ArcVector arc_vector;
  ComputeArcVector(arc_vector);
  forest sub_tree_vector;
  for (const CyA::Point &p : *this) {
    EMST::SubTree s;
    s.AddPoint(p);
    sub_tree_vector.push_back(s);
  }
  for (const CyA::WeighthedArc &a : arc_vector) {
    int i, j;
    FindIncidentSubtrees(sub_tree_vector, a.second, i, j);
    if (i != j) {
      MergeSubtrees(sub_tree_vector, a.second, i, j);
    }
  }
  emst_ = sub_tree_vector[0].GetArcs();
}