#include <vector>
#include <string>
#include <iostream>
#include "product.hpp"

//constructor and destructor
Product::Product(std::string name, int base_val, int ingredient1,
		int ingredient2, int ingredient3, int ratio1, int ratio2,
		int ratio3, int production_time) : Commodity(name, base_val),
		m_prod_time(production_time)
{
   // The pointers to the commodities in each CommodityDependency are set
   // to NULL here and later set to the necessary values by fill_components
   m_recipe.push_back(CommodityDependency(NULL, ingredient1, ratio1));
   m_recipe.push_back(CommodityDependency(NULL, ingredient2, ratio2));
   m_recipe.push_back(CommodityDependency(NULL, ingredient3, ratio3));
}

Product::~Product()
{ }

//accessors
int Product::prod_time(void) const
{
   return m_prod_time;
}

Commodity* Product::get_recipe(int i) const
{
   return m_recipe[i].commodity;
}

int Product::get_ingredient(int i) const
{
   return m_recipe[i].number;
}

int Product::get_ratio(int i) const
{
   return m_recipe[i].ratio;
}

// private mutator
void Product::set_recipe(int i, Commodity* c)
{
   m_recipe[i].commodity = c;
}

//print functions
void Product::print_all(void) const
{
   std::cout << "Product name: " << m_name << ", val: " << m_base_val 
             << ", ingredients: " << get_ingredient(0) 
             << ", " << get_ingredient(1) << ", " << get_ingredient(2) 
             << ", ratios: " 
             << get_ratio(0) << ", " << get_ratio(1) << ", " << get_ratio(2) 
             << ", prodtime: " << m_prod_time << std::endl;
}

void Product::build_print(void) const
{
   std::cout << m_name;
   std::cout.width(30-m_name.size());
   std::cout << "Requires: " << get_ratio(0) << " units of " 
             << get_recipe(0)->name() << ", ";
   if (get_ingredient(1) > 0)
   {
      std::cout << get_ratio(1) << " units of " << get_recipe(1)->name() 
                << ", ";
      if (get_ingredient(2) > 0)
         std::cout << get_ratio(2) << " units of " << get_recipe(2)->name() 
                   << ", ";
   }
   std::cout << "and " << m_prod_time << " weeks." << std::endl;
}

//mutator
void Product::fill_components(std::vector<Commodity*> components_list)
{
   set_recipe(0, components_list[get_ingredient(0)-1]);
   if (get_ingredient(1) >= 0)
   {
      set_recipe(1, components_list[get_ingredient(1)-1]);
      if (get_ingredient(2) >= 0)
         set_recipe(2, components_list[get_ingredient(2)-1]);
   }
}
