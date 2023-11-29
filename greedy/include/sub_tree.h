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
    void AddArc(const CyA::arc &arc);
    void AddPoint(const CyA::point &point);
    bool Contains(const CyA::point &point) const;
    void Merge(const SubTree &sub_tree, const CyA::weigthed_arc &arc);
    
    // Getters
    inline const CyA::tree& GetArcs(void) const { return arcs_; }
    inline double GetCost(void) const { return cost_; }

   private:
    CyA::tree arcs_;
    CyA::point_collection points_;
    double cost_;
  };

  typedef std::vector<SubTree> sub_tree_vector;
}

#endif