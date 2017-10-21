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
   Commodity* get_recipe(int i) const;
   int get_ingredient(int i) const;
   int get_ratio(int i) const;
   virtual void print_all(void) const;
   virtual void build_print(void) const;

   //mutators
   virtual void fill_components(std::vector<Commodity*> components_list); //converts file data into pointers

 private:
   // private mutator
   void set_recipe(int i, Commodity* c);

   // data
   int m_prod_time;	//number of weeks it takes to produce one of the product

   std::vector<CommodityDependency> m_recipe;
   // The structure CommodityDependency is used to store information about
   // each Commodity needed to build this Product as follows:
   //    commodity: points to commodity (was m_recipe)
   //    number: how many of commodity are needed to make product (was m_ingredients)
   //    ratio: the ratio of ... (was m_ratio)

};

#endif /* PRODUCT_HPP_ */
