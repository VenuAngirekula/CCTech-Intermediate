#include "VendingMachine.H"

using namespace std;


/********************        Constructor      ***********************************/
VendingMachine::VendingMachine()
{
    SetInventory(std::array<int,3> {5, 5, 5});
    std::array<int,3> Default_Treasury = {5,5,5};
    SetTreasurycoins(Default_Treasury);
}

VendingMachine::VendingMachine(int colaCount, int chipscount,int candycount)
{
    SetInventory(std::array<int,3> {colaCount, chipscount, candycount});
    std::array<int,3> Default_Treasury = {5,5,5};
    SetTreasurycoins(Default_Treasury);
}

VendingMachine::VendingMachine(std::array<int,3> Initial_Inventory)
{    
    SetInventory(Initial_Inventory);
    std::array<int,3> Default_Treasury = {5,5,5};
    SetTreasurycoins(Default_Treasury);
}

VendingMachine::VendingMachine(std::array<int,3> Initial_Inventory,
                               std::array<int,3> Initial_Treasury)
{
    SetInventory(Initial_Inventory);
    SetTreasurycoins(Initial_Treasury);
}

void VendingMachine::SetInventory(std::array<int,3> Initial_Inventory)
{
    _Inventory["COLA"]  = Initial_Inventory[0]; 
    _Inventory["CHIPS"]  = Initial_Inventory[1]; 
    _Inventory["CANDY"]  = Initial_Inventory[2];  
}

void VendingMachine::SetTreasurycoins(std::array<int,3> Initial_Treasury)
{
    _Treasury_Nickels = Initial_Treasury[0];
    _Treasury_Dimes   = Initial_Treasury[1];
    _Treasury_Quaters = Initial_Treasury[2];
    _Treasury_Coins = Initial_Treasury;
}
void VendingMachine::Execute()
{
    PrintHeader();
    InsertCoins();
    SelectItem();
    Dispatch_Reinsert_Makechange();
}
bool VendingMachine::check_Treasury()
{
    if (_Treasury_Nickels == 0 || _Treasury_Dimes == 0){
        cout << "Enter Exact amount" << endl;  
        return true;
    }
    return false;
}

bool VendingMachine::ExactAmount_NotInserted()
{
    auto RoundUpToTwoDecimals = [](float temp) -> float{ return std::floor(temp*100.0)/100.0;};        
    if(RoundUpToTwoDecimals(_currentAmount) > 0 )
    {
        cout << "Exact amounts NOT entered: Coins retuned." << endl;
        Makechange(_currentAmount,"Nontreasury");
        return true;
    }
    return false;
}

bool VendingMachine::InsertCoins()
{
    bool exactneeded = check_Treasury();
    string coinInput;
    cout << "INSERT COINS : ";
    getline(std::cin, coinInput);

    if(coinInput.empty())
    {
        cerr << "No coins inserted" << endl;
        return false;
    }
    ProcessCoins(coinInput);   
    if(exactneeded && ExactAmount_NotInserted())
        return false;

    return true;    
}

void VendingMachine::ProcessCoins(string coinInput)
{
    int ind = 0;
    coinInput.erase(std::remove_if(coinInput.begin(),
                            coinInput.end(), ::isspace), coinInput.end());
    cout << coinInput << endl;                            
    regex pat("\\d+");
	smatch result;
    while (std::regex_search(coinInput, result, pat)) {
        _Entered_coins[ind] = stoi(result.str());
        coinInput = result.suffix().str();
        ind++;
    }
    _currentAmount += coinToCurrency(_Entered_coins);

    cout << _Entered_coins[0] << " Nickels; "  \
         << _Entered_coins[1] << " Dimes; "  \
         << _Entered_coins[2] << " Quaters; " << endl;
    cout << "Entered value: " << _currentAmount << " $ " << endl;
}



std::string VendingMachine::SelectItem()
{    
    cout << "Please select items: " ;
    string item;
    cin >> item;
    std::transform(item.begin(), item.end(), item.begin(), ::toupper);

    if(_Rates.find(item) != _Rates.end())
    {
        _selectedItem = item;
        CheckInventory(item);
    }
    else
    {
        cout << "Please select available items only" << endl;
        _selectedItem = "";
    }   
    return _selectedItem;
}

void VendingMachine::CheckInventory(std::string item)
{
    if (_Inventory[item]==0 && !item.empty())
    {
        _selectedItem = "";
        cout << "\t!!! "<< item << " - SOLD OUT" << endl;
        SelectItem();
    }
}

void VendingMachine::Dispatch_Reinsert_Makechange()
{
    string item = _selectedItem;
    _balanceAmount =  _currentAmount - _Rates[item];
    
    if(_Rates[item] > _currentAmount)  // Re-insert
    {
        ReInsertCoins(); 
    }
    else if (std::fabs(_balanceAmount) < 1e-06)  //Dispatch
    {  
        if(ReturnCoins())
            return;
        DispatchItem(item);
              
    }
    else if (_Rates[item] < _currentAmount ) //Make change
    {
        Makechange(_balanceAmount,"Treasury");
        DispatchItem(item);
    }
    
}

void VendingMachine::DispatchItem(std::string item)
{
    cout << item << " Dispatched. " << "Thank you!!!"  << endl;
    _Inventory[item]--;  
    _Treasury_Coins = Add_Arrays(_Entered_coins, _Treasury_Coins);
    _currentAmount = 0.0; _Entered_coins = {0,0,0};
}

bool VendingMachine::ReturnCoins()
{
    if(checkReturnCoins())
    {
        _balanceAmount = _currentAmount;
        Makechange(_balanceAmount,"Nontreasury");
        _balanceAmount = 0.0;
        return  true;
    }
    return false;
}

void VendingMachine::ReInsertCoins()
{
    if (InsertCoins())
    {
        Dispatch_Reinsert_Makechange();
        return;
    }
}

bool VendingMachine::checkReturnCoins()
{
    cout << "Select Proceed (YES) or Return coins(NO)" << endl;
    string RetcoinUserInput;
    cin >> RetcoinUserInput;
    std::transform(RetcoinUserInput.begin(), RetcoinUserInput.end(),
            RetcoinUserInput.begin(), ::toupper);
    std::regex yesnopattern("^YES|NO$");
    if(!std::regex_match(RetcoinUserInput, yesnopattern))
    {
        checkReturnCoins();
    }
    if(RetcoinUserInput=="YES")
        return true;

    return false;
}

void VendingMachine::Makechange(float amount ,std::string whichcoins)
{
    
    if(whichcoins == "Nontreasury")
    {
        _Return_coins  = _Entered_coins;
    }
    else  // Treasury
    {    
        std::pair<int, float> getquaters= get_CoinsNeeded(amount,"Quater");
        if(_Treasury_Coins[2] >=  getquaters.first){
            _Return_coins[2] = getquaters.first; amount = getquaters.second;
        }
        else
            _Return_coins[2] = 0; 

        std::pair<int, float> getDimes= get_CoinsNeeded(amount,"Dime");
        if(_Treasury_Coins[1] >=  getDimes.first){
            _Return_coins[1] = getDimes.first; amount = getDimes.second;
        }
        else
            _Return_coins[1] = 0;
        
        std::pair<int, float> getNickels= get_CoinsNeeded(amount,"Nickel");
        if(_Treasury_Coins[0] >=  getNickels.first){
            _Return_coins[0] = getNickels.first; amount = getNickels.second;
        }
        else
            _Return_coins[0] = 0;
        
    }
    cout << "Please check return coin tray: " \
            << _Return_coins[0] << " Nickels;  "  \
            << _Return_coins[1]   << " Dimes  ;  "  \
            << _Return_coins[2] << " Quater ;  "  << endl;

    cout << "\tAmount inserted : " << _currentAmount << " $" <<
            "\tAmount returned : " << coinToCurrency(_Return_coins) << " $" << endl;
    _currentAmount = 0.0; _Entered_coins = {0,0,0};

}

std::pair <int, float> VendingMachine::get_CoinsNeeded(float balanceAmount, string coinName)
{
    
    int coins = 0;    
    float diff = balanceAmount - _CoinValue[coinName];    
    if(diff > 0)
    {
        coins = balanceAmount / _CoinValue[coinName];
        balanceAmount = fmod(balanceAmount, _CoinValue[coinName]);
    }
    else if( std::abs(diff) < 1e-06)
    {
        coins = 1;
        balanceAmount = 0.0;
    }
    else {}
    return make_pair(coins, balanceAmount);
}

float VendingMachine::coinToCurrency(std::array<int,3> coins)
{
    return (_CoinValue["Nickel"] * coins[0] +
            _CoinValue["Dime"]   * coins[1] +
            _CoinValue["Quater"] * coins[2]);
}

std::array<int,3> VendingMachine::Add_Arrays(std::array<int,3> A, std::array<int,3> B)
{
    std::array<int,3> C;
    for (size_t i = 0; i < 3; i++)
    {
        C[i] = A[i] + B[i];
    }
    return C;
}

void VendingMachine::Print_Inventory()
{
    cout << "\n\n/////////////////////////////////////////////////////" << endl;
    cout << "Inventory details:" << endl;
    for(auto row : _Inventory)
    {
        cout << row.first << " : " << row.second  << endl;
    }
    cout << "/////////////////////////////////////////////////////\n\n" << endl;
}

void VendingMachine::PrintHeader()
{
    cout << "\nAvailable items:\n " \
         << "COLA : $ 1.00 |  CHIPS : $ 0.50 |   CANDY : $ 0.65 " << endl;

    cout << "\nAccetable Currency: NICKEL, DIME, QUATER " << endl;
    cout << "Ex: 2N 3D 4Q :: 2 NiCKELS + 3 DIMES + 4 QUATER\n\n" << endl;
}

VendingMachine::~VendingMachine()
{
    
}