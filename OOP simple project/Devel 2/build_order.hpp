#ifndef BUILD_ORDER_HPP_
#define BUILD_ORDER_HPP_

#include "order.hpp"
#include "product.hpp"

class BuildOrder : public Order   //class for build orders to produce products
{
 public:
   //constructor and destructor
   BuildOrder(int time, int quantity, Product *product);
   ~BuildOrder();

   //accessors
   Product* product(void) const;

   //mutators
   int pass_time(int num_of_weeks);	//subtracts from timer, and adds order's quantity to the products quantity when timer reaches 0

 private:
   Product *m_product;  //what product this order is producing
};

#endif /* ORDER_HPP_ */
