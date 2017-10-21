#ifndef RAW_MATERIAL_HPP_
#define RAW_MATERIAL_HPP_

#include <string>
#include <vector>
#include "commodity.hpp"

class RawMaterial : public Commodity	//to Commodity, adds what this material gets refined into, and mine info
{
 public:
   //constructor and destructor
   RawMaterial(std::string name, int base_val, int component1, 
               int component2, int component3, int ratio1, int ratio2, 
               int ratio3, int mine_price, int mine_production);
   virtual ~RawMaterial();

   //accessors
   Commodity* get_yield(int i) const;
   int get_component(int i) const;
   int get_ratio(int i) const;
   int mine_level(void) const;
   int mine_price(void) const;
   int mine_production(void) const;
   virtual void print_all(void) const;
   void build_print(void) const;

   //mutators
   virtual void fill_components(std::vector<Commodity*> components_list);	//converts file data into pointers
   void upgrade_mine(void);

 private:
   // private mutator
   void set_yield(int i, Commodity* c);

   // data
   std::vector<CommodityDependency> m_yields;
   // The structure CommodityDependency is used to store information about
   // each Commodity that this RawMaterial get refined into as follows:
   //    commodity: points to commodity (was m_yields)
   //    number: how many items of commodity are produced by one unit of
   //            raw material (was m_components)
   //    ratio: the ratio of ... (was m_ratio)

   int m_mine_level;
   int m_mine_price;
   int m_mine_production;
};

#endif /* RAW_MATERIAL_HPP_ */
