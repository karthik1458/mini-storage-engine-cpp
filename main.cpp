#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

const string STORAGE_DIR = "storage/files/";

void ensureStorageExists() {
    if (!fs::exists("storage")) {
        fs::create_directory("storage");
    }
    if (!fs::exists(STORAGE_DIR)) {
        fs::create_directories(STORAGE_DIR);
    }
}

void uploadFile(const string& filename) {
    if (!fs::exists(filename)) {
        cout << "File not found.\n";
        return;
    }

    string destination = STORAGE_DIR + fs::path(filename).filename().string();

    try {
        fs::copy_file(filename, destination, fs::copy_options::overwrite_existing);
        cout << "File uploaded successfully.\n";
    } catch (const exception& e) {
        cout << "Upload failed: " << e.what() << "\n";
    }
}

void listFiles() {
    bool empty = true;
    for (const auto& entry : fs::directory_iterator(STORAGE_DIR)) {
        cout << entry.path().filename().string() << "\n";
        empty = false;
    }

    if (empty) {
        cout << "No files in storage.\n";
    }
}

void downloadFile(const string& filename) {
    string source = STORAGE_DIR + filename;

    if (!fs::exists(source)) {
        cout << "File not found in storage.\n";
        return;
    }

    try {
        fs::copy_file(source, filename, fs::copy_options::overwrite_existing);
        cout << "File downloaded successfully.\n";
    } catch (const exception& e) {
        cout << "Download failed: " << e.what() << "\n";
    }
}

void deleteFile(const string& filename) {
    string path = STORAGE_DIR + filename;

    if (!fs::exists(path)) {
        cout << "File not found in storage.\n";
        return;
    }

    try {
        fs::remove(path);
        cout << "File deleted successfully.\n";
    } catch (const exception& e) {
        cout << "Delete failed: " << e.what() << "\n";
    }
}

int main() {
    ensureStorageExists();

    string command, filename;

    cout << "C++ File Storage System\n";
    cout << "Commands: upload <file>, download <file>, delete <file>, list, exit\n";

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;

        if (command == "upload") {
            cin >> filename;
            uploadFile(filename);
        } else if (command == "download") {
            cin >> filename;
            downloadFile(filename);
        } else if (command == "delete") {
            cin >> filename;
            deleteFile(filename);
        } else if (command == "list") {
            listFiles();
        } else if (command == "exit") {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}
