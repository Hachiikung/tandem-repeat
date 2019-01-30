# tandem-repeat

My solution is in C/C++ language

Intruction to run the code
- Open Project Folder in Vistual Studio Code and use command [ g++ tandem-repeat.cpp -o tandem-repeat ] it will create the .exe file 
and then use the command [ ./tandem-reepat to run  ] to run. The test input is in the txt file and can be edited at the beginning of the main function.
g++ command can be used if MinGW is installed
- Use IDE for C/C++ language such as Dev-C or CodeBlock

The main algorithm

- Iterate of all the substring from left to right and check the substring of the same length adjacent to the left. 
if it is the same string (same hash value) then update the value to the array dp (dynamic programming approach)

Complexity

- Time: O(N^2) N is the length of string
- Memory: O(N*maximum primitive substring), O(N^2) in general case

Output 

- My output is all repeat substring which the primitive substring is between 3 to 10 and number of repeat is more than 1. The output file is the txt file output1.txt output2.txt output3.txt
