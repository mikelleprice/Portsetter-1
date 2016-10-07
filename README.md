# Portsetter Version Three Readme Instructions
C++ program that mimics a linux command line

Change Order Three Instructions:

Change Order Three involves the assingment of environment variables. The user will assign values to these four environment
variables: 'LANGUAGE', 'LC_ALL', 'LC_MESSAGES' and 'LANG'. The values assigned to these variables are whatever the user 
chooses to input within the setenv function calls contained within the 'systemtester.cpp' program. In order to compile and run correctly the  'port.cpp' program, special consideration must be given to the variable 'LC_MESSAGES': using the ENV button in the upper-right hand corner of the port.cpp interface, input the variable name 'LC_MESSGAES'. 

In order to access the Spanish language functionality of this module, 
the user must assign to at least one environmental variable (using the setenv functions withn the 'systemtester.cpp' program)  a value which contains the characters 'es', with no spaces or other characters between those letters. Examples of acceptable variable values include: 'es', 'es_MX', 'es_AR', 'ES,' etc. 

Once the program runs and detects the 'es' characters then the screen outputs will switch to Spanish. 
Should the user decide to change the outputs to English, he should change the values of any of the variables that contain
characters 'es'  through the 'systemtester.cpp' program's setenv functions to another value, such 'en', 'EN', 'en_USA', etc. 
The program will then read in English. If the values 'fr,' 'FR,' 'pl,' or 'PL' are input then the program will return an
error message and revert to English outputs. If Spanish outputs are once again desired, the value of at least one environmental
variable should be ince more changed to include the characters 'es' or 'ES'.

To use the basic functionality of the program, please note the following instructions:

Instructions for operating the Change Order Two protocol:

Compile and launch the systemtester.cpp and port.cpp file in Cloud 9.
In order to access the systemtester program with the alias 'setport' please do the following:

a. Creates a file named 'setport' without any extension.
b. Write the code line: ~/workspace/port.cpp.o $1 $2 $3 $4. Do not include a line with the symbols #!/bin/bash, 
as Cloud 9 apparently uses a default bin condition that conflicts with a declared bash in code.
c. Save and close the file and then move the 'setport' file to the bin folder with the command: mv setport ~/bin
d. Make the file executable through the command: chmod 755 ~/bin/setport.
