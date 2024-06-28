#CodeAlpha_BasicFileManager
This C++ program provides a simple command-line interface for managing files and directories using the <experimental/filesystem> library. It enables users to perform basic filesystem operations such as listing directory contents, viewing file contents, creating directories, copying files, moving files, and changing directories. The program enhances the user experience by using ANSI escape codes to color the console output, making the interaction more visually appealing and organized.

The program begins by defining _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING to handle any deprecation warnings from the experimental filesystem library. The SetColor function is used throughout to change the text color of the console output. This function helps distinguish different types of messages, such as prompts, errors, and status updates.

-> The listDirectory function lists all files and directories within a specified directory. 
-> The viewFileContent function displays the content of a specified file, 
-> while the createDirectory function creates a new directory at the specified path. 
-> The copyFile and moveFile functions handle the copying and moving of files, respectively, with appropriate error handling using exceptions.

In the main function, the program enters a loop where it continuously prompts the user for commands. The current directory is displayed at each iteration, and the user is asked to enter a command. The supported commands are:

ls: Lists the contents of the current directory.
cat: Displays the contents of a specified file.
mkdir: Creates a new directory.
cp: Copies a file from a source to a destination.
mv: Moves a file from a source to a destination.
cd: Changes the current directory. Special handling is included for returning to a predefined "home" directory.
exit: Exits the program.
The program checks the existence and type of files and directories before performing operations to ensure valid actions. For instance, when changing directories (cd), it verifies whether the target directory exists and is indeed a directory. If an invalid command is entered, the program notifies the user of the error.

Overall, this program provides a straightforward and interactive way to manage files and directories through a command-line interface, with added visual cues for an improved user experience.
