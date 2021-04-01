# Indentation of an unindented code

### Problem Statement

Read as input an unindented C/C++ program from a C/C++ file, them write a function `indent()` to convert the input code into an indented code. The **intended code** should be saved in another file *“indent.c”* and display it.

#### Hint:
Read the input unindented code as an array of strings; treat each line (null terminated) of code as a string; maintain a int variable say **(tab)**. During processing parse each string(line) and increment tab when `{` is encountered and decrement tab when `}` is encountered. To obtain desired indentation, append specific number of blank spaces corresponding to the tab to each string(line) and you may use `strcat()` function to achieve this.
