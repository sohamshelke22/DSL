'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statment:

Write a Python program to store marks scored in the subject "Fundamental of # Data Structure" by   N students in the class. Write functions to compute the  following: 

 a) The average score of the class 

 b) Highest score and lowest score of the class 

 c) Count of students who were absent for the test 

 d) Display mark with the highest frequency



'''



def countAbsent(marksList):

    absentCount = 0

    for mark in marksList:

        if mark == 0:

            absentCount += 1

    return absentCount



def findMaxMin(marksList):

    maxScore = minScore = marksList[0]

    for mark in marksList:

        if mark > maxScore:

            maxScore = mark

        if mark < minScore:

            minScore = mark

    return maxScore, minScore



def calcAverage(marksList):

    totalMarks = sum(marksList)

    return totalMarks / len(marksList)



def getFreqMark(marksList):

    freq = {}

    for mark in marksList:

        if mark in freq:

            freq[mark] += 1

        else:

            freq[mark] = 1



    maxFreq = 0

    markWithMaxFreq = None

    for mark in freq:

        if freq[mark] > maxFreq:

            maxFreq = freq[mark]

            markWithMaxFreq = mark

    return markWithMaxFreq, maxFreq



def displayMenu():

    print("\nSelect Your Choice:")

    print("1. Average Score")

    print("2. Highest and Lowest Score")

    print("3. Count of Absent Students")

    print("4. Mark with Highest Frequency")

    print("5. Exit")



def main():

    marksList = []

    totalStudents = int(input("Enter the number of students: "))

    

    for i in range(totalStudents):

        mark = int(input(f"Enter marks for student {i + 1}: "))

        marksList.append(mark)



    while True:

        displayMenu()

        choice = input("Enter your choice: ")



        if choice == "1":

            avg = calcAverage(marksList)

            print("Average marks obtained by students is:", avg)

        elif choice == "2":

            maxMarks, minMarks = findMaxMin(marksList)

            print("Highest marks obtained by students is:", maxMarks)

            print("Lowest marks obtained by students is:", minMarks)

        elif choice == "3":

            absentCount = countAbsent(marksList)

            print("Number of students absent for the test are:", absentCount)

        elif choice == "4":

            markWithMaxFreq, maxFreq = getFreqMark(marksList)

            print(f"Mark with the highest frequency is: {markWithMaxFreq} (Frequency: {maxFreq})")

        elif choice == "5":

            print("Exiting the program. Thank you!")

            break

        else:

            print("Invalid choice, please try again.")



main()







'''

OUTPUT

Enter the number of students: 5

Enter marks for student 1: 65

Enter marks for student 2: 0

Enter marks for student 3: 85

Enter marks for student 4: 25

Enter marks for student 5: 76



Select Your Choice

1. Average Score

2. Highest and Lowest Score

3. Count of Absent Students

4. Mark with Highest Frequency

5. Exit

Enter your choice: 1

Average marks obtained by students is: 50.2

Enter your choice: 2

Highest marks obtained by students is: 85

Lowest marks obtained by students is: 0

Enter your choice: 3

Number of students absent for the test are: 1

Enter your choice: 4

Mark with the highest frequency is: 65(Frequency: 1)

Enter your choice: 5

Exiting the program. Thank you!



=== Code Execution Successful ===

'''
