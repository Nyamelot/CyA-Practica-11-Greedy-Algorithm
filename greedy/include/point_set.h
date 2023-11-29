// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo Voraz
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 29/11/2023

#ifndef POINT_SET_H_
#define POINT_SET_H_

#include <vector>
#include <iostream>

#include "point_types.h"
#include "sub_tree.h"

typedef std::vector<EMST::SubTree> forest;
  class point_set : public CyA::point_vector {
   public:
    // Constructor
    point_set(const CyA::point_vector &points);
    ~point_set(void);

    // Methods
    void EMST(void);

    // Operator Overloading
    void write_tree(std::ostream &os) const;
    void write(std::ostream &os) const;

    // Getters
    inline const CyA::tree& get_tree(void) const { return emst_; }
    inline const CyA::point_vector& get_points(void) const { return *this; }
    inline const double GetCost(void) const { return compute_cost(); }

   private:
    CyA::tree emst_;
    void compute_arc_vector(CyA::arc_vector &av) const;
    void find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const;
    void merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const;

    double compute_cost(void) const;

    double euclidean_distance(const CyA::arc& a) const;
  };

#endif
