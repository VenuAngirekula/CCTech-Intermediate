#ifndef TESTINGCODE_H
#define TESTINGCODE_H

#include "CurrencyConvertor.H"
#include <sstream>

void testfunction_toReadTable(std::string TableName);

void testfunction_To_selectInput(std::string TestIndex, std::string TestCurrency);

void testfunction_To_selectOutput(std::string terminalInput, std::string TestCurrency);

void testingThefunction_convert(std::string TestIndex, double Answer);

void testingTheFunction_addcurrency(std::string newCurrencyName, double rate);

void testing_AnotherConversion(std::string UserInputs);
#endif