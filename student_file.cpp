#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<algorithm> // Add this line
using namespace std;

class files{
    public:
        int rollno;
        string name;
        string course;
        string subject;
        
    public:
        void inputdata();
        void displaydata();
        void countWordsAndLines();
        void copyFile();
        void readFromFile(); // Add this line
};

void files::inputdata()
{
    cout<<"enter rollno : ";
    cin>>rollno;
    cout<<"\n enter name : ";
    cin>>name;
    cout<<" \n course : ";
    cin>>course;
    cout<<"subjects : ";
    cin>>subject;
}

void files::displaydata()
{
    cout<<"display";
    ofstream outline;
    outline.open("file.txt",ios::app);
    outline<<rollno <<"\n";
    outline<<name<<"\n";
    outline<<course<<"\n";
    outline<<subject<<"\n";
    outline.close();
}

// Function to read content from file
void files::readFromFile() {
    string line;
    ifstream myfile ("file.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 
}

// Function to count no of word and no of lines in a file
void files::countWordsAndLines() {
    string line;
    int wordCount = 0;
    int lineCount = 0;
    ifstream myfile ("file.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            lineCount++;
            wordCount += count(line.begin(), line.end(), ' ') + 1;
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    cout << "Number of words: " << wordCount << "\n";
    cout << "Number of lines: " << lineCount << "\n";
}

// Function to copy contents of one file to another file
void files::copyFile() {
    ifstream src("file.txt", std::ios::binary);
    ofstream dst("file_copy.txt", std::ios::binary);
    dst << src.rdbuf();
}

int main()
{
    int n;
    
    cout<<"enter number of student : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        files f;
        f.inputdata();
        f.displaydata();
        f.countWordsAndLines();
        f.copyFile();
    }

    // Create an object and call the function here
    files obj;
    obj.readFromFile();
}
