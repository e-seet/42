# README

Use MakeFile with ENTR(File Watcher) to make life easier!
Note: ENTR is a file watcher

To setup:
brew install entr

Example: Makefile folder with ENTR
At the pwd:
/Users/eddieseet/MDesktop/42/makefile

Run entr:
find . -name "*.c" | entr make

Run the compiled program:
./$(name) as declared in the libft

Command:
find . -name "*.c" | entr make

find: This is the command used to search for files and directories within a file system.

.: This specifies the directory where find should start searching. The period . represents the current directory, meaning that find will search in the current directory and all of its subdirectories.

-name: This option tells find to only consider file names that match the pattern that follows.

"*.c": This is the pattern that file names need to match. The asterisk * is a wildcard that matches any number of characters, and .c specifies that the file name should end with .c. Therefore, "*.c" matches any file that has a .c extension, which is typically used for C source files.

"make": This tells the Makefile in the directory to do work. This can be changed to "Make bonus" if you are interested in "Make bonus"