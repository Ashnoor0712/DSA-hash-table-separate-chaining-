// ashnoor kaur jattana
// cscii 115
// lab 7

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

 int simpleHash(string word, int tableSize)
{
     int hash =0;
    for(char c: word)
    {
        hash+=c;
    }
    return hash % tableSize;
}

unsigned int djb2(const string& str) {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }
    return hash;
}

unsigned int sdbm(const string& str) {
    unsigned int hash = 0;
    for (char c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

unsigned int loseLose(const string& str) {
    unsigned int hash = 0;
    for (char c : str) {
        hash += c;
    }
    return hash;
}

class HashTable
{
    public:
    
    vector<list<string>> table;
    int size;
    unsigned int (*hashFunction)(const string&);
    
    HashTable(int s, unsigned int (*func)(const string&)= nullptr)
    {
        size =s;
        table.resize(size);
        hashFunction = func;
    }
    
    void insert(string word)
    {
        int index ;
        //= simpleHash(word, size);
        if(hashFunction)
        {
            index=hashFunction(word)% size;
        }
        else{
            index = simpleHash(word, size);
        }
        table[index].push_back(word);
    }
    
    void display()
    {
        for(int i =0; i<size; i++)
        {
            cout<<"Bucket"<<i <<": ";
            for(auto& word: table[i])
            {
                cout<<word<<" -> ";
            }
            cout<<"NULL"<<endl;
        }
    }
    
};


// function to read words
vector<string> readwords (const string& filename, int max)
{
    ifstream file(filename); // open the file in filename
    vector<string> words;
    string word;
    
    while (file>> word && words.size() < max)
    {
        words.push_back(word);
    }
    
    return words;
}

void computestats (const HashTable& ht)
{
    size_t maxLength = 0;
    size_t totalLength =0;
    
    for(const auto& chain: ht.table)
    {
        size_t chainLength = chain.size();
        if(chainLength>maxLength)
        {
            maxLength=chainLength; // update maxLength
        }
        totalLength += chainLength;
    }
    
    double average = static_cast<double>(totalLength)/ht.size;
    
    cout<<"Maximum Chain Length: "<<maxLength<<endl;
    cout<<"Avg Chain Length: "<<average<<endl;

    
}



int main()
{
   string filename= "Oxford English Dictionary.txt";
   int max=5000;
   
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    
   vector<string> words = readwords(filename, max);// step 1
   
   /*cout<<"Total words loaded: "<<words.size()<<endl;
   
   HashTable ht(2000);// step 2
   
   for(const auto& word: words)
   {
       ht.insert(word);
   }
   
   computestats(ht);// step 3*/
   
   cout<<"Testing with djb2 Hash Function: "<<endl;
   HashTable ht_djb2(2000, djb2);
   for(const auto& word: words)
   {
       ht_djb2.insert(word);
   }
   
   computestats(ht_djb2);
   
   cout<<endl;
   cout<<"Testing using sdbm Hash Function: "<<endl;
   HashTable ht_sdbm(2000, sdbm);
   for(const auto& word: words)
   {
      ht_sdbm.insert(word);
   }
   
   computestats(ht_sdbm);
   
   
   cout<<endl;
   cout<<"Testing using loselose Hash Function: "<<endl;
   HashTable ht_loselose(2000, loseLose);
   for(const auto& word: words)
   {
      ht_loselose.insert(word);
   }
   
   computestats(ht_loselose);
   

    return 0;
}
