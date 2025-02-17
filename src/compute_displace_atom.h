/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   LAMMPS development team: developers@lammps.org

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS
// clang-format off
ComputeStyle(displace/atom,ComputeDisplaceAtom);
// clang-format on
#else

#ifndef LMP_COMPUTE_DISPLACE_ATOM_H
#define LMP_COMPUTE_DISPLACE_ATOM_H

#include "compute.h"

namespace LAMMPS_NS {

class ComputeDisplaceAtom : public Compute {
 public:
  ComputeDisplaceAtom(class LAMMPS *, int, char **);
  ~ComputeDisplaceAtom() override;
  void init() override;
  void compute_peratom() override;
  void set_arrays(int) override;
  void refresh() override;
  double memory_usage() override;

 private:
  int nmax;
  double **displace;
  char *id_fix;
  class FixStore *fix;

  int refreshflag, ivar, nvmax;    // refresh option is enabled
  char *rvar;                      // for incremental dumps
  double *varatom;
};

}    // namespace LAMMPS_NS

#endif
#endif
