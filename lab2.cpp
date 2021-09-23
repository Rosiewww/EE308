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
void pretreatment(); //Preprocessing the text
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
	
	//Introducing preprocessor functions
	pretreatment();
	
	//Introduce keyword statistics functions
	cal_keyword();
	
	if (level > 1)
	{
	 	//Introduces the function that find switch-case structures.
		cal_switch_case();
		if (level > 2)
		{
			//Introduce a function that finds the number of if-else structures
			if_else_find( level );
		}  
	}
	file.close();  
	return 0;
}

//Delete the comment part of the file and process the file	 
void pretreatment()
{
	for (int i=0,j=i; i<(int)str.length(); i++ )
	{
		if (str[i]=='/' && str[i+1]=='/' )
		{
			j = i;
			while ( str[j] != '\n' )
			{
				j ++;
			}
			str.erase(i,j-i+1);
		}
		if (str[i]=='/' && str[i+1]=='*' )
		{
			j = i + 2;
			while ( str[j] != '*' )
			{
				j ++;
			}
			str.erase(i,j+2-i);
		}
		if ( str[i]=='"')
		{
			j = i+1;
			while (str[j] != '"' )
			{
				j ++;
			}
			str.erase(i,j-i+1);
		}
	}
}

//Check the keyword table to find the number of keywords in the file and return
void cal_keyword()
{
	int t_num=0;
	for (int i=0;i<32;i++)
	{
		int count = 0;
		size_t position = str.find(key_word[i]);
		while ( position != str.npos )
		{
			count ++;
			position = str.find(key_word[i],position+1);
		}
		t_num += count;
	}
	printf ("total num: %d\n",total);	
}


