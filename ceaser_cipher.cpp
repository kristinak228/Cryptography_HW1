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

// G L O B A L S
int MAX_KEY_SIZE = 26;

// user input for mode (decryption or encryption)
string getMode(){

	string mode;
	while(true){
		cout << "[E]ncryption or [D]ecryption?" << endl;
		getline(cin, mode);
		if((mode == "E") || (mode == "D")){
			cout << "Mode received: " << mode << endl;
			return mode;
		} else{
			cout << "Enter either E for Encryption or D for Decryption" << endl;
		}
	}
}

// remove the strings so it's eaiser to work with
string removeSpaces(string str){

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}	

// user input for message
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

// user input for key
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

// encrypts or decrypts
string translateMessage(string mode, string message, int key){

	int size = message.length();
	if(mode == "D") key = -key;
	string new_m;

	for(int i = 0; i < size; ++i){ 
		if(isupper(message[i])){
			int num = int(message[i]);
			num += key;
			if(num > int('Z')) num -= 26;
			else if(num < int('A')) num += 26;
			new_m[i] =+ char(num);
		} else{
			new_m[i] += message[i];
		}
	}

	return new_m; 
}

int main(){

	string message = getMessage();
	int key = getKey();
	string mode = getMode();
	string M = translateMessage(mode, message, key);	

	if(mode == "D"){
		cout << "Decrypted message: " << M << endl;
		for(int i = 0; i < message.length(); ++i){
        	        cout << M[i];
	        }

	}
	else{
		cout << "Encrypted message: " << M << endl;
		for(int i = 0; i < message.length(); ++i){
	                cout << M[i];
        	}

	}	
	
	return 0;
}














