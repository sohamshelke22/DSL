'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statment:

a) Write a Python program to store roll numbers of students in array who attended training program in

random order.

Write function for searching whether particular student attended training program or not, using Linear and

Sentinal Search.

b) Write a python program to store roll numbers of students in array who attended training program in

sorted order.

Write function for searching whether particular student attended training program or not, using Binary and

Fibonacci Search



'''



def linear_search(target, lst1):

    flag = 0

    for i in range(len(lst1)):

        if target == lst1[i]:

            flag = 1

            location = i

            break

    if flag == 1:

        print(f"Student with roll number {target} attended the training program at location {location}")

    else:

        print(f"Student with roll number {target} did not attend the training program")

    return flag



def sentinel_search(arr, key):

    n = len(arr)

    last = arr[n - 1]

    arr[n - 1] = key

    i = 0

    while arr[i] != key:

        i += 1

    arr[n - 1] = last

    if i < n - 1 or arr[n - 1] == key:

        print(f"Student with roll number {key} attended the training program at location {i}")

    else:

        print(f"Student with roll number {key} did not attend the training program")

    return i



def binary_search(arr, key):

    n = len(arr)

    flag = 0

    low = 0

    high = n - 1

    while low <= high:

        mid = (low + high) // 2

        if arr[mid] == key:

            position = mid

            flag = 1

            break

        elif arr[mid] > key:

            high = mid - 1

        else:

            low = mid + 1

    if flag == 1:

        print(f"Student with roll number {key} attended the training program at location {position}")

    else:

        print(f"Student with roll number {key} did not attend the training program")

    return flag



def fibonacci_search(arr, x, n):

    fibMMm2 = 0

    fibMMm1 = 1

    fibM = fibMMm2 + fibMMm1

    while fibM < n:

        fibMMm2 = fibMMm1

        fibMMm1 = fibM

        fibM = fibMMm2 + fibMMm1

    offset = -1

    while fibM > 1:

        i = min(offset + fibMMm2, n - 1)

        if arr[i] < x:

            fibM = fibMMm1

            fibMMm1 = fibMMm2

            fibMMm2 = fibM - fibMMm1

            offset = i

        elif arr[i] > x:

            fibM = fibMMm2

            fibMMm1 -= fibMMm2

            fibMMm2 = fibM - fibMMm1

        else:

            return i

    if fibMMm1 and arr[n - 1] == x:

        return n - 1

    return -1



def main():

    while True:

        print("\n1: Unsorted Array")

        print("  1: Linear Search")

        print("  2: Sentinel Search")

        print("2: Sorted Array")

        print("  1: Binary Search")

        print("  2: Fibonacci Search")

        print("3: Exit")

        ch = int(input("Enter your choice: "))

        if ch >= 3:

            print("End of program")

            break

        elif ch == 1:

            n = int(input("Enter the number of students in array: "))

            lst1 = [int(input("Enter roll number of student: ")) for _ in range(n)]

            target = int(input("Enter roll number of student to search: "))

            ch2 = int(input("Enter your choice of search: "))

            if ch2 == 1:

                linear_search(target, lst1)

            elif ch2 == 2:

                sentinel_search(lst1, target)

        elif ch == 2:

            n = int(input("Enter the number of students in array: "))

            lst1 = [int(input("Enter roll number of student: ")) for _ in range(n)]

            target = int(input("Enter roll number of student to search: "))

            ch2 = int(input("Enter your choice of search: "))

            if ch2 == 1:

                binary_search(lst1, target)

            elif ch2 == 2:

                ind = fibonacci_search(lst1, target, n)

                if ind >= 0:

                    print(f"Found at index: {ind}")

                else:

                    print(f"{target} isn't present in the array")



main()





'''



Output

1: Unsorted Array

  1: Linear Search

  2: Sentinel Search

2: Sorted Array

  1: Binary Search

  2: Fibonacci Search

3: Exit

Enter your choice: 1

Enter the number of students in array: 5

Enter roll number of student: 101

Enter roll number of student: 102

Enter roll number of student: 103

Enter roll number of student: 104

Enter roll number of student: 105

Enter roll number of student to search: 103

Enter your choice of search: 1



Student with roll number 103 attended the training program at location 2



'''
