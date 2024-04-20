# Project 1 - Password Strength Verification (text processing)

## Project Description
The goal of the project is to create a program that receives a set of passwords and verifies whether each password meets all the (fixed) required rules. Passwords that pass the check will be printed out, others will be discarded.

## Compiling the Source File:

`gcc -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck `

## Execution Syntax
The program is launched in the following manner: (`./pwcheck` indicates the location and name of the program):
`./pwcheck LEVEL PARAM [--stats]`

The program is run with two fixed arguments LEVEL and PARAM and with one optional argument --stats, possibly given in the third position:

| Command | Description |
| --- | --- |
| `LEVEL` | An integer in the range [1, 4], which specifies the required security level (see below). |
| `PARAM` | A positive integer that specifies an additional parameter of the rules (see below). |
| `--stats` | If given, it specifies whether to print a summary of statistics of the analyzed passwords at the end of the program. |

## Security Levels (controlled rules)
There are a total of 4 security levels expressed through 4 rules. The security level determines that passwords must meet all rules at that level and lower. For example, security level 3 specifies that passwords must meet rules 1, 2, and 3.

Some rules are parameterizable with an integer given using the program argument PARAM. In the following list, this parameter is marked as X.

### List of Rules:
1. The password contains at least 1 uppercase and 1 lowercase letter.
2. The password contains characters from at least X groups (if the number X is greater than 4, it refers to all groups). The considered groups are:
   - lowercase letters (a-z)
   - uppercase letters (A-Z)
   - numbers (0-9)
   - special characters (must support at least non-alphanumeric characters from the ASCII table at positions 32-126, including space)
3. The password does not contain a sequence of the same characters of length at least X.
4. The password does not contain two identical substrings of length at least X.

## Statistics
If the program argument `--stats` is specified, the program must print the total statistics at the end of the output in the format:

```
Statistics:
Different characters: NCHARS
Minimum length: MIN
Average length: AVG
```
where NCHARS is the *number of different characters* occurring across all passwords, MIN is the *length of the shortest password* (or passwords) and AVG is the *average length of passwords* (arithmetic mean) rounded to one decimal place. The statistics include even the passwords that were discarded.
