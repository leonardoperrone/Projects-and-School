#ifndef ORDER_HPP_
#define ORDER_HPP_

class Order		//base class for all types of orders
{
 public:
   //constructor and destructor
   Order(int time, int quantity);
   ~Order();

   //accessors
   int timer(void) const;
   int quantity(void) const;

   //mutators
   virtual int pass_time(int num_of_weeks) = 0;	//subtract one time unit from
                                                //timer; add commodities
                                                //produced when timer reaches 0

 protected:
   void set_timer(int time);

 private:
   int m_timer;	        //time left before order is completed
   int m_quantity;	//how many goods are being produced in this order
};

#endif /* ORDER_HPP_ */
