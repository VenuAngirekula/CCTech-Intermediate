#include "VendingMachine.H"
#include <sstream>
#include <cassert>

using namespace std;

void Testing_Acceptcoins(VendingMachine& VM, 
                            std::string coins);

void Testing_ItemSelection(VendingMachine& VM, std::string Insertedcoins,
                        std::string selecteditem);

float Testing_Dispatch_Reinsert_Makechange(VendingMachine& VM, std::string Insertedcoins,
                               std::string selecteditem);

float Testing_Repeat_itemSelection(VendingMachine& VM, std::string Insertedcoins,
                               std::string selecteditem);