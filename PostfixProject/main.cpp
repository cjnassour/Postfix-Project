#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	system("color 1A");

	vector<string> myvar;		//this vector will store the variables the user enters
	char inputs[15];			//this array will store the user's initial input

	cout << "Enter postfix: ";	//get user postfix input
	cin >> inputs;			
	string vecnumber;			//used for converting char to string

	for (int i = 0; i < 15; i++)
	{
		//if between 'A' to 'z' on ascii, ask user for value of variable, then add to vector
		if (inputs[i] >= 'A' && inputs[i] <= 'z') { 
			cout << "Enter value for " << inputs[i] << ": "; 
			cin >> vecnumber;
			myvar.insert(myvar.end(),vecnumber);
		} 
		//else it is a special character (+ or *), add to vector
		else {
			string spec_char(1,inputs[i]);		//convert the char to a string
			myvar.insert(myvar.end(),spec_char);
		}
	}

	cout << endl;

	vector<int> answer;	//this vector will be used to perform the operations, and store the answer

	for (int i = 0; i < myvar.size(); i++)
	{
		if (inputs[i] >= 'A' && inputs[i] <= 'z')	 
			{
				int x = stoi(myvar[i]);			//convert string to int
				answer.push_back(x);			//add number to vector for calculation
			}

		else if (inputs[i] == '+')	//addition
			{
				int sum = answer.end()[-1] + answer.end()[-2];	//last + 2nd to last element
				answer.pop_back();								//delete last element
				answer.end()[-1] = sum;							//assign last element to product
			}

		else if (inputs[i] == '*')	//multiplication
			{ 
				int product = answer.back() * answer.end()[-2];	//last * 2nd to last element
				answer.pop_back();								//delete last element
				answer.end()[-1] = product;						//assign last element to product
			}
		else if (inputs[i] == '-')	//subtraction
			{ 
				int diff = answer.back() - answer.end()[-2];	//last - 2nd to last element
				answer.pop_back();								//delete last element
				answer.end()[-1] = diff;						//assign last element to product
			} 

	}
	
	cout << "This expression equals " << answer.front() << endl;	//answer stored in the only remaining element in the vector

	return 0;
}

