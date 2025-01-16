# get_next_line

## What it is?

Get_next_line, or gnl as it is commonly abbreviated to, is a function designed to read files which are passed to it and return each line contained within separated by a new line (\n).

## How does it work?

Gnl works by reading a defined amount of bytes inside a file passed to it. If the amount is not specified then the program will use a default amount, in this case 9 bytes. If the entire line was not read the program will store what it as read and keep adding the rest of the line until it reached the next line. It is also capable of handling multiple files at once by storing each file's file descriptor as an element in a 2D array.

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.