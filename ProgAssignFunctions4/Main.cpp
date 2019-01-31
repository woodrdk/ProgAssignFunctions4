#include <iostream>
// TO DO: include statements go here
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

////////////////// added above
#include <cstdlib>

using namespace std;

// TO DO: function prototypes go here
double mathRootSum(int num);
bool isOdd(int num);
int countEs(string word);
void cumulative(vector<int> &list);
string factors56(int num);
///////////////// added above

int main() {
	// test mathRootSum
	cout << (abs(mathRootSum(624) - 24.0) < 0.0000000000001 ? "Success" : "Fail")
		<< " on mathRootSum test 1" << endl;
	cout << (abs(mathRootSum(1000) - 30.6386) < 0.0001 ? "Success" : "Fail")
		<< " on mathRootSum test 2" << endl;

	cout << endl; // added this for visual sake when working

	// test isOdd
	cout << (isOdd(3) ? "Success" : "Fail")
		<< " on isOdd test 1" << endl;
	cout << (isOdd(-1) ? "Success" : "Fail")
		<< " on isOdd test 2" << endl;
	cout << (!isOdd(-2) ? "Success" : "Fail")
		<< " on isOdd test 3" << endl;

	cout << endl; // added this for visual sake when working

	//// test countEs
	cout << (countEs("Elephant") == 2 ? "Success" : "Fail")
		<< " on countEs test 1" << endl;
	cout << (countEs("Aardvark") == 0 ? "Success" : "Fail")
		<< " on countEs test 2" << endl;
	cout << (countEs("Elephantine") == 3 ? "Success" : "Fail")
		<< " on countEs test 3" << endl;

	cout << endl; // added this for visual sake when working

	// test cumulative
	vector<int> v1{ 1, 1, 2, 3, 5 };
	vector<int> v1Cumulative{ 1, 2, 4, 7, 12 };
	cumulative(v1);
	cout << (v1 == v1Cumulative ? "Success" : "Fail")
		// should this have been (cumulative(v1) == v1Cumulative 
		<< " on cumulative test 1" << endl;

	vector<int> v2{ 1 };
	vector<int> v2Cumulative{ 1 };
	cumulative(v2);
	cout << (v2 == v2Cumulative ? "Success" : "Fail")
		<< " on cumulative test 2" << endl;

	vector<int> v3{};
	vector<int> v3Cumulative{};
	cumulative(v3);
	cout << (v3 == v3Cumulative ? "Success" : "Fail")
		<< " on cumulative test 3" << endl;

	cout << endl; // added this for visual sake when working

	//// test factors56
	cout << (factors56(10) == "10 is divisible by 5 or 6, but not both" ? "Success" : "Fail")
		<< " on factors56 test 1" << endl;
	cout << (factors56(30) == "30 is divisible by both 5 and 6" ? "Success" : "Fail")
		<< " on factors56 test 2" << endl;
	cout << (factors56(23) == "23 is not divisible by either 5 or 6" ? "Success" : "Fail")
		<< " on factors56 test 3" << endl;

	system("pause");
}

// TO DO: function definitions go here
double mathRootSum(int num) {
	double answer = 0;
	if (num > 0) {
		for (int i = 1; i <= num; i++) {
			answer += (1 / (sqrt(i) + sqrt(i + 1)));
		}
	}

	return answer;
}
bool isOdd(int num) {
	if (num % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}
int countEs(string word) {
	int howMany = 0;

	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 'e' || word[i] == 'E') {
			howMany++;
		}
	}
	return howMany;
}

string factors56(int num) {

	//if ((num % 10) == 5 || (num % 10) == 0){
	//	if ((num % 2) == 0 && (num % 3) == 0) {
	//		return num + " is divisible by both 5 and 6";
	//	}
	//}


	//else if ((num / 5) == 0 || (num / 6) == 0) {
	//	 return  num + " is divisible by 5 or 6, but not both";
	//}/*
	//else if (num / 6 == 0 && num / 5 == 0) {
	//	return num + " is divisible by both 5 and 6";
	//}*/
	//else {
	//	return num + " is not divisible by either 5 or 6";
	//}
	return num + " is not divisible by either 5 or 6";
}

void cumulative(vector<int> &list) {
	vector<int> made(list.size());
	int calc = 0;
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j <= i; j++) {
			calc = calc + list[j];
		}
		made[i] = calc;
		calc = 0;
	}
	
	for (int z = 0; z < list.size(); z++) {
		list[z] = made[z];
	}
}
