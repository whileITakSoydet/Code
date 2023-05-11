#include <iostream>
#include <string>

using namespace std;

string codeCaesar();

string decodeCaesar(string code, int key);

string codeVigenere();

string decodeVigenere(string code, string key);

int main()
{
	//cout << codeCaesar() << endl;
	//cout << decodeCaesar("ifmmp ZZzz aaAA", 1);
	//cout << codeVigenere() << endl;
	//cout << decodeVigenere("HFNLP", "ABC") << endl;

	return 0;
}

string codeCaesar()
{
	string word, code;
	int ch;
	int key;
	cout << "Enter word:\n";
	getline(cin, word);
	code = word;
	cout << "Enter key:\n";
	cin >> key;
	for (int i = 0; i < word.length(); i++)
	{
		ch = (int)word[i];
		if (ch >= 65 && ch <=90)
		{
			ch += key;
			if (ch > 90) 
			{
				code[i] = (char)(ch % 90 + 64);
				continue;
			}
			code[i] = (char)ch;
		}
		if (ch >= 97 && ch <= 122)
		{
			ch += key;
			if (ch > 122)
			{
				code[i] = (char)(ch % 122 + 96);
				continue;
			}
			code[i] = (char)ch;
		}
	}
	return code;
}

string decodeCaesar(string code, int key)
{
	string word = code;
	int ch;
	for (int i = 0; i < code.length(); i++)
	{
		ch = (int)code[i];
		if (ch >= 65 && ch <= 90)
		{
			ch -= key;
			if (ch < 65)
			{
				word[i] = (char)(90 - 65 % ch);
				continue;
			}
			word[i] = (char)ch;
		}
		if (ch >= 97 && ch <= 122)
		{
			ch -= key;
			if (ch < 97)
			{
				word[i] = (char)(122 - 96 % ch);
				continue;
			}
			word[i] = (char)ch;
		}
	}
	return word;
}

string codeVigenere()
{
	string word, key, code;
	int valChar, valKey;
	cout << "Enter word or text for encryption: ";
	getline(cin, word);
	code = word;
	cout << "Enter word - key: ";
	getline(cin, key);
	for (int i = 0; i < word.length(); i++)
	{
		valChar = word[i];
		valKey = key[i % key.length()];

		if (valKey >= 65 && valKey <= 90)
		{
			valKey %= 65;
		}
		if (valKey >= 97 && valKey <= 122)
		{
			valKey %= 97;
		}
		if (valChar >= 65 && valChar <= 90)
		{
			valChar += valKey;
			if (valChar > 90)
			{
				code[i] = (char)(valChar % 90 + 64);
				continue;
			}
			code[i] = (char)valChar;
		}
		if (valChar >= 97 && valChar <= 122)
		{
			valChar += valKey;
			if (valChar > 122)
			{
				code[i] = (char)(valChar % 122 + 96);
				continue;
			}
			code[i] = (char)valChar;
		}
	}
	return code;
}

string decodeVigenere(string code, string key)
{
	string word = code;
	int valChar, valKey;
	for (int i = 0; i < code.length(); i++)
	{
		valChar = code[i];
		valKey = key[i % key.length()];

		if (valKey >= 65 && valKey <= 90)
		{
			valKey %= 65;
		}
		if (valKey >= 97 && valKey <= 122)
		{
			valKey %= 97;
		}
		if (valChar >= 65 && valChar <= 90)
		{
			valChar -= valKey;
			if (valChar < 65)
			{
				word[i] = (char)(90 - 65 % valChar);
				continue;
			}
			word[i] = (char)valChar;
		}
		if (valChar >= 97 && valChar <= 122)
		{
			valChar += valKey;
			if (valChar < 97)
			{
				word[i] = (char)(122 - 97 % valChar);
				continue;
			}
			word[i] = (char)valChar;
		}
	}
	return word;
}