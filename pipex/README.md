# Pipex

## What is it?

Pipex is a program designed to replicate file redirection in shell commands (eg. < infile cmd1 | cmd2 > outfile). It achieves this using forks and pipes to run commands concurrently and redirects input and output from and to specified files.

## How does it Work?

Pipex works by checking it's input as valid, such as the infile and outfile having correct permissions and being actual files etc, and creates child processes to run the commands given to it which can be either system calls or custom programs/scripts. The bonus for this project also replicates the << and >> operators allowing for the user to enter input into the function directly instead of using a file and also appending any results to the outfile instead of truncating the file. 

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.