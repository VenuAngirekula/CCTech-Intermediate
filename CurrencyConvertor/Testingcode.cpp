#include "Testingcode.H"

int main(int argc, char const *argv[])
{

    /** Reading table **/
    {
        testfunction_toReadTable("ConversionTable");
    }
    
    {   testfunction_To_selectInput("1", "EUR"); }
    {   testfunction_To_selectInput("2", "GBP"); }
    {   testfunction_To_selectInput("3", "INR"); }
    {   testfunction_To_selectInput("4", "AUD"); }
    {   testfunction_To_selectInput("5", "CAD"); }
    {   testfunction_To_selectInput("6", "SGD"); }
    {   testfunction_To_selectInput("7", "CHF"); }
    {   testfunction_To_selectInput("8", "MYR"); }
    {   testfunction_To_selectInput("dddsf\n1", "EUR"); }
    {   testfunction_To_selectInput("15\n1", "EUR"); }

    /** Select INPUT**/

    /** Select INPUT and OUTPUT**/
    {
        testfunction_To_selectOutput("junkInput\n1\njunkOuput\n1", "GBP");
        testfunction_To_selectOutput("junkInput\n1\njunkOuput\n105\n1", "GBP");

        testfunction_To_selectOutput("1\n1", "GBP");
        testfunction_To_selectOutput("1\n2", "INR");
        testfunction_To_selectOutput("1\n3", "AUD");
        testfunction_To_selectOutput("1\n4", "CAD");
        testfunction_To_selectOutput("1\n5", "SGD");
        testfunction_To_selectOutput("1\n6", "CHF");
        testfunction_To_selectOutput("1\n7", "MYR");

        testfunction_To_selectOutput("2\n7", "MYR");
    }
    
    /* Testing Convert function */
    std::cout << "Converting SGD to MYR " << std::endl;
        {testingThefunction_convert("6\n7\n1\nN",3.29);}
    std::cout << "Converting SGD to CNY " << std::endl;
        {testingThefunction_convert("6\n9\n1\nN",5.1047);}
    std::cout << "Converting GBD to AUD " << std::endl;
        {testingThefunction_convert("2\n3\n1\nN", 1.75);}
    std::cout << "Converting CHF to JPY " << std::endl;
        {testingThefunction_convert("7\n8\n1\nN",142.10);}
    std::cout << "Converting AUD to SGD " << std::endl;
        {testingThefunction_convert("4\n5\n10\nN",9.21);}
    std::cout << "Converting JPY to SGD " << std::endl;
        {testingThefunction_convert("9\n6\n10\nN",0.10);}
    
    std::cout << "Converting JPY to SGD " << std::endl;
    {testingThefunction_convert("9\n6\nInvalidAmount\n10\nn",0.10);}

    /* Testing Add_Currency function */
    {
        testingTheFunction_addcurrency("ARS", 179.084964);
    }

    /* Testing Another conversion function */
    {
        testing_AnotherConversion("9\n6\n10\nNo\nN");
        testing_AnotherConversion("9\n6\n10\nYes\nY\n5\n4\n5\nNo\nN");
    }    


    return 0;

}

void testing_AnotherConversion(std::string UserInputs)
{
    std::cout << "Selected options from user in sequence: \n" << UserInputs << std::endl;
    CurrencyConvertor CCobject;
    std::streambuf* cin_backup = std::cin.rdbuf();
    std::stringstream CommandStream(UserInputs);
    std::cin.rdbuf(CommandStream.rdbuf());
    CCobject.convert();
    std::cin.rdbuf(cin_backup);
}
void testingTheFunction_addcurrency(std::string newCurrencyName, double rate)
{
    CurrencyConvertor CCobject;
    CCobject.AddCurrency(newCurrencyName,rate);
    //Testing
    assert(CCobject._ConversionTable[newCurrencyName]==rate);
}

void testingThefunction_convert(
        std::string UserInputs, double Answer)
{
    std::cout << "Selected options from user in sequence: \n" << UserInputs << std::endl;
    CurrencyConvertor CCobject;
    
    std::streambuf* cin_backup  = std::cin.rdbuf();
    std::stringstream inputstream(UserInputs);
    std::cin.rdbuf(inputstream.rdbuf());

    double convertedResult = CCobject.convert();
    std::cin.rdbuf(cin_backup);
    assert( std::fabs(Answer - convertedResult) < 1e-02);
}

void testfunction_To_selectInput(
        std::string UserInputs, std::string TestCurrency)
{
    std::cout << "Selected options from user in sequence: \n" << UserInputs << std::endl;
    CurrencyConvertor CCobject;
    
    std::streambuf* cin_backup  = std::cin.rdbuf();
    std::stringstream inputstream(UserInputs);
    std::cin.rdbuf(inputstream.rdbuf());

    assert(TestCurrency == CCobject.SelectInput());
    std::cin.rdbuf(cin_backup);
}

void testfunction_To_selectOutput(
        std::string terminalInput, std::string TestCurrency)
{
    std::cout << "Selected options from user in sequence: \n" << terminalInput <<
             "\n    Expected output currency " << TestCurrency << std::endl << std::endl;
    CurrencyConvertor CCobject;
    std::streambuf* cin_backup = std::cin.rdbuf();
    std::stringstream teststream(terminalInput);
    std::cin.rdbuf(teststream.rdbuf());
    
    std::streambuf* cout_backup  = std::cout.rdbuf();
    std::string OutputString;
    std::stringstream outputstream(OutputString);
    std::cout.rdbuf(outputstream.rdbuf());

    CCobject.SelectInput();
    assert(TestCurrency == CCobject.SelectOutput());

    std::cin.rdbuf(cin_backup);
    std::cout.rdbuf(cout_backup);
}

void testfunction_toReadTable(std::string TableName)
{    
    CurrencyConvertor currconv;
    currconv.ReadConversionTable();

    std::unordered_map<std::string, double> 
        table = currconv._ConversionTable;

    std::string line;
    std::ifstream file(TableName);
    while (std::getline(file,line))
    {
        std::string key = line.substr(0,line.find('\t'));
        double value = stold( line.substr(line.find('\t')+1) );
        assert((table[key]==value));
    }
     
}
