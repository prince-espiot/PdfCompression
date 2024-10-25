// PdfCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class SimplePDFReader {
private:
    std::vector<char> pdfData;
public:
    SimplePDFReader(){}
    ~SimplePDFReader(){}

    // Method to read the PDF file
    bool ReadPDF(const std::string& filePath) {
        std::ifstream inputFile(filePath, std::ios::binary);
        if (!inputFile) {
            std::cerr << "Error opening PDF file: " << filePath << std::endl;
            return false;
        }
        // Read the entire PDF file into the pdfData vector
        pdfData = std::vector<char>((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        inputFile.close();

        return true;
    }

    // Method to get the raw PDF data
    const std::vector<char>& GetPDFData() const {
        return pdfData;
    }
};

int main()
{
    SimplePDFReader pdfReader;

    // Provide the path to your PDF file
    std::string pdfFilePath = "C:\\Users\\admin\\OneDrive\\Documents\\API For Production Testing.pdf";

    if (pdfReader.ReadPDF(pdfFilePath)) {
        const std::vector<char>& data = pdfReader.GetPDFData();
        std::cout << "PDF file read successfully. Size: " << data.size() << " bytes." << std::endl;

        // Pass the data to another class for processing here
        // Example: AnotherClass processor(data);
        for (char c : data) {
            std::cout << c;
                        
        }
        std::cout << std::endl;
    }
    else {
        std::cerr << "Failed to read the PDF file." << std::endl;
    }

    

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
