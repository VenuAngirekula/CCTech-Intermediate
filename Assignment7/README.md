# Description

The code will convert a floating number to four byte.In C++ float 4 byes(32 bits) of memory, which has three components as 
* Sign - 1 bit
* Exponent - 8 bit
* Significant - 23 bit

Bit will be arranged in this sequence. We are going to split this 32 bits to 4 bytes and converting them to their decimal value.

Ex:  
Float  = 10.75  
Bits   = 01000 0010 0101 1000 0000 0000 0000  
Result = 65 44 0 0  
  

The bit conversion procedure for floats is explained [here](https://www.log2base2.com/storage/how-float-values-are-stored-in-memory.html).


## Usage

```shell
# Compile main cpp file

g++ floatToFourBytes.cpp -o floatToFourBytes

# Execute the object file

./floatToFourBytes

```
## Notes
1. Cpp file has test cases & Testing function
2. Logic is stored in seperate file, "FourByteConvertor.h"