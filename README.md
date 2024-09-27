# 🟩 BSQ (Biggest Square) Project

## 📖 Overview

The BSQ project is a C program designed to read map data from standard input or files and determine the largest square that can be formed from empty spaces. The program validates the input maps and processes them accordingly.

## 🚀 Features

- 📥 Read map data from standard input or specified files.
- ✅ Validate map structure and data.
- 📏 Identify and compute the largest square area that can fit in the map.
- 🗺️ Print the map with the largest square marked.

## 📁 File Structure

```bash

/includes
└── ft.h // Header file containing function declarations and structure definitions 
/src 
├── main.c // Main program entry point 
├── ft_process.c // Functions for processing maps and files 
└── ft_bsq.c // Functions related to finding and filling the biggest square

```
## 💻 Compilation

To compile the project, use the following command:

```bash
gcc -o bsq src/main.c src/ft_process.c src/ft_bsq.c -I includes
```
Make sure to adjust the paths based on your project's directory structure.

## 🛠️ Usage

To run the program, you can either provide map files as arguments or read from standard input:
📂 From Files

```bash

./bsq map1.txt map2.txt

```

🖊️ From Standard Input

You can also run the program without arguments and input the map data directly:

```bash

./bsq

```
Then enter the map data and end with EOF (Ctrl+D in Unix/Linux or Ctrl+Z in Windows).
🗺️ Map Format

The input maps must follow this structure:

    The first line should contain a number representing the number of rows in the map.
    Each subsequent line represents a row in the map.
    Valid characters in the map include:
        Empty space (e.g., . or other defined characters)
        Obstacles (e.g., o or other defined characters)
        Full squares (e.g., x or other defined characters)

📊 Example Map

```bash

5
.....
.....
..o..
.....
.....

```

## ⚠️ Error Handling

The program includes basic error handling, such as:

    ❌ Invalid map format or structure.
    ⚠️ Errors reading map data.
    🚫 No empty space available for placing a square.

Error messages will be printed to the standard output.
## 🤝 Contributing

Contributions are welcome! If you'd like to contribute, please fork the repository and create a pull request.

## 📜 License

This project is free to use and distribute.
