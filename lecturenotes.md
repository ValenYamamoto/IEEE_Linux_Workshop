# IEEE Linux Command Line Quickstart

## Overview
- [IEEE Linux Command Line Quickstart](#ieee-linux-command-line-quickstart)
  - [Overview](#overview)
  - [Welcome to the Command Line](#welcome-to-the-command-line)
  - [Getting Around](#getting-around)
  - [Files](#files)
  - [Permissions](#permissions)
  - [Pipes and Redirection](#pipes-and-redirection)
  - [Searching Files](#searching)
  - [Intro to Vim](#Intro-to-vim)
  - [Intro to Tmux](#Intro-to-tmux)

## Overview
Linux is an open source operating systems based on Unix. Linux has many
different distributions, which include:
- Ubuntu
- RedHat
- Arch Linux
- Centos
- and many more


## Welcome to the Command Line
prompt
In order to find out what user you are currently logged in as, use command **whoami**(who am I)
```bash
whoami
> ieee-uci
```

Some shortcuts for moving along current line
* CTRL-a - go to start of line
* CTRL-e - go to end of line
* CTRL-u - cut from start of line
* CTRL-k - cut to end of the line
## Getting Around
Files in a Linux system are organized into directories, which are like folders on Windows and Mac OS systems.
To see what directory you are currently in, use command **pwd**(print working directory)
```bash
pwd
> /home/ieee-uci
```

To see what is in the directory you are currently in, use the command **ls**(list)
```bash
ls
> directory1 file1 file2 file3 file4
```
Executing the command, you will see a list of the contents of the current
directory you are in. **ls** has lots of additional options; a few that are
used frequently:
- `ls -a` -- also lists hidden files (filenames that start with '.')
- `ls -l` -- long listing, includes file permissions, last modified time

Can also see a single file by listing its name. This is useful for testing if a
file actually exists
```bash
ls filename1 filename2
```

In order to switch directories, use command **cd**(change directory)
```bash
cd # returns you to home directory
cd ./ # stay in same directory
cd ../ # Go up to parent directory
cd directory1 # change directory to directory1
```
cd paths are all relative to your current location.

## Files
Everything in a Linux system is a file. Most of these are familiar: text files, executable files, any type of code file; Some are a little more foriegn: external devices like flash drives are represented as files.

To see what type of file a certain file is, use command **file**, which will give the type of file(pdf, executable, c code) regardless of what the extension on the file is.
```bash
file pythoncode.py
> pythoncode.py: Python script, ASCII text executable
```

To see what is at the beginning of the file, use command **head**, which will by default show the first 10 lines of the file (but more can be optionally specified)
```bash
head pythoncode.py
> # first 10 lines of pythoncode.py
head -n 20 pythoncode.py
> # first 20 lines of pythoncode.py
```

Conversely, you can also see the last few lines of a file with the command **tail**. tail can also be made to follow the end of the file as more lines are added.
```bash
tail pythoncode.py
> # last 10 lines of pythoncode.py
tail -n 20 pythoncode.py
> # last 20 lines of pythoncode.py
tail -f pythoncode.py
> # posts last 10 lines of pythoncode.py and will continue to post lines as they appear in file
```

To view the entire file, use the command **cat**(concatenate). cat will print the entire contents of the list of files it is given. As files get bigger, cat becomes less managable and it is easier to use head and tail.
```bash
cat pythoncode.py
> # puts entire pythoncode.py file on terminal
cat pythoncode.py cppcode.cpp
> # prints entire pythoncode.py file followed by entire cppcode.cpp file
```
If you want to view a long file with the ability to scroll up and down, use
command `less` followed by filename. While in less:
- `f` - next page
- `b` - back one page
- arrow keys - up and down
- `q` - quit
Can also use much of vim's search by pattern syntax.

`less` can be used to view long outputs from programs:
```bash
python3 printStuff.py | less
```
## Permissions
All files have permissions associated with them that decide which users are allowed to do certain actions on each file. To view permission on a file, we use the command **ls -l**(list long)
```bash
ls -l ex_python_file.py
> -rwxrw-rw 1 valen valen 3852 Aug 26 08:37 ex_python_file.py
```
The first field of the output is are the permissions.
- r - read permission
- w - write permission
- x - execute permisison
Any missing permission is filled with a `-`. There are 3 groups of permissions:
- first group is owner permissions
- second group is group permissions
- third group is global permissions
Each permission group can be represented as binary bitstring, where:
- r=4
- w=2
- x=1
The third field of `ls -l` is the owner, the fourth field is the group.

To change permission, use `chmod` command:
```bash
chmod u+x file # add execute permission for user for file
chmod 644 file # change permission on file to rwxr--r--
```
## Piping and Redirection
Every command has 3 data streams:
- STDIN (0) - input
- STDOUT (1) - output, default prints to terminal
- STDERR (2 ) - error, default prints to terminal

To redirect to a file, use `>`:
```bash
ls -l > filename
```
This puts the output of `ls -l` in filename, erasing everything that was in
filename previously. To append to the end of an existing file, use `>>`:
```bash
ls -l >> filename
```
which puts the output of `ls -l` at the end of filename and preserves the
contents of filename that were there previously.

Can also ssend data from a file and feed into another program.
```bash
wc -l < filename # Counts the number of lines in filename
```
To redirect stderr:
```bash
python3 throw_error.py 2> errorOutput # redirect error to errorOutput file
python3 throw_error.py 2>&1 # redirect error stderr to stdout
```
Put an `&` in front of a number to denote the data stream you are redirecting
to.

Redirecting sends data to and from files; piping sends data from one program to
another. The pipe operator is `|`.
```bash
ls | head -n 3 # take output of ls and pipe to head to only display 3 lines
```

Can use command `tee` to read from input and output it to stdout and at least
one file simultaneously. Helpful for putting output from a program in a file
while also having it appear on the screen in stdout.
```bash
python3 program_with_output.py | tee file1 # put output in stdout and file1
python3 program_with_output.py | tee -a file1 # put output in stdout and
# append to file1
```
## Searching

The `find` command searches for files that match a certain pattern. To find a
file that matches a certain pattern:

```bash
find . -name pattern
```
which will search the current directory and all directories under it. To start
search at a different directory:
```bash
find ./directory_name -name pattern
```

The `grep` command searches inside a specific file for a certain pattern.
```bash
grep pattern filename # search filename for pattern
grep pat1 pat2 filename # search filename for both pat1 and pat2
```
Can outputs to grep.
```bash
ls -l | grep ^d # list all directories 
```

## Introduction to Vim

To edit a file in vim from the command line, type:
```bash
vim filename
vi filename
```

When you first enter vim, you enter in normal mode.

While you can use arrow keys in vim, to get the fastest performance use the
keys:
* k - up
* j - down
* h - left
* l - right
which only works in normal mode.

To insert text, enter Insert mode by pressing `i`, which will allow you to
begin inserting characters where the cursor currently is.

Insert mode can also be reached by pressing `a`, which will begin inserting
text after the cursor.

To insert a line:
* o - opens a line underneath where cursor is
* O - opens a line above where cursor is

For more info, check out [Vim Cheat Sheet](https://vim.rtorr.com)

## Introduction to Tmux
Tmux is a terminal multiplexer. Using tmux, you can simulate having multiple
windows open in a single terminal window at a time.

To start tmux, simply type `tmux` on the command line.

To create a new window, press `Ctrl-b c`. 

To move between windows, use:
* `Ctrl-b n` - moves to next window
* `Ctrl-b p` - moves to previous window

Tmux can also split the screen into multiple panes and facilitate a shared
screen between people on the same machine. For more information, check out:
[Tmux Cheat Sheet](https://tmuxcheatsheet.com)
