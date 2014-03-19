/*****************************************/
/* Written by andrew.wilkins@csiro.au    */
/* Please contact me if you make changes */
/*****************************************/

//  "Monomial" form of relative permeability
//
#ifndef RICHARDSRELPERMMONOMIAL_H
#define RICHARDSRELPERMMONOMIAL_H

#include "RichardsRelPerm.h"

class RichardsRelPermMonomial;


template<>
InputParameters validParams<RichardsRelPermMonomial>();

/**
 * Monomial form of relative permeability
 * relperm = Seff^n for 0<Seff<=1, where S = (S - simm)/(1 - simm)
 * relperm = 1 for Seff>1
 * relperm = 0 for Seff<0, except if n=0 then relperm = zero_to_the_zero
 */
class RichardsRelPermMonomial : public RichardsRelPerm
{
 public:
  RichardsRelPermMonomial(const std::string & name, InputParameters parameters);

  /**
   * Relative permeability
   */
  Real relperm(Real seff) const;

  /**
   * Derivative of elative permeability wrt seff
   */
  Real drelperm(Real seff) const;

  /**
   * Second derivative of elative permeability wrt seff
   */
  Real d2relperm(Real seff) const;

 protected:

  /// immobile saturation
  Real _simm;
  /// exponent, must be >= 0
  Real _n;
  /// 0^0, which is used if _n=0
  Real _zero_to_the_zero;

};

#endif // RICHARDSRELPERMMONOMIAL_H