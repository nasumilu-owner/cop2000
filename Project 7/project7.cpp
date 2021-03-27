//Michael Lucas
//COP2000.53
//Project 7 - Decrypt file

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define BUFFER_SIZE 11 // The maximum buffer size allowed

using namespace std;

/**
 * An AbstractEncryption class. (Abstract Layer)
 */
template <int N>
class AbstractEncryption
{
    public:
        AbstractEncryption(string filename) {
            this->filename = filename;
        }

        // AbstractEncryption::decrypt member function implementation (public)
        char* decrypt()
        {
            this->get_contents();
            for(int i = 0; i < N; i++) {
                this->decrypted_value[i] = this->decrypt(this->encrypted_value[i]);
            }
            return this->decrypted_value;
        }

        // AbstractEncryption:encrypt member function implmenation (public)
        int* encrypt(const string& value)
        {
            for(int i =0; i < N; i++) {
                this->encrypted_value[i] = this->encrypt(value[i]);
            }
            this->put_contents();
            return this->encrypted_value;
        }

        // Encrypts a char
        friend int operator >> (AbstractEncryption& encryption, char& value) { return encryption.encrypt(value); }
        // Decrypts an integer
        friend char operator << (AbstractEncryption& encryption, int& value) { return encryption.decrypt(value); }
        // Adds the decrypted file contents into ostream
        friend ostream& operator << (ostream& os, AbstractEncryption& encryption) { return os << encryption.decrypt(); }
        // Writes the encrypted contents to ofstream
        friend int* operator >> (AbstractEncryption& encryption, string& value) { return encryption.encrypt(value); }

    protected:
        // Encrypts a single character value.
        virtual int encrypt(const char& value) = 0;
        // Decrypts a single integer value.
        virtual char decrypt(const int& value) = 0;

        // Gets the file contents and stores it in private Project7Encryption::encrypted_value
        void get_contents()
        {
            this->filein.open(this->filename);
            if(!this->filein.is_open()) {
                cerr << "\033[1;31mUnable to open file " << filename << "!\033[0m" << endl;
                exit(404);
            } 
            string data{};
            getline(this->filein, data);
            filein.close();
            stringstream ss{data};
            string word{};
            for(int i = 0; i < N; i++) {
                ss >> word;
                this->encrypted_value[i] = stoi(word);
            }
        }

        // Puts the private Project7Encryption::encrypted_value in to the file
        void put_contents()
        {
            this->fileout.open(this->filename, ios::trunc | ios::out);
            if(!this->fileout.is_open()) {
                cerr << "\033[1;31mUnable to open file " << filename << "!\033[0m" << endl;
                exit(404);
            }
            for(int i = 0; i < N; i++) {
                this->fileout << this->encrypted_value[i];
                this->fileout << " ";
            }
            this->fileout.close();
        }

    protected:
        // File of encrypted data
        string filename;

    private:
        // Buffer for encrypted data
        int encrypted_value[N]{};
        // Buffer for decrypted data
        char decrypted_value[N]{};
        // File input resource
        ifstream filein;
        // File ouput resoruce
        ofstream fileout;
};

/**
 * Concrete class implementation of AbstractEncryption
 */
template <int N>
class Project7Encryption: public AbstractEncryption<N>
{        
    public: 
        Project7Encryption(string filename) : AbstractEncryption<N>(filename) {}
    protected:
        // AbstractEncryption::encrypt member function implementation (protected)
        int encrypt(const char& value) { return static_cast<int>((((((value) - 96) * 5) + 3) * 7) - 10); }
        // AbstractEncryption::decrypt member function implementation (protected)
        char decrypt(const int& value) { return static_cast<char>(((((value + 10)/7)-3)/5) + 96); }
};

template <int N>
class BitMaskEncryptor : public Project7Encryption<N>
{
    public: 
        BitMaskEncryptor(string filename) : Project7Encryption<N>(filename) {}

    protected:
         protected:
        // AbstractEncryption::encrypt member function implementation (protected)
        int encrypt(const char& value) { 
            if(value > 96) {
                return Project7Encryption<N>::encrypt(value);
            }
            return (((((value - 64) * 5) + 3) * 7) - 10) | UPPERCASE_BITMASK; // uppercase
        }
        // AbstractEncryption::decrypt member function implementation (protected)
        char decrypt(const int& value) { 
            if((value & UPPERCASE_BITMASK) == UPPERCASE_BITMASK) {
                return static_cast<char>(((((value - UPPERCASE_BITMASK + 10)/7)-3)/5) + 64);
            }
            return  Project7Encryption<N>::decrypt(value);
        }

    private:
        static const int UPPERCASE_BITMASK{2048};
    
};


int main(int argc, char** argv)
{
    string filename = (argc > 1) ? argv[1] : "./encrypted.txt";

    Project7Encryption<BUFFER_SIZE> encoder = Project7Encryption<BUFFER_SIZE>{filename};

    if(argc == 3) {
        string str{argv[2]};
        str.resize(BUFFER_SIZE);
        encoder >> str;
    }
    cout << "Decryption of file contents:" << endl << endl << encoder << endl;

}

