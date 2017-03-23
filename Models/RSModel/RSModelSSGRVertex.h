// -*- C++ -*-
//
// RSModelSSGRVertex.h is a part of Herwig - A multi-purpose Monte Carlo event generator
// Copyright (C) 2002-2011 The Herwig Collaboration
//
// Herwig is licenced under version 2 of the GPL, see COPYING for details.
// Please respect the MCnet academic guidelines, see GUIDELINES for details.
//
#ifndef HERWIG_RSModelSSGRVertex_H
#define HERWIG_RSModelSSGRVertex_H
//
// This is the declaration of the RSModelSSGRVertex class.

#include "ThePEG/Helicity/Vertex/Tensor/SSTVertex.h"
#include "RSModel.h"

namespace Herwig {
using namespace ThePEG;
    
/** \ingroup Helicity
 * 
 *  The RSModelSSGRVertex class is thew implementation of the graviton
 *  coupling to the Higgs in the RSModel. It inherits from the SSTVertex 
 *  and implements the setCoupling member
 *
 *  @see SSTVertex
 *  @see VertexBase
 */
class RSModelSSGRVertex: public SSTVertex {
  
public:
  
  /**
   * Default constructor.
   */
  RSModelSSGRVertex();
    
  /** @name Functions used by the persistent I/O system. */
  //@{
  /**
   * Function used to write out object persistently.
   * @param os the persistent output stream written to.
   */
  void persistentOutput(PersistentOStream & os) const;

  /**
   * Function used to read in object persistently.
   * @param is the persistent input stream read from.
   * @param version the version number of the object when written.
   */
  void persistentInput(PersistentIStream & is, int version);
  //@}
  
  /**
   * Standard Init function used to initialize the interfaces.
   */
  static void Init();
  
  /**
   * Calculate the couplings. 
   * @param q2 The scale \f$q^2\f$ for the coupling at the vertex.
   * @param part1 The ParticleData pointer for the first  particle.
   * @param part2 The ParticleData pointer for the second particle.
   * @param part3 The ParticleData pointer for the third  particle.
   */
  virtual void setCoupling(Energy2 q2,tcPDPtr part1,tcPDPtr part2,tcPDPtr part3);

protected:
  
  /** @name Clone Methods. */
  //@{
  /**
   * Make a simple clone of this object.
   * @return a pointer to the new object.
   */
  virtual IBPtr clone() const {return new_ptr(*this);}

  /** Make a clone of this object, possibly modifying the cloned object
   * to make it sane.
   * @return a pointer to the new object.
   */
  virtual IBPtr fullclone() const {return new_ptr(*this);}
  //@}

protected:
  
  /**
   * Initialize this object after the setup phase before saving and
   * EventGenerator to disk.
   * @throws InitException if object could not be initialized properly.
   */
  virtual void doinit();
    
private:
  
  /**
   * Describe a concrete class with persistent data.
   */
  static ClassDescription<RSModelSSGRVertex> initRSModelSSGRVertex;
  
  /**
   * Private and non-existent assignment operator.
   */
  RSModelSSGRVertex & operator=(const RSModelSSGRVertex &);

  /**
   * Coupling.
   */
  InvEnergy kappa_;
};

}

namespace ThePEG {

/** @cond TRAITSPECIALIZATIONS */
  
/**
 * The following template specialization informs ThePEG about the
 * base class of RSModelSSGRVertex.
 */
template <>
struct BaseClassTrait<Herwig::RSModelSSGRVertex,1> {
  /** Typedef of the base class of RSModelSSGRVertex. */
  typedef ThePEG::Helicity::SSTVertex NthBase;
};

/**
 * The following template specialization informs ThePEG about the
 * name of this class and the shared object where it is defined.
 */
template <>
struct ClassTraits<Herwig::RSModelSSGRVertex>
  : public ClassTraitsBase<Herwig::RSModelSSGRVertex> {

  /**
   * Return the class name.
   */
  static string className() { return "Herwig::RSModelSSGRVertex"; }

  /** 
   * Return the name of the shared library to be loaded to get
   * access to this class and every other class it uses
   * (except the base class).
   */
  static string library() { return "HwRSModel.so"; }

};

/** @endcond */
  
}


#endif /* HERWIG_RSModelSSGRVertex_H */
