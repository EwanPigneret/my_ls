# Welcome to My Ls
***

## Task
The task is to recreate the behavior of the bash command ls. It needs to handle the flags -a and -t.

## Description
I separate the folders and the flags. I identify any flags by looking at the first character. If it's a '-', then the following letter define which flags it is. If not, the argument is added to a linked list
that holds every folders name. Then I pass as a parameter the value of the flags in my functions, I get every file and folder in the detected folder, stock them in a linked list and sort the linked list.
I then print the said linked list.

## Installation
I didn't have any installation to do.

## Usage
To use this project you need to compile it using this command :
```
./my_ls -flags folders
```
The flags and folders aren't necessary.

This program works by firstly separating the flags and the parameters, like explained earlier. It uses opendir and readir to read the files contained in each folders. Once the files are stocked inside
the linked list, I call another function which takes as a parameter the said linked list and creates another one, but sorted, and prints it. Depending on if the flag -t is passed as a parameter, I call a function
that compares 2 nodes alphabetically or by modification dates to know how to sort the linked list. I also concatened different string in order to precisely tell the path of each files and folders,
so I can use the function stat to get the modification date of each element.

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
