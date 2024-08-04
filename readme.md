---

# Organizer

## Overview

The Organizer is a simple C program that organizes files in a directory by moving them into subdirectories based on their file types. This tool helps keep directories tidy by categorizing files into logical groups.

## Features

- Scans a specified directory for files.
- Identifies file types based on their extensions.
- Creates directories for different file types if they do not already exist.
- Moves files into the appropriate directories based on their types.

## Supported File Types

- **Images**: `.jpg`, `.png`
- **Documents**: `.pdf`, `.doc`, `.txt`
- **Videos**: `.mp4`, `.mkv`
- **Others**: Any other file types

## Prerequisites

- A C compiler (e.g., `gcc` `clang`).

## Usage

1. **Compile the program** using a C compiler:
   ```sh
   gcc src/main.c -o organize
   ```

2. **Run the program** with the directory path as an argument. If no argument is provided, it defaults to the current directory:
   ```sh
   ./organize </path/to/directory>
   ```

## Example

To organize files in the current directory:
```sh
./organize .
```

The program will create subdirectories (`Images`, `Documents`, `Videos`, `Others`) and move the files into these directories based on their extensions.


---