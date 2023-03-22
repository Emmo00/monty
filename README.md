# Monty

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Example:
```shell
emmo00@ubuntu:~/monty$ cat -e file.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
## Compilation
Compile this project using the following command
```shell
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
## Usage
```shell
monty file
```
where file is the path to the file containing Monty byte code