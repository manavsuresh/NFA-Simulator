#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Test iostream
    std::cout << "Testing iostream: OK" << std::endl;
    
    // Test fstream
    std::ofstream testFile("test.txt");
    if (testFile.is_open()) {
        testFile << "Testing fstream: OK";
        testFile.close();
        std::cout << "Testing fstream: OK" << std::endl;
    }
    
    // Test vector
    std::vector<int> testVector;
    testVector.push_back(1);
    std::cout << "Testing vector: OK" << std::endl;
    
    // Test string
    std::string testString = "Testing string: OK";
    std::cout << testString << std::endl;
    
    return 0;
}