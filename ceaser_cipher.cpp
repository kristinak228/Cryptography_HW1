/*
 * Kristina Kolibab
 * Prof. Tino - CS 456
 * Assignment 1
 *
 * Compiling: g++ -o cchiper ceaser_cipher.cpp -std=c++11
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Encrypting
// e(x) = (x+k)(mod 26)

// where x is the letter you're encrypting/decrypting
// and the key is the number of letters you're shifting

// Decrypting
// e(x) = (x - k)(mod 26)

// turn the alphabet into digits 0-25 first

int MAX_KEY_SIZE = 26;

string removeSpaces(string str){
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}	

string getMessage(){
	// prompt user for message
	cout << "Enter you message: " << endl;
	string m; 
	getline(cin, m);

	// remove spaces in message
	m = removeSpaces(m);
	transform(m.begin(), m.end(), m.begin(), ::toupper);
	cout << "Message received: " << m << endl;
	return m;	
}

int getKey(){
	string Skey;
	int key;
	do{
		cout << "Enter a shift key between 0-26: ";
		getline(cin, Skey);
		istringstream(Skey) >> key;	
	}while(key < 0 || key > MAX_KEY_SIZE);
	cout << "Key received: " << key << endl;
	return key;
}

int main(){
	string message;
	message = getMessage();
	int key = getKey();

	return 0;
}
