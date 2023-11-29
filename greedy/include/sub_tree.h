// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#ifndef SUB_TREE_H_
#define SUB_TREE_H_

#include <iostream>
#include <cmath>

#include "point_types.h"

namespace EMST {
  class SubTree {
   public:
    // Constructor
    SubTree(void);
    ~SubTree(void);

    // Methods
    void AddArc(const CyA::Arc &arc);
    void AddPoint(const CyA::Point &point);
    bool Contains(const CyA::Point &point) const;
    void Merge(const SubTree &sub_tree, const CyA::WeighthedArc &arc);
    
    // Getters
    inline const CyA::Tree& GetArcs(void) const { return arcs_; }
    inline double GetCost(void) const { return cost_; }

   private:
    CyA::Tree arcs_;
    CyA::PointCollection points_;
    double cost_;
  };

  using sub_tree_vector = std::vector<SubTree>;
}

#endif
