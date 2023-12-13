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
#include <map>
#include <set>

#include "point_set.h"
#include "sub_tree.h"
#include "point_types.h"

/**
 * @brief The method will realize the algorithm euclidean minimum spanning tree
 * 
 */
void PointSet::EMST(void) {
  CyA::ArcVector arc_vector;
  ComputeArcVector(arc_vector);
  int eliminated_arcs = arc_vector.size();
  forest sub_tree_vector;
  for (const CyA::Point &point : points_) {
    EMST::SubTree sub_tree;
    sub_tree.AddPoint(point);
    sub_tree_vector.push_back(sub_tree);
  }
  for (const CyA::WeighthedArc &weight_arc : arc_vector) {
    int i, j;
    FindIncidentSubtrees(sub_tree_vector, weight_arc.second, i, j);
    if (i != j) {
      MergeSubtrees(sub_tree_vector, weight_arc.second, i, j);
      eliminated_arcs--;
    }
  }
  std::cout << "The eliminated arcs are: " <<eliminated_arcs << std::endl;
  emst_ = sub_tree_vector[0].GetArcs();
}


/**
 * @brief The method will create an arc vector using the vector of points of the class
 * 
 * @param arc_vector 
 */
void PointSet::ComputeArcVector(CyA::ArcVector &arc_vector) const {
  arc_vector.clear();
  const int n = points_.size();
  for (int i = 0; i < n - 1; ++i) {
    const CyA::Point &point_i = points_[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::Point &point_j = points_[j];
      const double dist = EuclideanDistance(std::make_pair(point_i, point_j));
      arc_vector.push_back(std::make_pair(dist, std::make_pair(point_i, point_j)));
    }
  }
  std::sort(arc_vector.begin(), arc_vector.end());
}


/**
 * @brief The method will calculate the euclidean distance
 * 
 * @param arc 
 * @return double 
 */
double PointSet::EuclideanDistance(const CyA::Arc& arc) const {
  double euclidean_distance = sqrt((pow(arc.second.first - arc.first.first, 2)) + (pow(arc.second.second - arc.first.second, 2)));
  return euclidean_distance;
}


/**
 * @brief The method given an arc will find if any of it´s points is contained in any of the sub trees of forest
 * 
 * @param forest 
 * @param arc 
 * @param i 
 * @param j 
 */
void PointSet::FindIncidentSubtrees(const forest& forest, const CyA::Arc &arc, int& i, int& j) const {
  i = -1;
  j = -1;
  for (int k = 0; 0 < forest.size(); k++) {
    if (forest[k].Contains(arc.first)) {
      i = k;
    }
    if (forest[k].Contains(arc.second)) {
      j = k;
    }
    if (i != -1 && j != -1) break;
  }
}


/**
 * @brief The method will merge sub trees given two points
 * 
 * @param forest 
 * @param arc 
 * @param i 
 * @param j 
 */
void PointSet::MergeSubtrees(forest& forest, const CyA::Arc &arc, int i, int j) const {
  forest[i].Merge(forest[j], std::pair(EuclideanDistance(arc), arc));
  forest.erase(forest.begin() + j);
}


/**
 * @brief The method will calculate the cost of the tree
 * 
 * @return double 
 */
double PointSet::ComputeCost(void) const {
  double cost = 0;
  for (const auto& arc : emst_) {
    cost = cost + EuclideanDistance(arc);
  }
  return cost;
}


/**
 * @brief The method will print the tree with it´s cost
 * 
 * @param os 
 */
void PointSet::WriteTree(std::ostream &os) const {
  for(const auto& arc : emst_) {
    os << "(" << arc.first.first << ", " << arc.first.second << ") -> ("
    << arc.second.first << ", " << arc.second.second << ") \n";   
  }
  os << "\n";
  os << ComputeCost() << "\n";
}


/**
 * @brief The method will print the tree in graphviz style
 * 
 * @param os 
 */
void PointSet::WriteDot(std::ostream &os) const {
  os << "graph { \n";
  std::map<CyA::Point, int> point_ids;
  std::set<CyA::Point> point_collection;
  for (const auto& arc : emst_) {
    point_collection.emplace(arc.first);
    point_collection.emplace(arc.second);
  }
  int i = 0;
  for (const auto& point : point_collection) {
    os << i << "[pos=\"" << point.first << "," << point.second << "!\"]\n";
    point_ids.emplace(point, i);
    i++;
  }
  for (const auto& arc : emst_) {
    os << point_ids.at(arc.first) << "--" << point_ids.at(arc.second) << "\n";
  }
  os << "}\n";
  os.flush();
}
