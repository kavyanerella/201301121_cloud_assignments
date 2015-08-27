#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
	ifstream file("add32.asm");
	ofstream myfile;
	myfile.open("add64.asm");
	string line;
	int flag = 0;
	while(getline(file, line))   
    {
    	istringstream iss(line);
    	string result;
    	while(getline(iss, result , ' '))
        {	 
        	if(result == "dd")
        		myfile << " dq" ;
        	else if(result == "resd")
        		myfile << " resq";
        	else if(result == "eax,")
        		myfile << " rax,";
        	else if(result == "eax")
        		myfile << " rax" << endl << "pop rbp"; 
        	else
        		myfile << " " << result;

        	if(result == "main:")
        	{
        		myfile << endl ; 
        		myfile << "push rbp" ;
        	}
        }
        myfile << endl;
    } 
    myfile.close();
	return 0;
}
