
#  Custom Shell in C

This project is a lightweight custom shell written in C, built from scratch to mimic the core functionalities of a Unix-like shell. It supports process management, directory traversal, command history, colored output, and more.

##  Features

-  Custom prompt with username, hostname, and current directory
-  Built-in commands:
  - `warp <dir>`: change directories (`cd` equivalent)
  - `peek`: list directory contents (`ls` equivalent)
  - `proclore [pid]`: display process information
  - `seek <pattern>`: recursively search for files/directories
  - `pastevents`: view and manage command history
-  Color-coded output for files, directories, and executables
-  Command history with:
  - Last 15 commands stored
  - Ability to clear history
  - Retrieve specific past command
-  Absolute and relative path handling
-  Supports `~` for home directory, `-` for previous directory

---



