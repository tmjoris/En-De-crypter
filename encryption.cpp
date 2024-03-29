#include "encryption.h"
#include <fstream>
#include <cctype>

using namespace std;

bool performCeaserCipher(string& content, bool encrypt){
    //if true positive 3 else -3
        int shift= encrypt? 3:-3;

        for(char& ch :content){
            if(isalpha(ch)){
                char base = isupper(ch)? 'A' : 'a';
                ch = static_cast<char>((ch-base+ shift +26)% 26 + base);
            }
        }
    return true;
}

bool encryptFile(const string& filename, bool encrypt){

   //Open the input file
   ifstream inFile (filename);
   if(!inFile){
    return false;
   }

   //read the contents of the file
   string content(istreambuf_iterator<char>(inFile),{});
   inFile.close();

    if(performCeaserCipher(content, encrypt)){
    //Creating an output file and writing the modified content
    ofstream outFile(encrypt ? "encrypted_"+filename : "decrypted_"+ filename);
    if(!outFile){
        return false;
    }

    outFile << content;

    outFile.close();

    return true;
    }  
}