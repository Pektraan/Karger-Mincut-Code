# Karger-Mincut-Code

###Code for solving the min-cut problem in graphs using Karger's algorithm

This is a C language implementation of Karger's algorithm to find the min cut of a graph given its adjacency list. This was done as part of `Week 3` of `Algorithms - Design and Analysis - Part 1`'s Programming Assignment. The algorithm used is from the video lecture.

It takes as input a text file containing the adjacency lists of the given graph (the assignment's input file).

This is a fast implementation using only an elementary structure and an array.
It is easy for a beginner to understand.

**NOTE** : If each line of the input text file is terminated with a `\t\n` then one has to delete all the `\t`'s AT THE END (not in between)  for the code to work..

Try running `dos2unix kargerMinCut.txt` or `unix2dos kargerMinCut.txt`.
If both don't work, then one has to manually remove the `\t`'s at the end.

All the lines should be terminated with a `\n`.
In other words no line should end with a `\t`.
Otherwise one has to make minor changes to the code in the `populatearray` function.

Eg: 
1 \t 3 \t 4 \n
2 \t 4 \t 5 \n
...
is correct

1 \t 3 \t 4 \t \n
2 \t 4 \t 5 \t \n
...
wont work..

Also each execution of the program with `NUMOFTIMES` trials in each execution, takes approximately 5 minutes at 3 GHz clock speed, so one may find it better to reduce the constant `NUMOFTIMES`.

