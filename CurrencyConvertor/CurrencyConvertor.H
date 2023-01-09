#ifndef CURRENCY_CONVERTOR_H
#define CURRENCY_CONVERTOR_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#include <regex>

class CurrencyConvertor
{
    
    int _selectedInputIndex;
    int _selectedOutputIndex;
    
    std::string _Date;
    std::string _Filename;
    std::vector<std::string> _InputCurrencyList;
    std::vector<std::string> _OutputCurrencyList;

public:
    
    std::unordered_map<std::string, double> _ConversionTable;

    CurrencyConvertor();
    CurrencyConvertor(std::string date, std::string FileName);

    ~CurrencyConvertor();

    void ReadConversionTable();
    
    void AddCurrency(std::string Name, double rate);

    void DisplayInput();
    void DisplayOutput();

    std::string SelectInput();
    std::string SelectOutput();
    
    std::string CheckifNumber(std::string EnteredValue);
    bool CheckList(int InputValue, std::vector<std::string> list);

    double getamount();
    double convert();
    void checkForAnotherConversion();
    
    
    std::pair<std::string, double> SplitString(const std::string& s, char delimiter);

    void PrintHeader();
    void PrintConversionTable();
};

#endif