#ifndef ORDER_HPP_
#define ORDER_HPP_

#include "product.hpp"

class Order		//class for build orders to produce products
{
 public:
   //constructor and destructor
   Order(int time, int quantity, Product *product);
   ~Order();

   //accessors
   int timer(void) const;
   int quantity(void) const;
   Product* product(void) const;

   //mutators
   int pass_time(int num_of_weeks);	//subtracts from timer, and adds order's quantity to the products quantity when timer reaches 0

 private:
   int m_timer;	        //time left before order is completed
   int m_quantity;	//how many goods are being produced in this order
   Product *m_product;  //what product this order is producing
};

#endif /* ORDER_HPP_ */
