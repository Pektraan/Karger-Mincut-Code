# Karger-Mincut-Code
Code for solving min-cut problem in graphs using Karger's algorithm
This is a C language implementation of Karger's algorithm to find the min cut of a graph given its adjacency list.
It takes as input a text file containing the adjacency lists of the given graph.
This is a very fast implementation using only an elementary structure and an array.
It is easy for a beginner to understand.
NOTE : If each line of the input text file is terminated with a \t\n then one has to delete all the \t's AT THE END (not in between)  for the code to work..
All the lines should be terminated with a \n.
In other words no line should end with a \t.
Otherwise one has to make minor changes the code in the populatearray part..
Eg: 
1\t3\t4\n
2\t4\t5\n
...
is correct
1\t3\t4\t\n
2\t4\t5\t\n
...
wont work..
Also each run takes approximately 5 minutes at 3 GHz clock speed, so one may find it better to reduce the constant NUMOFTIMES..

