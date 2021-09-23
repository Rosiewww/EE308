#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string str;
string key_word[32] =
{
	"auto","break","case","char","const","continue","default","do ",
	"double","else","enum","extern","float","for","goto","if","int",
	"long","register","return","short","signed","sizeof","stastic",
	"struct","switch","typedef","union","unsigned","void","volatile","while"
};

//Function declaration
void Pretreatment(); //Preprocessing the text
void cal_keyword(); //Find and evaluate the number of keywords
void cal_switch_case(); //Find and evaluate the number of 'switch_case' structure
void cal_if_else(int input_level); //Find and evaluate the number of 'if_else' structure

int main()
{
	int count = 0;
	char filepath[100] = {'\0'};
	int level;
	cout<<"Please enter the file path: ";
	cin.getline (filepath,100); //Read line by line
	cout<<"Please enter the level: ";
	cin >> level;
	
	fstream file; 
	file.open (filepath);
	if(!file.is_open())//is_open returns a Boolean type to determine whether it opened successfully
	{
		cout<<"File opening failure"<<endl;
		return;
	}
	
	string temp;
	while ( file.good() )
	{
		getline(file,temp);		
		str = str + temp + '\n';
	}
	
	file.close(); //¹Ø±ÕÎÄ¼þ 
	return 0;
}

