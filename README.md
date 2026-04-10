# 💾 C++ File Storage System

A simple command-line file storage system built in C++ that simulates core storage operations such as uploading, retrieving, listing, and deleting files.

## 🚀 Features
- Upload files into storage
- Download files from storage
- List all stored files
- Delete files
- Error handling for missing files

## 🛠 Technologies Used
- C++
- STL (`filesystem`, `fstream`)
- Linux-compatible

## 📂 Project Structure
storage/
 ├── files/
 ├── metadata.txt
 ├── main.cpp

## ▶️ How to Run

1. Compile:
g++ -std=c++17 main.cpp -o storage_app

2. Run:
./storage_app

## 💡 Example Commands
upload test.txt
list
download test.txt
delete test.txt

## 🎯 Learning Outcomes
- File handling in C++
- Working with filesystem APIs
- Designing simple storage systems
- Error handling and CLI design

## 🔮 Future Improvements
- File chunking
- Multithreading for faster operations
- Logging system
- Distributed storage simulation

Built as a systems-focused project to explore storage concepts similar to distributed systems like Ceph.
