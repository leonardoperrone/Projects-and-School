#ifndef REFINE_HPP_
#define REFINE_HPP_

#include "raw_material.hpp"

class Refine	//class for refine orders to produce raw materials
{
 public:
   //constructor and destructor
   Refine(int time, int quantity, RawMaterial *material);
   ~Refine();

   //accessors
   int timer(void) const;
   int quantity(void) const;
   RawMaterial* material(void) const;

   //mutators
   int pass_time(int num_of_weeks);    //subtracts from timer, and adds order's quantity to the commodities' quantities with the proper ratio when timer reaches 0

 private:
   int m_timer;        	     //time left before order is completed
   int m_quantity;           //how many units of material are being refined
   RawMaterial *m_material;  //what material is being refined by this order
};

#endif /* REFINE_HPP_ */
