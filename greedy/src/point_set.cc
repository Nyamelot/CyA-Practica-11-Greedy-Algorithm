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

void point_set::EMST(void)
    {
        CyA::arc_vector av;
        compute_arc_vector(av);

        forest st;

        for (const CyA::point &p : *this)
        {
            EMST::SubTree s;
            s.AddPoint(p);

            st.push_back(s);
        }

        for (const CyA::weigthed_arc &a : av)
        {
            int i, j;
            find_incident_subtrees(st, a.second, i, j);

            if (i != j)
            {
                merge_subtrees(st, a.second, i, j);
            }
        }

        emst_ = st[0].GetArcs();
    }