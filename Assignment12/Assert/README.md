# Problem description

A program that replicates the assert function using preprocessor macro, predefined  
macros, stringfication of arguments etc.


## Usage

```bash
make clean

make
```
###Result
```bash  

cc -save-temps    foo.c   -o foo  
./foo  
foo.c:7: error: In function main(), verification of condition "(1==2)" faied.  

```
## File structure
foo.c  
verify.h  
Makefile

