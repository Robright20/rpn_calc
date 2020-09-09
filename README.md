# RPN Calculator

A C program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation,
and prints the result on the standard output followed by a newline.  

## About

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.  
[See more](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

## Algorithm explained

[TODO]

## Latest Features

The folowing operator works well: "+", "-", "/", "\*", "%" .

## Building

The code was written on Ubuntu 18.04.4 LTS, and to compile it you'll need
- gcc
- make

```
make
```

## Testing

The folder [answer/](https://github.com/Robright20/rpn_calc/tree/master/answers)
contains a list of expexted result for each test case written in ./spec.sh

```
sh spec.sh
```

## Usage

The program will write "Error\n" to the stdout it the string isn't valid or
there isn't exactly one argument.

All the given operands must be in INTEGER type.

```
$> ./rpn "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn "1 2 3 4 +" | cat -e
Error$
$> ./rpn |cat -e
Error$
```
