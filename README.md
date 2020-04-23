# KuppaShell

<p align="center">
<img src="https://scontent-yyz1-1.cdninstagram.com/v/t51.2885-15/e35/90091621_139784817544104_7832354385914330040_n.jpg?_nc_ht=scontent-yyz1-1.cdninstagram.com&_nc_cat=100&_nc_ohc=qS5dny3McOUAX855iE_&oh=d9d29cc30a037cbf249d74a37bf028ad&oe=5EB5B093" height="308" width="508">
</p>

### Description
KuppaShell is a UNIX command interpreter written in the C programming language. This repository is continuation of 
simple_shell project from HolbertonSchool. More features such as easter eggs, alias, etc will be added.

___
## Project Requirements
### General
- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with gcc 4.8.4 using flags:
```c
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
 ```
- All files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Code should use the [Betty style](https://github.com/holbertonschool/Betty/wiki)
- Github - There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.
- No more than 5 functions per file
- Header files should be include guarded
- The shell should not have any memory leaks
- Use of system calls only when needed

### Authorized functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

___
## Installation
Clone repository into working directory:
```c
$ git clone https://github.com/djso89/KuppaShell.git
 ```
Compile as follows for best results:
```c
$ gcc -Wall -Werror -Wextra -pedantic *.c -o kuppa
 ```

## Usage
KuppaShell works in either interactive or non-interactive modes. Use "exit" command or ctrl-D to end KuppaShell.

### Interactive Mode
Run executable then type in commands at prompt. For example:
```c
$ ./kuppa
KuppaShell$ /bin/ls
hsh main.c shell.c
KuppaShell$ exit
$
 ```

### Non-interactive Mode
Echo desired command and pipe into program. KuppaShell will end after commands are executed. For example:
```c
$ echo "/bin/ls" | ./kuppa
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./kuppa
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
 ```
___
## Examples
KuppaShell can run outside programs, if its directory is included in the PATH. 

### Run program by absolute path:
```c
KuppaShell$ /bin/ls
hsh main.c shell.c
KuppaShell$ 
 ```
Run program by executable name:
```c
KuppaShell$ pwd
/home/vagrant/simple_shell
KuppaShell$ 
 ```
Run a KuppaShell built-in:
```c
KuppaShell$ env
XDG_SESSION_ID=10
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 59047 22
SSH_TTY=/dev/pts/1
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 59047 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LESSCLOSE=/usr/bin/lesspipe %s %s
_=/usr/bin/env
OLDPWD=/home/vagrant/simple_shell
KuppaShell$ 
 ```
___
## File Descriptions
Name | Description
| --- | --- |
[main.c](https://github.com/djso89/simple_shell/blob/master/main.c) | handles user input
[kshell.h](https://github.com/djso89/simple_shell/blob/master/kshell.h) | library includes and all function prototypes
[kshell.c](https://github.com/djso89/simple_shell/blob/master/kshell.c) | prints the prompt for user
[avtok.c](https://github.com/djso89/simple_shell/blob/master/avtok.c) | converts string to array of strings
[dir_helpers.c](https://github.com/djso89/simple_shell/blob/master/dir_helpers.c) | returns list of directories
[env_helpers.c](https://github.com/djso89/simple_shell/blob/master/env_helpers.c) | tokenizes environment variables
[error.c](https://github.com/djso89/simple_shell/blob/master/error.c) | handles errors
[exit_helpers.c](https://github.com/djso89/simple_shell/blob/master/exit_helpers.c) | returns the exit status
[execute.c](https://github.com/djso89/simple_shell/blob/master/execute.c) | executes commands
[free_mem.c](https://github.com/djso89/simple_shell/blob/master/free_mem.c) | frees allocated memory
[str_helpers.c](https://github.com/djso89/simple_shell/blob/master/str_helpers.c) | functions that manipulate strings including copy and compare
___
### Authors
* **Daniel So** - [djso89](https://github.com/djso89)
* **Michelle Domingo** - [michedomingo](https://github.com/michedomingo)

### Inspiration
[Kuppa the Marginated Tortoise](https://www.instagram.com/troopakuppa19/)
