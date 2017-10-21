#ifndef COMMODITY_HPP_
#define COMMODITY_HPP_

#include <string>
#include <vector>

class Commodity	//base class, stores the name of the commodity and its value
{
 public:
   //constructor and destructor
   Commodity(std::string name, int base_val);
   virtual ~Commodity();

   //accessors
   std::string name(void) const;
   int base_val(void) const;
   int quantity(void) const;

   //print functions
   virtual void print_all(void) const; //prints all the data stored in the class. used for debugging the file loader
   void buy_print(void) const;	//prints information for the buy menu
   void sell_print(void) const;	//prints information for the sell menu
   virtual void build_print(void) const;//prints information for the build/refine menu

   //mutators
   void add_quantity(int num_add);		//adds to m_quantity
   void sub_quantity(int num_sub);		//subtracts from m_quantity
   virtual void fill_components(std::vector<Commodity*> components_list);	//takes the data from the file and converts it to usable data. Used for derived classes only

 protected:
   std::string m_name;
   int m_base_val;
   int m_quantity;
};

#endif /* COMMODITY_HPP_ */
