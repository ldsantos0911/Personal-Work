My program is written in python3 and can be run via a terminal by navigating to the directory which contains it and typing:

$python3 occurrences.py

Although, this will not do anything as a function call is not present in the program itself.

Instead, the function can be imported inside another python program's source code by typing the following line somewhere, before it is intended to be used (in order for this to work, occurrences.py must be copied/moved to the same directory as the program in question):

import occurrences.py

COMPLEXITY:

In terms of space, this function only uses enough memory to create an array of 26 ints.

Regarding time, this function works in O(n), or linear, time, for it only moves through the requested string once. 


