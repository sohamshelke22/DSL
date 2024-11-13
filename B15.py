'''

Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



PROBLEM STATEMENT: Write a python program to store second year percentage

of students in array. Write function for sorting array of floating point numbers in ascending

order using

a) Insertion sort

b) Shell Sort and display top five scores

'''



def insertion_sort(arr):

    for i in range(1, len(arr)):

        key = arr[i]

        j = i - 1

        while j >= 0 and key < arr[j]:

            arr[j + 1] = arr[j]

            j -= 1

        arr[j + 1] = key

    return arr



def shell_sort(arr):

    n = len(arr)

    gap = n // 2

    while gap > 0:

        for i in range(gap, n):

            temp = arr[i]

            j = i

            while j >= gap and arr[j - gap] > temp:

                arr[j] = arr[j - gap]

                j -= gap

            arr[j] = temp

        gap //= 2

    return arr



def display_top_five(arr):

    top_five = arr[-5:]

    top_five.reverse()

    print("Top 5 Scores:")

    for score in top_five:

        print(score)



def main():

    percentages = [78.5, 82.3, 91.2, 74.6, 88.9, 95.5, 69.4, 85.1, 92.7, 73.2]

    print("Original Percentages: ", percentages)

    sorted_arr = []

    choice = 0



    while choice != 4:

        print("\nSelect Sorting Method:")

        print("1. Insertion Sort")

        print("2. Shell Sort")

        print("3. Display top 5 scores")

        print("4. Exit")

        choice = int(input("Enter your choice: "))



        if choice == 1:

            print("\nUsing Insertion Sort:")

            sorted_arr = insertion_sort(percentages.copy())

            print("Sorted Percentages: ", sorted_arr)

        elif choice == 2:

            print("\nUsing Shell Sort:")

            sorted_arr = shell_sort(percentages.copy())

            print("Sorted Percentages: ", sorted_arr)

        elif choice == 3:

            if sorted_arr:

                display_top_five(sorted_arr)

            else:

                print("Please sort the percentages first.")

        elif choice == 4:

            print("END OF PROGRAM")

        else:

            print("Invalid choice! Please select a valid option.")



if __name__ == "__main__":

    main()





'''

Output



Original Percentages: [78.5, 82.3, 91.2, 74.6, 88.9, 95.5, 69.4, 85.1, 92.7, 73.2]

Select Sorting Method:

1. Insertion Sort

2. Shell Sort

3. Display top 5 scores

4. Exit

Enter your choice: 1

Using Insertion Sort:

Sorted Percentages: [69.4, 73.2, 74.6, 78.5, 82.3, 85.1, 88.9, 91.2, 92.7, 95.5]

Select Sorting Method:

1. Insertion Sort

2. Shell Sort

3. Display top 5 scores

4. Exit

Enter your choice: 2

Using Shell Sort:

Sorted Percentages: [69.4, 73.2, 74.6, 78.5, 82.3, 85.1, 88.9, 91.2, 92.7, 95.5]

Select Sorting Method:

1. Insertion Sort

2. Shell Sort

3. Display top 5 scores

4. Exit

Enter your choice: 3

Top 5 Scores:

95.5

92.7

91.2

88.9

85.1

Select Sorting Method:

1. Insertion Sort

2. Shell Sort

3. Display top 5 scores

4. Exit

Enter your choice: 4

END OF PROGRAM 



'''
