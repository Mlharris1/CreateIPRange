/*
*
*	This program is used to write Custom IP Addresses out to a Custom File.
*	This will include 16 possible options on how to write the IPv4 Addresses out
* 	which are listed out beside the functions. All have been tested and all work. 
* 	This program does give you the ability to watch them as they are being written
*	to your specified file. Please be mindful when using this program that the more
*	IPv4 address that are written the longer it will take, as well as the strain on 
*	the device. This is written in C++, Feel free to move things around or change
*	things to meet your individual needs. 
*	
*	I am not responsible for any malicious use of this program.
* 
*	For thos unfamiliar with Networking, an IPv4 address reads x.x.x.x from 0.0.0.0
*	through 255.255.255.255. There are public and private addresses. For more
*	information, Google has been invented for your convenience. 
*
*	(x).x.x.x - this is the first octet. 
*	x.(x).x.x - this is the second octet. 
*	x.x.(x).x - this is the third octet. 
*	x.x.x.(x) - this is the fourth octet.
*	
*	set - user will be require to  specify the octet that doesnt change
*	range - user will be prompt for the minimum and maximum 
*	
* 	Please read through the initial function comments to understand
*	to understand each function.
*
*	By: Matthew Harris
*
*/
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;														// The x = set / _ = range

void FirstSecondFourthRange(string, int, int, int, int, int, int, int);		// _._.x._
void FirstThirdFourthRange(string, int, int, int, int, int, int ,int);		// _.x._._ 
void FirstThirdFourthRange(string, int, int, int, int, int, int ,int);		// _.x._._ 
void FirstThreeRange(string, int, int, int, int, int, int, int);			// _._._.x
void FirstTwoRange(string, int, int, int, int, int, int);					// _._.x.x
void NoOctRange(string, int, int, int, int); 								// x.x.x.x
void SecondFourthRange(string, int, int, int, int, int, int);				// x._.x._
void MiddleTwoRange(string, int, int, int, int, int, int);					// x._._.x
void FirstThirdRange(string, int, int, int, int, int, int);					// _.x._.x
void FirstLastRange(string, int, int, int, int, int, int);					// _.x.x._
void FirstRange(string, int, int, int, int, int);							// _.x.x.x
void SecondRange(string, int, int, int, int, int);							// x._.x.x
void ThirdRange(string, int, int, int, int, int);							// x.x._.x
void LastOctRange(string, int, int, int, int, int);							// x.x.x._
void LastTwoOctRange(string, int, int, int, int, int, int);					// x.x._._
void LastThreeOctRange(string, int, int, int, int, int, int, int);			// x._._._
void AllFourOctRange(string, int, int, int, int, int, int, int, int);		// _._._._

int a = 0;		//This is a global counter

int main()
{
	int firstOct = 0;			//	This is a set first octet
	int secondOct = 0;			//	This is a set second octet
	int thirdOct = 0;			//	This is a set third octet
	int fourthOct = 0;			//	This is a set fourth octet
	int firstRangeBeg = 0;		//	This is the minimum first octet
	int firstRangeEnd = 0;		//	This is the maximum first octet
	int secondRangeBeg = 0;		//	This is the minimum second octet
	int secondRangeEnd = 0;		//	This is the maximum second octet
	int thirdRangeBeg = 0;		//	This is the minimum third octet
	int thirdRangeEnd = 0;		//	This is the maximum third octet
	int fourthRangeBeg = 0;		//	This is the minimum fourth octet
	int fourthRangeEnd = 0;		//	This is the maximum fourth octet
	int UserMenuSelect = 0;		//	This is the integar variable that the user will allow for main menu selection 
	string UserInput, nameOfFile;
	
	cout << "This program will give you the ability to write a list of IP addresses automatically. If you have 10.10.(100-200).(100-200) then please select the set.set.range.range.\n\n";	//	This is a minor explanation and example of the capability of this program for a more detailed explanation please lookup networking octets. 	
	
	cout << "What would you like to name the outputfile (No spaces No file extension): ";	//	This gives the user the ability to customize the output name
	cin >> UserInput;
		
	nameOfFile = UserInput + ".txt";	//	This will add the file extension to the users custom filename.

	cout << "Please make a selection:\n0) set.set.set.set\n1) range.set.set.set\n2) set.range.set.set\n3) set.set.range.set\n4) set.set.set.range\n5) set.range.range.set\n6) set.set.range.range\n7) range.range.set.set\n8) range.set.set.range\n9) set.range.set.range\n10) range.set.range.set\n11) set.range.range.range\n12) range.set.range.range\n13) range.range.set.range\n14) range.range.range.set\n15) range.range.range.range\nPlease Enter Your Selection: ";
	cin >> UserMenuSelect;		//	This is the menu selection. The user will select an option 0 - 15. Pay attention to the specified selection menu. if it says set, then that octet will not have a min or max. if it says range, one will be prompted for a min and a max.
	
	switch(UserMenuSelect){		//	This Menu Selection uses a switch/case statement to give the user the ability to make the selection and then collects the required information, it will then pass the information to the designated function. The comment beside each case will show the octets that are designated as range as well as the set octet per case. 
		case 0:	// set.set.set.set
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;	
			NoOctRange(nameOfFile, firstOct, secondOct, thirdOct, fourthOct);
			break;
		case 1:	// range.set.set.set
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			FirstRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondOct, thirdOct, fourthOct);
			break;
		case 2:	// set.range.set.set
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			SecondRange(nameOfFile, firstOct, secondRangeBeg, secondRangeEnd, thirdOct, fourthOct);
			break;
		case 3:	// set.set.range.set
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			ThirdRange(nameOfFile, firstOct, secondOct, thirdRangeBeg, thirdRangeEnd, fourthOct);
			break;
		case 4:	// set.set.set.range
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			LastOctRange(nameOfFile, firstOct, secondOct, thirdOct, fourthRangeBeg, fourthRangeEnd);
			break;
		case 5:	// set.range.range.set
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			MiddleTwoRange(nameOfFile, firstOct, secondRangeBeg, secondRangeEnd, thirdRangeBeg, thirdRangeEnd, fourthOct);
			break;
		case 6:	// set.set.range.range
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd; 
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			LastTwoOctRange(nameOfFile, firstOct, secondOct, thirdRangeBeg, thirdRangeEnd, fourthRangeBeg, fourthRangeEnd);
			break;
		case 7:	// range.range.set.set
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			FirstTwoRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondRangeBeg, secondRangeEnd, thirdOct, fourthOct);
			break;
		case 8:	// range.set.set.range
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			FirstLastRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondOct, thirdOct, fourthRangeBeg, fourthRangeEnd);
			break;
		case 9:	// set.range.set.range
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			SecondFourthRange(nameOfFile, firstOct, secondRangeBeg, secondRangeEnd, thirdOct, fourthRangeBeg, fourthRangeEnd);
			break;		
		case 10: // range.set.range.set
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum ";
			FirstThirdRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondOct, thirdRangeBeg, thirdRangeEnd, fourthOct);
			break;
		case 11: // set.range.range.range
			cout << "Enter 1st Oct: ";
			cin >> firstOct;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd; 
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			LastThreeOctRange(nameOfFile, firstOct, secondRangeBeg, secondRangeEnd, thirdRangeBeg, thirdRangeEnd, fourthRangeBeg, fourthRangeEnd);
			break;
		case 12: // range.set.range.range
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter 2nd Oct: ";
			cin >> secondOct;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd;
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			FirstThirdFourthRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondOct, thirdRangeBeg, thirdRangeEnd, fourthRangeBeg, fourthRangeEnd);
			break;
		case 13: // range.range.set.range
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter 3rd Oct: ";
			cin >> thirdOct;
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			FirstSecondFourthRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondRangeBeg, secondRangeEnd, thirdOct, fourthRangeBeg, fourthRangeEnd);
			break;
		case 14: // range.range.range.set
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd;
			cout << "Enter 4th Oct: ";
			cin >> fourthOct;
			FirstThreeRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondRangeBeg, secondRangeEnd, thirdRangeBeg, thirdRangeEnd, fourthOct);
			break;
		case 15: // range.range.range.range
			cout << "Enter the minimum 1st Oct: ";
			cin >> firstRangeBeg;
			cout << "Enter the maximum 1st Oct: ";
			cin >> firstRangeEnd;
			cout << "Enter the minimum 2nd Oct: ";
			cin >> secondRangeBeg;
			cout << "Enter the maximum 2nd Oct: ";
			cin >> secondRangeEnd;
			cout << "Enter the minimum 3rd Oct: ";
			cin >> thirdRangeBeg;
			cout << "Enter the maximum 3rd Oct: ";
			cin >> thirdRangeEnd; 
			cout << "Enter the minimum 4th Oct: ";
			cin >> fourthRangeBeg;
			cout << "Enter the maximum 4th Oct: ";
			cin >> fourthRangeEnd;
			AllFourOctRange(nameOfFile, firstRangeBeg, firstRangeEnd, secondRangeBeg, secondRangeEnd, thirdRangeBeg, thirdRangeEnd, fourthRangeBeg, fourthRangeEnd);
			break;
		default:
			cout << "You have entered an invalid selection. This program will close. Next time please select an option of 0 through 15. Enter only the number and then press return.";
			break;
	}
	return 0;
}

void NoOctRange(string nameOfFile, int firstOct, int secondOct, int thirdOct, int fourthOct)
{
	ofstream out (nameOfFile);
	
	out << firstOct << '.' << secondOct << '.' << thirdOct << '.' << fourthOct << "\n";
	a++;
	out.close();
}

void FirstTwoRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondRangeBeg, int secondRangeEnd, int thirdOct, int fourthOct)
{
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int j = secondRangeBeg; j <= secondRangeEnd; j++){
			out << i << '.' << j << '.' << thirdOct << '.' << fourthOct << "\n";
			cout << a << " - " << i << '.' << j << '.' << thirdOct << '.' << fourthOct << "\n";
			a++;
		}
	}
	out.close();
}

void SecondFourthRange(string nameOfFile, int firstOct, int secondRangeBeg, int secondRangeEnd, int thirdOct, int fourthRangeBeg, int fourthRangeEnd)
{	
	ofstream out (nameOfFile);

	for (int i = secondRangeBeg; i <= secondRangeEnd; i++){
		for (int h = fourthRangeBeg; h <= fourthRangeEnd; h++){
			out << firstOct << '.' << i << '.' << thirdOct << '.' << h << "\n";
			cout << a << " - " << firstOct << '.' << i << '.' << thirdOct << '.' << h << "\n";
			a++;
		}
	}
	out.close();
}

void FirstSecondFourthRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondRangeBeg, int secondRangeEnd, int thirdOct, int fourthRangeBeg, int fourthRangeEnd)
{
	ofstream out (nameOfFile);

	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = secondRangeBeg; h <= secondRangeEnd; h++){
			for (int j = fourthRangeBeg; j <= fourthRangeEnd; j++){
				out << i << '.' << h << '.' << thirdOct << '.' << j << "\n";
				cout << a << " - " << i << '.' << h << '.' << thirdOct << '.' << j << "\n";
				a++;
			}
		}
	}
	out.close();
}

void FirstThirdFourthRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondOct, int thirdRangeBeg, int thirdRangeEnd, int fourthRangeBeg, int fourthRangeEnd)
{
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = thirdRangeBeg; h <= thirdRangeEnd; h++){
			for (int j = fourthRangeBeg; j <= fourthRangeEnd; j++){
				out << i << '.' << secondOct << '.' << h << '.' << j << "\n";
				cout << a << " - " << i << '.' << secondOct << '.' << h << '.' << j << "\n";
				a++;
			}
		}
	}
	out.close();
}

void FirstThreeRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondRangeBeg, int secondRangeEnd, int thirdRangeBeg, int thirdRangeEnd, int fourthOct)
{
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = secondRangeBeg; h <= secondRangeEnd; h++){
			for (int j = thirdRangeBeg; j <= thirdRangeEnd; j++){
				out << i << '.' << h << '.' << j << '.' << fourthOct << "\n";
				cout << a << " - " << i << '.' << h << '.' << j << '.' << fourthOct << "\n";
				a++;			
			}		
		}
	}
	out.close();
}

void LastOctRange(string nameOfFile, int firstOct, int secondOct, int thirdOct, int fourthRangeBeg, int fourthRangeEnd)
{
	ofstream out (nameOfFile);
	
	for (int i = fourthRangeBeg; i <= fourthRangeEnd; i++){
		out << firstOct << '.' << secondOct << '.' << thirdOct << '.' << i << "\n";
		cout << a << " - " << firstOct << '.' << secondOct << '.' << thirdOct << '.' << i << "\n";
		a++;	
	} 
	out.close();
}

void LastTwoOctRange(string nameOfFile, int firstOct, int secondOct,int thirdRangeBeg, int thirdRangeEnd, int fourthRangeBeg, int fourthRangeEnd)
{		
	ofstream out (nameOfFile);
	
	for (int i = thirdRangeBeg; i <= thirdRangeEnd; i++){
		for (int h = fourthRangeBeg; h <= fourthRangeEnd; h++){
			out << firstOct << '.' << secondOct << '.' << i << '.' << h << "\n";
			cout << a << " - " << firstOct << '.' << secondOct << '.' << i << '.' << h << "\n";
			a++;
		}
	}	
	out.close();
}

void LastThreeOctRange(string nameOfFile, int firstOct, int secondRangeBeg, int secondRangeEnd, int thirdRangeBeg, int thirdRangeEnd, int fourthRangeBeg, int fourthRangeEnd)
{		
	ofstream out (nameOfFile);
	
	for (int i = secondRangeBeg; i <= secondRangeEnd; i++){
		for (int h = thirdRangeBeg; h <= thirdRangeEnd; h++){
			for (int j = fourthRangeBeg; j <= fourthRangeEnd; j++){
				out << firstOct << '.' << i << '.' << h << '.' << j << "\n";
				cout << a << " - " << firstOct << '.' << i << '.' << h << '.' << j << "\n";
				a++;
			}
		}	
	}
	out.close();
}

void AllFourOctRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondRangeBeg, int secondRangeEnd, int thirdRangeBeg, int thirdRangeEnd, int fourthRangeBeg, int fourthRangeEnd)
{	
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = secondRangeBeg; h <= secondRangeEnd; h++){
			for (int j = thirdRangeBeg; j <= thirdRangeEnd; j++){
				for (int k = fourthRangeBeg; k <= fourthRangeEnd; k++){
					out << i << '.' << h << '.' << j << '.' << k << "\n";
					cout << a << " - " << i << '.' << h << '.' << j << '.' << k << "\n";
					a++;
				}
			}
		} 	
	}
	out.close();
}

void MiddleTwoRange(string nameOfFile, int firstOct, int secondRangeBeg, int secondRangeEnd, int thirdRangeBeg, int thirdRangeEnd, int fourthOct)
{
	ofstream out (nameOfFile);
	
	for (int i = secondRangeBeg; i <= secondRangeEnd; i++){
		for (int h = thirdRangeBeg; h <= thirdRangeEnd; h++){
			out << firstOct << '.' << i << '.' << h << '.' << fourthOct << "\n";
			cout << a << " - " << firstOct << '.' << i << '.' << h << '.' << fourthOct << "\n";
			a++;
		}
	}	
	out.close();
}

void FirstThirdRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondOct, int thirdRangeBeg, int thirdRangeEnd, int fourthOct)
{
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = thirdRangeBeg; h <= thirdRangeEnd; h++){
			out << i << '.' << secondOct << '.' << h << '.' << fourthOct << "\n";
			cout << a << " - " << i << '.' << secondOct << '.' << h << '.' << fourthOct << "\n";
			a++;					
		}
	}	
	out.close();
}

void FirstLastRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondOct, int thirdOct, int fourthRangeBeg, int fourthRangeEnd)
{
	ofstream out (nameOfFile);
	
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		for (int h = fourthRangeBeg; h <= fourthRangeEnd; h++){
			out << i << '.' << secondOct << '.' << thirdOct << '.' << h << "\n";
			cout << a << " - " << i << '.' << secondOct << '.' << thirdOct << '.' << h << "\n";
			a++;	
		}
	}
	out.close();
}

void FirstRange(string nameOfFile, int firstRangeBeg, int firstRangeEnd, int secondOct, int thirdOct, int fourthOct)
{
	ofstream out (nameOfFile);
		
	for (int i = firstRangeBeg; i <= firstRangeEnd; i++){
		out << i << '.' << secondOct << '.' << thirdOct << '.' << fourthOct << "\n";
		cout << a << " - " << i << '.' << secondOct << '.' << thirdOct << '.' << fourthOct << "\n";
		a++;	
	} 
	out.close();
}

void SecondRange(string nameOfFile, int firstOct, int secondRangeBeg, int secondRangeEnd, int thirdOct, int fourthOct)
{
	ofstream out (nameOfFile);
		
	for (int i = secondRangeBeg; i <= secondRangeEnd; i++){
		out << firstOct << '.' << i << '.' << thirdOct << '.' << fourthOct << "\n";
		cout << a << " - " << firstOct << '.' << i << '.' << thirdOct << '.' << fourthOct << "\n";
		a++;	
	} 
	out.close();
}

void ThirdRange(string nameOfFile, int firstOct, int secondOct, int thirdRangeBeg, int thirdRangeEnd, int fourthOct)
{
	ofstream out (nameOfFile);
		
	for (int i = thirdRangeBeg; i <= thirdRangeEnd; i++){
		out << firstOct << '.' << secondOct << '.'	<< i << '.' << fourthOct << "\n";
		cout << a << " - " << firstOct << '.' << secondOct << '.'	<< i << '.' << fourthOct << "\n";
		a++;	
	} 
	out.close();
}