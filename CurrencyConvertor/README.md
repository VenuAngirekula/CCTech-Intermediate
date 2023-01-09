
# Currency Convertor

Currency convertor written in C++. Library is takes Currency conversion rates
from text file "ConversionTable" [Should be placed in same directory as library]  

Find problem statement in "ProblemStatement" file.

## Assumptions
* Value corresponding to each currency in CurrencyTable file is inverse of its value in US dollars.  
Example:  
```
EUR	0.937044
```
It means 1 USD = 0.937044 EUR.  
## Notes

1. Tests needed for TDD(Test Driven Development) are placed in Testing.cpp  
   ```
   make Test
   ```
2. Inputs that should be passed through terminal are passed as string objects in testing file by redirecting the stream buffers.  
   ```
   "9\n6\n10\nNo\nN"
   ```
   The above string is given to stream and its buffer is provided to std::cin. [Only for testing exercise].  
3. To use library, Implementation.cpp can executed  
    ```
    make Implement
    ```
4. Error handling and Exception handling taken care for user inputs.