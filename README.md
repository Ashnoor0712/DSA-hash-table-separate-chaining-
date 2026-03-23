# Hash Table with Separate Chaining in C++

## Overview
This project implements a hash table in C++ using separate chaining to handle collisions. It reads words from a text file, inserts them into the hash table, and compares the behavior of different hash functions by measuring chain statistics.

The project was developed as part of a data structures lab and focuses on understanding how hashing works in practice.

## Features
- Custom hash table implementation
- Collision handling using separate chaining
- Word insertion from a file
- Comparison of multiple hash functions
- Statistics for maximum chain length and average chain length

## Hash Functions Included
- Simple hash
- djb2
- sdbm
- loseLose

## Concepts Covered
- Hash tables
- Collision handling
- Separate chaining
- Hash functions
- File input
- Basic performance analysis
- Data structures in C++

## Tech Stack
- Language: C++
- Standard Libraries:
  - iostream
  - fstream
  - vector
  - list
  - string
  - algorithm

## File Structure
- `main.cpp` — main implementation of the hash table and hash function comparison
- `Oxford English Dictionary.txt` — input file containing words for testing

## How It Works
1. Reads up to 5000 words from the input file
2. Inserts words into a hash table of size 2000
3. Tests different hash functions
4. Computes:
   - Maximum chain length
   - Average chain length

## How to Run

Compile the program:
```bash
g++ main.cpp -o program
