#ifndef REFINE_ORDER_HPP_
#define REFINE_ORDER_HPP_

#include "order.hpp"
#include "raw_material.hpp"

class RefineOrder : public Order //class for refine orders to produce raw materials
{
 public:
   //constructor and destructor
   RefineOrder(int time, int quantity, RawMaterial *material);
   ~RefineOrder();

   //accessors
   RawMaterial* material(void) const;

   //mutators
   int pass_time(int num_of_weeks);    //subtracts from timer, and adds order's quantity to the commodities' quantities with the proper ratio when timer reaches 0

 private:
   RawMaterial *m_material;  //what material is being refined by this order
};

#endif /* REFINE_HPP_ */
