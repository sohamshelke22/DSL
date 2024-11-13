'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



PROBLEM STATEMENT: Write a Python program to compute following operations on String:

a) To display word with the longest length

b) To determines the frequency of occurrence of particular character in the string

c) To check whether given string is palindrome or not

d) To display index of first appearance of the substring

e) To count the occurrences of each word in a given string

'''



def longest_word(sentence):

    words = sentence.split()

    longest = max(words, key=len)

    return longest



def char_frequency(string, char):

    count = string.count(char)

    return count



def word_frequency(sentence):

    words = sentence.split()

    frequency = {}

    for word in words:

        if word in frequency:

            frequency[word] += 1

        else:

            frequency[word] = 1

    return frequency



def is_palindrome(string):

    clean_string = string.replace(" ", "").lower()

    return clean_string == clean_string[::-1]



def find_substring_index(string, substring):

    index = string.find(substring)

    if index != -1:

        return index

    else:

        return "Substring not found"



str = input("Enter string: ")



while True:

    print("\n\n--------------------MENU--------------------\n")

    print("1. To display word with longest length")

    print("2. To determine the frequency of occurrence of a particular character in the string")

    print("3. To check whether the given string is palindrome or not")

    print("4. To display index of first appearance of substring")

    print("5. To count the occurrence of each word in the given string")

    print("6. Exit\n")



    ch = int(input("Enter your Choice (from 1 to 6): "))



    if ch == 1:

        print("The longest word is:", longest_word(str))

    elif ch == 2:

        char = input("Enter character to be counted: ")

        print(f"The character '{char}' appears {char_frequency(str, char)} times.")

    elif ch == 3:

        if is_palindrome(str):

            print(f"'{str}' is a palindrome.")

        else:

            print(f"'{str}' is not a palindrome.")

    elif ch == 4:

        sub = input("Enter substring: ")

        print(f"The index of the first appearance of '{sub}' is: {find_substring_index(str, sub)}")

    elif ch == 5:

        print(f"Occurrence of each word: {word_frequency(str)}")

    elif ch == 6:

        print("End of program")

        break

    else:

        print("Invalid choice")



'''

Output

Enter string: python is a great programming language

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

Enter your Choice (from 1 to 6) :3

'python is a great programming language' is not a palindrome.

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

Enter your Choice (from 1 to 6) :5

Occurrence of each word: {'python': 1, 'is': 1, 'a': 1, 'great': 1, 'programming': 1, 'language': 1}

--------------------MENU--------------------

1. To display word with longest length

2. To determine the frequency of occurrence of particular character in string

3. To check whether given string is palindrome or not

4. To display index of first appearance of substring

5. To count the occurrence of each word in given string

6. Exit

Enter your Choice (from 1 to 6) :6

End of program 

'''
