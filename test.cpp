#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
int main() {
    // Test iostream
    std::cout << "Testing iostream: OK" << std::endl;
    
    // Test fstream
    std::ofstream testFile("test.txt");
    if (testFile.is_open()) {
        testFile << "Testing fstream: OK";
        testFile.close();
        std::remove("test.txt");
        std::cout << "Testing fstream: OK" << std::endl;
    }
    
    // Test vector
    std::vector<int> testVector;
    testVector.push_back(1);
    std::cout << "Testing vector: OK" << std::endl;
    
    // Test string
    std::string testString = "Testing string: OK";
    std::cout << testString << std::endl;
    
    // Test limits
    std::vector<bool> boolVec;
    std::vector<int> intVec;
    std::vector<char> charVec;
    
    std::cout << "Vector max sizes on this system:\n";
    std::cout << "bool vector: " << boolVec.max_size() << " elements\n";
    std::cout << "int vector: " << intVec.max_size() << " elements\n";
    std::cout << "char vector: " << charVec.max_size() << " elements\n";
    
    std::cout << "\nSystem limits:\n";
    std::cout << "Max size_t: " << std::numeric_limits<size_t>::max() << "\n";
    std::cout << "Available memory may be less than theoretical max\n";
    
    class ObjectA {
    public:
        int num;
        bool flag1;
        bool flag2;
    };

    class ObjectB {
    public:
        int num1;
        int num2;
        char ch;
    };

    std::vector<ObjectA> vecA;
    std::vector<ObjectB> vecB;

    std::cout << "\nObject vector max sizes:\n";
    std::cout << "ObjectA vector: " << vecA.max_size() << " elements\n";
    std::cout << "ObjectB vector: " << vecB.max_size() << " elements\n";

    // Test practical usage
    vecA.push_back({1, true, false});
    vecB.push_back({10, 20, 'A'});

    std::cout << "Testing object vectors: OK" << std::endl;

    return 0;
}