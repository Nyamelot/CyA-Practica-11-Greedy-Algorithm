// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>

#include "sub_tree.h"

namespace EMST {
  SubTree::SubTree(void) : arcs_(), points_(), cost_(0) {}

  SubTree::~SubTree(void) {}

  /**
   * @brief The method will add an arc to the sub tree
   * 
   * @param arc 
   */
  void SubTree::AddArc(const CyA::Arc &arc) {
    arcs_.push_back(arc);
    points_.insert(arc.first);
    points_.insert(arc.second);
  }


  /**
   * @brief The method will add a point to the sub tree
   * 
   * @param point 
   */
  void SubTree::AddPoint(const CyA::Point &point) {
    points_.insert(point);
  }

  /**
   * @brief The method will confirm if a given point exist within the sub tree
   * 
   * @param point 
   * @return true 
   * @return false 
   */
  bool SubTree::Contains(const CyA::Point &point) const {
    return points_.find(point) != points_.end();
  }


  /**
  * @brief The Method will merge the invoker and a given sub tree
  * 
  * @param sub_tree 
  * @param weight_arc 
  */
  void SubTree::Merge(const SubTree &sub_tree, const CyA::WeighthedArc &weight_arc) {
    arcs_.insert(arcs_.end(), sub_tree.arcs_.begin(), sub_tree.arcs_.end());
    arcs_.push_back(weight_arc.second);
    points_.insert(sub_tree.points_.begin(), sub_tree.points_.end());
    points_.insert(weight_arc.second.first);
    points_.insert(weight_arc.second.second);
    cost_ += weight_arc.first + sub_tree.GetCost();
  }
}
