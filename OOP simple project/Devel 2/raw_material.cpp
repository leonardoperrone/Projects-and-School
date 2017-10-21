#include <string>
#include <vector>
#include <iostream>
#include "raw_material.hpp"

//constructor
RawMaterial::RawMaterial(std::string name, int base_val, int component1,
		int component2, int component3, int ratio1, int ratio2, 
                int ratio3, int mine_price, int mine_production) :
		Commodity(name, base_val), m_mine_price(mine_price), 
                m_mine_production(mine_production), m_mine_level(0)
{
   // The pointers to the commodities in each CommodityDependency are set
   // to NULL here and later set to the necessary values by fill_components
   m_yields.push_back(CommodityDependency(NULL, component1, ratio1));
   m_yields.push_back(CommodityDependency(NULL, component2, ratio2));
   m_yields.push_back(CommodityDependency(NULL, component3, ratio3));
}

//destructor
RawMaterial::~RawMaterial(void)
{ }

//accessors
Commodity* RawMaterial::get_yield(int i) const
{
   return m_yields[i].commodity;
}

int RawMaterial::get_component(int i) const
{
   return m_yields[i].number;
}

int RawMaterial::get_ratio(int i) const
{
   return m_yields[i].ratio;
}

int RawMaterial::mine_level(void) const
{
   return m_mine_level;
}

int RawMaterial::mine_price(void) const
{
   return m_mine_price;
}

int RawMaterial::mine_production(void) const
{
   return m_mine_production;
}

// private mutator
void RawMaterial::set_yield(int i, Commodity* c)
{
   m_yields[i].commodity = c;
}

// print functions
void RawMaterial::print_all(void) const
{
   std::cout << "Raw Material name: " << m_name << ", val:" << m_base_val 
             << ", components: " << get_component(1) << ", "
             << get_component(1) << ", " << get_component(2) << ", ratios: " 
             << get_ratio(0) << ", " << get_ratio(1) << ", " << get_ratio(2) 
             << std::endl;
}

void RawMaterial::build_print(void) const
{
   std::cout << m_name;
   std::cout.width(30-m_name.size());
   std::cout << "Yeilds: " << get_ratio(0) << " units of " << get_yield(0)->name();
   if (get_component(1) > 0)
   {
      std::cout << ", " << get_ratio(1) << " units of " << get_yield(1)->name();
      if (get_component(2) > 0)
         std::cout << ", " << get_ratio(2) << " units of " << get_yield(2)->name();
   }
   std::cout << ", and will take 1 week per 5 units of " << m_name 
             << " refined." << std::endl;
}

//mutators
void RawMaterial::fill_components(std::vector<Commodity*> components_list)
{
   set_yield(0, components_list[get_component(0)-1]);
   if (get_component(1) >= 0)
   {
      set_yield(1, components_list[get_component(1)-1]);
      if (get_component(2) >= 0)
         set_yield(2, components_list[get_component(2)-1]);
   }
}

void RawMaterial::upgrade_mine(void)
{
   m_mine_level++;
}



