'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



PROBLEM STATEMENT: Write a Python program to store first year percentage of

students in array. Write function for sorting array of floating point numbers in ascending

order using

a)Selection Sort

b)Bubble sort and display top five scores. 

'''



def selection_sort(arr):

    for i in range(len(arr)):

        min_index = i

        for j in range(i + 1, len(arr)):

            if arr[j] < arr[min_index]:

                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr



def bubble_sort(arr):

    n = len(arr)

    for i in range(n):

        for j in range(0, n - i - 1):

            if arr[j] > arr[j + 1]:

                # Swap if the element found is greater than the next element

                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr



def display_top_five(arr):

    print("Top 5 Scores:")

    for i in range(-1, -6, -1):

        print(arr[i])



percentages = [85.5, 78.3, 92.1, 88.7, 70.5, 95.3, 89.4, 81.9, 73.6, 67.8]



print("Unsorted:", percentages)



sorted_selection = selection_sort(percentages.copy())

print("Sorted using Selection Sort:", sorted_selection)

display_top_five(sorted_selection)



sorted_bubble = bubble_sort(percentages.copy())

print("\nSorted using Bubble Sort:", sorted_bubble)

display_top_five(sorted_bubble)



'''

Output:

Unsorted: [85.5, 78.3, 92.1, 88.7, 70.5, 95.3, 89.4, 81.9, 73.6, 67.8]

Sorted using Selection Sort: [67.8, 70.5, 73.6, 78.3, 81.9, 85.5, 88.7, 89.4, 92.1, 95.3]

Top 5 Scores:

95.3

92.1

89.4

88.7

85.5

Sorted using Bubble Sort: [67.8, 70.5, 73.6, 78.3, 81.9, 85.5, 88.7, 89.4, 92.1, 95.3]

Top 5 Scores:

95.3

92.1

89.4

88.7

85.5 

'''
