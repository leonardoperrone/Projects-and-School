#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <string>
#include "commodity.hpp"

class Product : public Commodity    //to Commodity, adds how to produce this product
{
 public:
   //constructor and destructor
   Product(std::string name, int base_val, int ingredient1, 
           int ingredient2, int ingredient3, int ratio1, int ratio2, 
           int ratio3, int production_time);
   virtual ~Product();

   //accessors
   int prod_time(void) const;
   std::vector<Commodity*> recipe(void) const;
   std::vector<int> ingredients(void) const;
   std::vector<int> ratio(void) const;
   virtual void print_all(void) const;
   virtual void build_print(void) const;

   //mutators
   virtual void fill_components(std::vector<Commodity*> components_list); //converts file data into pointers

 private:
   int m_prod_time;	//number of weeks it takes to produce one of the product
   std::vector<Commodity*> m_recipe;  //stores the commodities needed to build the product
   std::vector<int> m_ingredients;    //stores the commodity numbers for the recipe
   std::vector<int> m_ratio;	      //stores the ratio of the commodities for the recipe
};

#endif /* PRODUCT_HPP_ */
