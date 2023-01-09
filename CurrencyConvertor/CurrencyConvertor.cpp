#include "CurrencyConvertor.H"

using namespace std;
/**************** Constructor  ***********************/
CurrencyConvertor::CurrencyConvertor()
{
    _Date  = "2023-01-06";
    _Filename = "ConversionTable";
    ReadConversionTable();
}

CurrencyConvertor::CurrencyConvertor(std::string date, std::string FileName)
{
    _Date     = date;
    _Filename = FileName;
    ReadConversionTable();
}

void CurrencyConvertor::ReadConversionTable()
{
    std::ifstream curFilestream (_Filename);
    std::string line;
    if(curFilestream.is_open()){

        while (getline(curFilestream,line))
        {
            std::pair<std::string, double>
                Name_And_Value = SplitString(line, '\t');
            
            _ConversionTable.insert(Name_And_Value);

            _InputCurrencyList.push_back(Name_And_Value.first);

        }
    }
}

void CurrencyConvertor::DisplayInput()
{
    int i = 1;
    for(auto Value : _InputCurrencyList)
    {
        cout << i <<". " << Value << endl;
        i++;
    }
}

std::string CurrencyConvertor::CheckifNumber(std::string EnteredValue)
{
    std::regex NumberPattern("^\\d+$");
    while(!std::regex_match(EnteredValue, NumberPattern))
    {
        cout << "Please enter a valid number/amount" << endl;
        cin >> EnteredValue;
    }
    return EnteredValue;
}

bool CurrencyConvertor::CheckList(
    int InputValue, std::vector<std::string> list)
{
    try {
        list.at(InputValue);
    } 
    catch (std::out_of_range& err) {
        cout << "The number is out of range" << endl;
        return false;
    }
    return true;
}

std::string CurrencyConvertor::SelectInput()
{
    std::cout << "Select the input currency from the list" << std::endl;
    DisplayInput();

    string EnteredValue;
    cin >> EnteredValue;
    EnteredValue = CheckifNumber(EnteredValue);
    _selectedInputIndex = std::stoi(EnteredValue);
    _selectedInputIndex--;

    if(!CheckList(_selectedInputIndex,_InputCurrencyList))
        SelectInput();

    return _InputCurrencyList.at(_selectedInputIndex);
}

void CurrencyConvertor::DisplayOutput()
{
    _OutputCurrencyList = _InputCurrencyList;
    _OutputCurrencyList.erase(_OutputCurrencyList.begin()+_selectedInputIndex);

    int i = 1;
    for(auto Value : _OutputCurrencyList)
    {
        cout << i <<". " << Value << endl;
        i++;
    }
}

std::string CurrencyConvertor::SelectOutput()
{
    std::cout << "Select the outlet currency from the list" << std::endl;
    DisplayOutput();

    string EnteredValue;
    cin >> EnteredValue;
    EnteredValue = CheckifNumber(EnteredValue);
    _selectedOutputIndex = std::stoi(EnteredValue);
    _selectedOutputIndex--;

    if(!CheckList(_selectedOutputIndex,_OutputCurrencyList) )
        SelectOutput();
    return _OutputCurrencyList[_selectedOutputIndex];
}

double CurrencyConvertor::getamount()
{
    std::cout << "Please enter the amount: " << endl;
    string amount;
    std::cin >> amount;
    amount = CheckifNumber(amount);

    return std::stold(amount);
}

double CurrencyConvertor::convert()
{
    string inputCurrency    = SelectInput();
    string outputCurrency   = SelectOutput();
    double amountEntered    = getamount();
    double amountConverted  = amountEntered*(_ConversionTable[outputCurrency]/
                                                    _ConversionTable[inputCurrency]);

    std::cout << amountEntered << " " << inputCurrency <<" would be " << amountConverted << " " \
              << outputCurrency << " on " << _Date << std::endl;
    checkForAnotherConversion();
    return amountConverted;
}

void CurrencyConvertor::checkForAnotherConversion()
{
    std::cout << "Do you wish to continue with another conversion (Y/N)" << std::endl;
    std::string AnotherConversion;
    cin >> AnotherConversion;
    //Exception hannding
    std::regex pat("^[YyNn]$");
    if(std::regex_match(AnotherConversion, pat))
    {
        std::regex yesPattern("^[Yy]$");
        if(std::regex_match(AnotherConversion, yesPattern))
            convert();
    }
    else
    {
        std::cout << "Invalid input, please enter Y or N (case insensitive)" << std::endl;
        checkForAnotherConversion();
    }

}

void CurrencyConvertor::PrintHeader()
{
    std::cout << "Welcome to CCTech Currency converter: "<< std::endl;
}

void CurrencyConvertor::PrintConversionTable()
{
    for (auto NameAndValue: _ConversionTable)
        {
            cout << NameAndValue.first << ":" << setprecision(7) << NameAndValue.second << endl;
        }
}

void CurrencyConvertor::AddCurrency(std::string Name, double rate)
{
    _ConversionTable.insert(std::make_pair(Name, rate)); 
}

std::pair<std::string, double> 
    CurrencyConvertor::SplitString(const string& s, char delimiter)
{
    std::pair<std::string, double> Name_and_Value;
    std::string Name; 
    std::string Value;

    std::istringstream linestream(s);
    linestream.precision(16);
    getline(linestream, Name, delimiter);
    getline(linestream, Value, delimiter);
   return std::make_pair(Name,stold(Value));
}

CurrencyConvertor::~CurrencyConvertor()
{
}