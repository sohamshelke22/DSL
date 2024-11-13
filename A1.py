'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

In a second year computer engineering class, group A students

play cricket, group B students play badminton and group C students play football. Write a

python program using functions to compute following:

a) List of students who play both cricket and badminton.

b) List of students who play either cricket or badminton but not both.

c) Number of students who play neither cricket nor badminton.

d) Number of students who play cricket and football but not badminton.

(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET

built-in functions) 

'''





def removeDuplicate(d):

    lst = []

    for i in d:

        if i not in lst:

            lst.append(i)

    return lst



def intersection(lst1, lst2):

    lst3 = []

    for val in lst1:

        if val in lst2:

            lst3.append(val)

    return lst3



def union(lst1, lst2):

    lst3 = lst1.copy()

    for val in lst2:

        if val not in lst3:

            lst3.append(val)

    return lst3



def diff(lst1, lst2):

    lst3 = []

    for val in lst1:

        if val not in lst2:

            lst3.append(val)

    return lst3



def sym_diff(lst1, lst2):

    D1 = diff(lst1, lst2)

    D2 = diff(lst2, lst1)

    return union(D1, D2)



def candb(lst1, lst2):

    lst3 = intersection(lst1, lst2)

    print("\n\nList of students who play both cricket and badminton is:", lst3)

    return len(lst3)



def corbnotboth(lst1, lst2):

    lst3 = sym_diff(lst1, lst2)

    print("\nList of students who play either cricket or badminton but not both is:", lst3)

    return len(lst3)



def nCnB(lst1, lst2, lst3):

    lst4 = diff(lst1, union(lst2, lst3))

    print("\n\nList of students who play neither cricket nor badminton is:", lst4)

    return len(lst4)



def candfnotb(lst1, lst2, lst3):

    lst4 = diff(intersection(lst1, lst2), lst3)

    print("\n\nList of students who play cricket and football but not badminton is:", lst4)

    return len(lst4)



all_students = []

n = int(input("\nEnter total number of students: "))

print(f"Enter the names of {n} students:")

for i in range(n):

    ele = input()

    all_students.append(ele)



print("All students:", all_students)



Cricket = []

n = int(input("\n\nEnter number of students who play cricket: "))

print(f"Enter the names of {n} students who play cricket:")

for i in range(n):

    ele = input()

    Cricket.append(ele)



Cricket = removeDuplicate(Cricket)

print("The list of students playing cricket:", Cricket)



Football = []

n = int(input("\n\nEnter number of students who play football: "))

print(f"Enter the name of {n} students who play football:")

for i in range(n):

    ele = input()

    Football.append(ele)



Football = removeDuplicate(Football)

print("The list of students playing football:", Football)



Badminton = []

n = int(input("\n\nEnter number of students who play badminton: "))

print(f"Enter the name of {n} students who play badminton:")

for i in range(n):

    ele = input()

    Badminton.append(ele)



Badminton = removeDuplicate(Badminton)

print("The list of students playing badminton:", Badminton)



while True:

    print("\n\n--------------------MENU--------------------\n")

    print("1. List of students who play both cricket and badminton")

    print("2. List of students who play either cricket or badminton but not both")

    print("3. List of students who play neither cricket nor badminton")

    print("4. Number of students who play cricket and football but not badminton")

    print("5. Exit\n")

    

    ch = int(input("Enter your Choice (from 1 to 5): "))

    

    if ch == 1:

        print("Number of students who play both cricket and badminton:", candb(Cricket, Badminton))

    elif ch == 2:

        print("Number of students who play either cricket or badminton but not both:", corbnotboth(Cricket, Badminton))

    elif ch == 3:

        print("Number of students who play neither cricket nor badminton:", nCnB(all_students, Cricket, Badminton))

    elif ch == 4:

        print("Number of students who play cricket and football but not badminton:", candfnotb(Cricket, Football, Badminton))

    elif ch == 5:

        print("End of program")

        break

    else:

        print("!!Wrong Choice!!")



'''

Output

Enter total number of students: 5

Enter the names of 5 students:

Alice

Bob

Charlie

David

Eve

All students: ['Alice', 'Bob', 'Charlie', 'David', 'Eve']

Enter number of students who play cricket: 3

Enter the names of 3 students who play cricket:

Alice

Bob

Charlie

The list of students playing cricket: ['Alice', 'Bob', 'Charlie']

Enter number of students who play football: 2

Enter the name of 2 students who play football:

Bob

David

The list of students playing football: ['Bob', 'David']

Enter number of students who play badminton: 3

Enter the name of 3 students who play badminton:

Charlie

David

Eve

The list of students playing badminton: ['Charlie', 'David', 'Eve']

--------------------MENU--------------------

1. List of students who play both cricket and badminton

2. List of students who play either cricket or badminton but not both

3. List of students who play neither cricket nor badminton

4. Number of students who play cricket and football but not badminton

5. Exit

Enter your Choice (from 1 to 5): 1

List of students who play both cricket and badminton is: ['Charlie']

Number of students who play both cricket and badminton: 1

--------------------MENU--------------------

1. List of students who play both cricket and badminton

2. List of students who play either cricket or badminton but not both

3. List of students who play neither cricket nor badminton

4. Number of students who play cricket and football but not badminton

5. Exit

Enter your Choice (from 1 to 5): 2

List of students who play either cricket or badminton but not both is: ['Alice', 'Bob', 'David',

'Eve']

Number of students who play either cricket or badminton but not both: 4

--------------------MENU--------------------

1. List of students who play both cricket and badminton

2. List of students who play either cricket or badminton but not both

3. List of students who play neither cricket nor badminton

4. Number of students who play cricket and football but not badminton

5. Exit

Enter your Choice (from 1 to 5): 3

List of students who play neither cricket nor badminton is: []

Number of students who play neither cricket nor badminton: 0

--------------------MENU--------------------

1. List of students who play both cricket and badminton

2. List of students who play either cricket or badminton but not both

3. List of students who play neither cricket nor badminton

4. Number of students who play cricket and football but not badminton

5. Exit

Enter your Choice (from 1 to 5): 4

List of students who play cricket and football but not badminton is: ['Bob']

Number of students who play cricket and football but not badminton: 1

--------------------MENU--------------------

1. List of students who play both cricket and badminton

2. List of students who play either cricket or badminton but not both

3. List of students who play neither cricket nor badminton

4. Number of students who play cricket and football but not badminton

5. Exit

Enter your Choice (from 1 to 5): 5

End of program

'''
