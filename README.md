Temperature Analyser in C

A beginner C project that reads temperature data from a file, performs statistical analysis, and filters temperatures based on a user-defined threshold.

Features

Reads temperature data from a text file.

Calculates highest and lowest temperatures.

Calculates the mean temperature.

Counts temperatures above a given threshold.

Dynamically allocates memory for filtered temperatures.

Writes filtered temperatures to a new file.

Concepts Practised

C arrays and functions

Pointers and dereferencing

Dynamic memory allocation (malloc and free)

File handling (fopen, fscanf, fprintf, fclose)

Input validation and debugging

Compilation

gcc main.c -o temperature_analyser

Execution

./temperature_analyser

Input Format

The temperature.txt file contains time and temperature values separated by commas.

Output

Generates high_temps.txt containing temperatures above the user-defined threshold.