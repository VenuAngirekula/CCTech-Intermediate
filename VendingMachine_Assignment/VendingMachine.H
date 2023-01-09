#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <algorithm>

class VendingMachine
{
    private:
        float _currentAmount = 0.0;

        int _Treasury_Nickels;
        int _Treasury_Dimes  ;
        int _Treasury_Quaters;
        std::array<int,3> _Treasury_Coins;
        
        std::unordered_map<std::string, float> _Rates = {
                {"COLA", 1},
                {"CHIPS", 0.5},
                {"CANDY", 0.65}
                };
        std::unordered_map<std::string, int> _Inventory = {
                {"COLA", 0},
                {"CHIPS", 0},
                {"CANDY", 0}
                };
        std::unordered_map<std::string, float> _CoinValue = {
                {"Nickel", 0.05},
                {"Dime", 0.1},
                {"Quater", 0.25}
                };
    
    public:
        std::array<int,3> _Entered_coins;
        std::array<int,3> _Return_coins;
        std::string _selectedItem;
        float _balanceAmount;

        VendingMachine();

        VendingMachine(int colaCount, int chipscount, int candycount);

        VendingMachine(std::array<int,3> Inventory);

        VendingMachine(std::array<int,3> Inventory, std::array<int,3> Treasury);

        ~VendingMachine();

        float coinToCurrency(std::array<int,3> coins);

        void SetInventory(std::array<int,3> Inventory);

        void SetTreasurycoins(std::array<int,3> InitialCoins);


        bool check_Treasury();

        bool ExactAmount_NotInserted();

        bool InsertCoins();

        void ProcessCoins(std::string s);

        void Makechange(float _balanceAmount,std::string whichcoins);

        std::pair <int, float> get_CoinsNeeded(float balanceAmount,std::string coinName);

        void PrintHeader();

        void Print_Inventory();

        std::string SelectItem();

        void Dispatch_Reinsert_Makechange();

        void ReInsertCoins();

        bool ReturnCoins();

        bool checkReturnCoins();

        void DispatchItem(std::string item);
        
        void CheckInventory(std::string item);

        void Execute();
        std::array<int,3> Add_Arrays(std::array<int,3> A, std::array<int,3> B);

};

#endif