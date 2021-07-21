#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

static void remove_all_space_from_string(string& word)
{
	int a = 0;

	// We loop through all the letters to find the spaces
	while (a < word.length())
	{
		char letter = word[a];

		// We check if the letter is a space or not and if it IS, we erase that space
		if (isspace(letter))
		{
			word.erase(a, 1);
			// We minus A so that it can still be syced up with the length since we minued 1 from the word's length
			a--;
		}

		// Then finally we increment A and the loop begins again until we have checked all letters of the word;
		a++;
	}
}

static bool is_anagram(string word_one, string word_two)
{
	int a = 0;

	// We remove all the spaces from both words so we can check only the letters
	remove_all_space_from_string(word_one);
	remove_all_space_from_string(word_two);

	// Before we start testing, we make sure their both the same length and if their not, they can't be anagrams
	if (word_one.length() != word_two.length())
		return false;

	// Now that we have cleared all spaces and made sure both words are the same length, 
	// we can begin our loop by checking if A is less then word one's length
	while (a < word_one.length())
	{	
		int b = 0;

		// We make a nested while loop and check each letter of word one with EVERY letter of word two. 
		// If we don't find a match for even one letter, it isn't an anagram and we return false
		while (b < word_two.length())
		{
			// We lowercase all letters so captalisation doesn't get in the way and we check if their the same letter
			if (tolower(word_one[a]) == tolower(word_two[b]))
			{
				// If it is the same letter, we erase both those letters from both words
				word_two.erase(b, 1);
				word_one.erase(a, 1);
				// We decrement A because we are decrementing word one's length by taking out a letter. 
				// So to stay in sync with the length of the word, we minus 1 from A too. We do the same thing with B;
				a--;
				b--;
				break;
			}

			// If the letters don't match, we move on to the next letter by incrementing B and seeing if the next letter matches
			b++;
		}

		// Once the nested while loop is done, we check if B equals word two's length. 
		// We do this because we want to see if it checked all the letters but couldn't find a match, therefore, breaking the while loop.
		// And if there is no letters that match, it's not an anagram so we return false
		if (b == word_two.length())
			return false;

		// Once we have finished this cycle of the while loop, we increment A to go to the next letter and check it all again
		a++;
	}

	// If everything has gone right, it would have gone through all the letters and eventually finished the while loop, 
	// proving that all the letters are the same, and that it's an anagram. So we return true!
	return true;
}

static string take_input()
{
	string word = "";
	getline(cin, word);

	return word;
}

int main()
{
	// We first introduce the person and make them input the two words to check if they are an anagram
	cout << "Welcome to Sal's Anagram Checker! You will need to input 2 words to check. " << endl << endl;

	cout << "Enter the first word here: ";
	string one = take_input();

	cout << endl << endl << "Enter the second word here: ";
	string two = take_input();

	// We check whether those two words are an anagram and we tell the person whether it is or isn't an anagram
	if (is_anagram(one, two) == true)
		cout << endl << "'" << one << "' and '" << two << "' ARE anagrams. " << endl;
	else
		cout << endl << "'" << one << "' and '" << two << "' are NOT anagrams. " << endl;

	// We then exit the program and finish
	return 0;
}

