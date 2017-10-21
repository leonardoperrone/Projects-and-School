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
   std::vector<Commodity*> yeilds(void) const;
   std::vector<int> components(void) const;
   std::vector<int> ratio(void) const;
   int mine_level(void) const;
   int mine_price(void) const;
   int mine_production(void) const;
   virtual void print_all(void) const;
   void build_print(void) const;

   //mutators
   virtual void fill_components(std::vector<Commodity*> components_list);	//converts file data into pointers
   void upgrade_mine(void);

 protected:
   std::vector<Commodity*> m_yeilds;  //stores pointers to the commodities that the raw material refines into
   std::vector<int> m_components;     //stores the commodity number for the yeilds, used for file reading
   std::vector<int> m_ratio;	      //stores the ratios for refining
   int m_mine_level;
   int m_mine_price;
   int m_mine_production;
};

#endif /* RAW_MATERIAL_HPP_ */
