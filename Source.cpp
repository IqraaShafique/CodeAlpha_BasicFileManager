//as we used experimental/filesystem so to handle the warning   predefining it
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <string>

using namespace std;
using namespace std::experimental::filesystem;

// Function to set the console text color using ANSI escape
void SetColor(int textColor)
{
    cout << "\033[" << textColor << "m";
}

//functiom to display content of directoryy/folder
void listDirectory(const path& path) 
{
    if (exists(path) && is_directory(path)) 
    {
        for (const auto& entry : directory_iterator(path)) 
        {
            cout << entry.path().filename().string() << endl;
        }
    }
    else 
    {
        SetColor(31);
        cout << "Path does not exist or is not a directory." << endl;
    }
}

//function to display contents of file user demands
void viewFileContent(const path& filePath) 
{
    if (exists(filePath) && is_regular_file(filePath)) 
    {
        ifstream file(filePath);
        string line;
        //displaying file content
        while (getline(file, line)) 
        {
            SetColor(34);
            cout << line << endl;
        }
        file.close();
    }
    else 
    {
        SetColor(31);
        cout << "File does not exist or is not a regular file." << endl;
    }
}

//creating new directory when user asks for it
void createDirectory(const path& path) 
{
    //moving to next directory present in home directory
    if (create_directory(path)) 
    {
        SetColor(34);
        cout << "Directory created successfully." << endl;
    }
    else 
    {
        SetColor(31);
        cout << "Failed to create directory." << endl;
    }
}

//funtion yo copy both file and directories
void copyFile(const path& source, const path& destination) 
{
    try 
    {
        SetColor(34);
        copy(source, destination, copy_options::overwrite_existing);
        cout << "File copied successfully." << endl;
    }
    catch (const filesystem_error& e) 
    {
        SetColor(31);
        cout << "Error copying file: " << e.what() << endl;
    }
}

//funtion yo move both file and directories
void moveFile(const path& source, const path& destination) 
{
    try 
    {
        SetColor(34);
        rename(source, destination);
        cout << "File moved successfully." << endl;
    }
    catch (const filesystem_error& e) 
    {
        SetColor(31);
        cout << "Error moving file: " << e.what() << endl;
    }
}

int main() 
{
   string command;
   path currentPath = "D:/Intership/CodeAlpha";
   const path home = "D:/Intership/CodeAlpha";                //saving the home directory in case user wants to moves back

   SetColor(35);
   cout << "-------------------------------------------------------------------------------------------------------\n";
   cout << "                                      Basic File Manager\n";
   cout << "-------------------------------------------------------------------------------------------------------\n\n";

    while (true) 
    {
        //changing color of main text
       SetColor(36);
       cout << "\nCurrent Directory: " << currentPath.string() << endl;
       cout << "Enter command (ls, cat, mkdir, cp, mv, cd, exit): ";

       SetColor(33);
       cin >> command;
       cout << endl;
      
       SetColor(32);
        if (command == "ls") 
        {
            listDirectory(currentPath);
        }
        else if (command == "cat") 
        {
            string fileName;
            cout << "Enter file name: ";
            SetColor(33);
            cin >> fileName;
            viewFileContent(currentPath / fileName);
            cout << endl;
        }
        else if (command == "mkdir") 
        {
            string dirName;
            SetColor(32);
            cout << "Enter directory name: ";
            SetColor(33);
            cin >> dirName;
            createDirectory(currentPath / dirName);
        }
        else if (command == "cp") 
        {
            string source, destination;

            cout << "Enter source file: ";
            SetColor(33);
            cin >> source;
            SetColor(32);
            cout << "Enter destination file: ";
            SetColor(33);
            cin >> destination;
            copyFile(currentPath / source, currentPath / destination);
        }
        else if (command == "mv") 
        {
            string source, destination;
            cout << "Enter source file: ";
            SetColor(33);
            cin >> source;
            SetColor(32);
            cout << "Enter destination file: ";
            SetColor(33);
            cin >> destination;
            moveFile(currentPath / source, currentPath / destination);
        }
        else if (command == "cd") 
        {
            string dirName;
            cout << "Enter directory name: ";
            SetColor(33);
            cin >> dirName;
            if (dirName == "CodeAlpha") 
            {
                currentPath = home;  //move to home directory
            }
            else
            {
                path newPath = currentPath / dirName;
                if (exists(newPath) && is_directory(newPath))
                {
                    currentPath = newPath;
                }
                else
                {
                    SetColor(31);
                    cout << "Directory does not exist." << endl;
                }
            }
            cout << endl;
        }
        else if (command == "exit") 
        {
            break;
        }
        else 
        {
            SetColor(31);
            ///if in any case user entered upper case letter  it will give error as it is a case sensitive program
            cout << "Invalid command." << endl;
        }
    }

    SetColor(37);
    return 0;
}

