# Command-line Interface

A terminal is for accessing command-line interfaces (CLI) and text user interface (TUI) applications. In this class, we will be using the terminal to build and test C programs. Please get accustomed to the syntax of the command line.

### Open the Terminal app
For macOS users:

In Finder, go to `Applications` -> `Utilities` and open the Terminal app

### Useful commands for the Terminal application

Type these into your Terminal Window and hit Enter:

- `pwd` Print Working Directory (prints the path to the directory [folder] that you are currently in)

- `cd` Change Directory (changes working directory to different directory) 
	
	>You can type `cd` and then drag and drop the folder you'd like to work in, into the Terminal Window. This is much faster than typing out the full path

- `ls` Lists the files stored in the Working Directory

- `cp` Makes a copy of a file ("cp file.txt filecopy.txt" makes a copy of file.txt and names it filecopy.txt)

- `mkdir` Makes a new directory (`mkdir NewDirectory` makes a new folder called `NewDirectory`)

- `clear` clears the Terminal Window

- `&&` Means "and also do this", helpful for inputing multiple commands in the same line

- `man` opens the manual for Terminal commands ("man man" will open up the manual for the manual!)

- `~` means home directory

- `nano` is a text editor within Command-line Interface

### Compiling and running C code from Command-line Interface:

1. Install Command Line Tools
	
		xcode-select --install

2. Type the command `clang` to signify that we're using the [Clang Compiler](https://clang.llvm.org/). This compiler translates our C code (human readable) in to machine understandable code.

3. After `clang`, type `[nameofinputfile] -o [nameofoutputfile]`. This should look like:
	
		clang HelloWorld.c -o HelloWorld 
		
	In this command line, we named the output binary file `HelloWorld` compiled from the C file `HelloWorld.c`.

4. To Run the outputfile, type "./[nameofoutputfile]". This should look like:
 
 		./HelloWorld
	
	The `./` shortcut refers to the current directory
	
5. In Bash, we can concatenate commands using `&&`:

		clang HelloWorld.c -o HelloWorld && ./HelloWorld

7. When running the compiled binary file, it should print `Hello, World!` to the terminal window.

### Additional resources for terminal and CLI
- [GNU Bash reference](http://www.gnu.org/software/bash/manual/bashref.html)
- [The Art of Command Line](https://github.com/jlevy/the-art-of-command-line)
- [101 Bash Commands and Tips for Beginners to Experts](https://dev.to/awwsmm/101-bash-commands-and-tips-for-beginners-to-experts-30je)