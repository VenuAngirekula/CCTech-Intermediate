# Objective
To perform a Golden master testing on unix 'cat' command.  

# Test cases  
1. When no arguments provided, then it read the inputs from terminal (stdin) and print them right away, untill
   EOF is read by the program, then it will exit without printing any new line to terminal.
     
Single argument

When single argument is provided, then check if it Directory or fileName.

2.   If an argument is directory, then print out "DirectoryName/: Is a directory".
   >> cat DirectoryName 
   cat: DirectoryName/: Is a directory

3. If file is present, Print contents of file to terminal  
    >> cat file
   
4. If file is absent, then show error msg in terminal.
   cat: hi: No such" file or directory

Multiple arguments

5. When multiple arguments are provided, then concatenate the contents of file in a sequence.
6. if file is missing, then throw an error for the file which is not present
7. When one of the argument is a directory, show msg "cat: DirectoryName/: Is a directory" in the sequence.  

# Note 
1. check test cases in the Makefile
