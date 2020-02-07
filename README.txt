OS Used:
mimi.cs.mcgill.ca

Assumptions:
1. A quit command has to be placed as the last command of a script that is run by the shell in order to exit the script and return to the shell.
2. The shell will allow recursion to happen when running a file (ie. a script can call itself indefinitely).
3. When piping input ex: ./mysh < testfile.txt vs using the run command, $ signs are printed where each command in the testfile is read becuase it is emulating user input, in comparison to the run command which executes tasks from a script.