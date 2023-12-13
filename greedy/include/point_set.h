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

using forest = std::vector<EMST::SubTree>;
  class PointSet : public CyA::PointVector {
   public:
    // Constructor
    PointSet(const CyA::PointVector &points) : points_(points) {}
    ~PointSet(void) = default;

    // Methods
    void EMST(void);

    // Operator Overloading
    void WriteTree(std::ostream &os) const;
    void Write(std::ostream &os) const;
    void WriteDot(std::ostream &os) const;

    // Getters
    inline const CyA::Tree& GetTree(void) const { return emst_; }
    inline const CyA::PointVector& GetPoints(void) const { return points_; }
    inline const double GetCost(void) const { return ComputeCost(); }

   private:
    CyA::Tree emst_;
    CyA::PointVector points_;
    void ComputeArcVector(CyA::ArcVector &arc_vector) const;
    void FindIncidentSubtrees(const forest& forest, const CyA::Arc &arc, int& i, int& j) const;
    void MergeSubtrees(forest& forest, const CyA::Arc &arc, int i, int j) const;

    double ComputeCost(void) const;

    double EuclideanDistance(const CyA::Arc& arc) const;
  };

#endif
