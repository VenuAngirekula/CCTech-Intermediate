## MOTIVATION
To create an application that selects the only filename that needed to change from the full name of the file, by excluding  

1. Extensions (.py, .exe, .ay, etc)

2. Keywords like "tests", "test", "spec", "specs", "step", and "steps". (Case insensitive) 

3. Combinations of above keywords along with separators like dot(.), underscore(_), hyphen(-).    

4. path of the file  
   Eg: test/FizzBuzz_test.exs -> FizzBuzz


## Test cases  
Manual test cases are used to develop the logic. Along with the function is written to read test cases from a JSON file and automate the testing.  

## Strategy   
1. Remove the above-mentioned extension, keywords and their combinations, and dir patch from the original file name.  
2. Then, identify the indices of the interested name in the original filename  
3. Return it back to the Testing function.

## File Structure  
* dojo.cpp -- Main file  
* Testingfunction.h -- Function that checks the logic and returns a bool to assert.  
* testcaselist.json --  File that contains test cases.  
* fileNameSelector.h -- File that contains the logic to identify the indices of the word of interest.

