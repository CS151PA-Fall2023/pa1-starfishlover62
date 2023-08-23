# PA1: Data Analysis by Sorting (100 points)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Sort an array or vector of structs
* Search an item in an array or vector of structs

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* [CORGIS: The Collection of Really Great, Interesting, Situated Datasets](https://corgis-edu.github.io/corgis)

## Overview and Requirements
For this programming assignment, we are going to write a data analytics program. Users can interact with your program by selecting a menu and following the instructions of the program.

## Program Details

Write a data analytics program using the National Survey of Recent College Graduates. The user interacts with the program in the following manner:

**Step 1**: Show menu to the user, and prompt user to select from the menu. Ensure that the program validates user input. Prompt the user when an invalid menu option is selected.
```
2015 National Survey of Recent College Graduate
1. Top 10 Majors with the Highest Mean Salary
2. Top 10 Majors with the Lowest Mean Salary
3. Top 10 Majors with the Highest Median Salary
4. Top 10 Majors with the Lowest Median Salary
5. What are the Top 5 Majors with the Highest Number of Asians
6. What are the Top 5 Majors with the Lowest Number of Asians
7. What are the Top 5 Majors with the Highest Number of Minorities
8. What are the Top 5 Majors with the Lowest Number of Minorities
9. <Design and implement a menu item that provides information through the data>
10. <Design and implement a menu item that provides information through the data>
11. Display Information for a Specific Major
12. Exit

Select a Menu: _
```
**Step 2**: If the user selects a valid menu, print out the output. Thus, if the user selects menu 1, the output should be
```
Education Major                    Mean Salary
------------------------------------------------
Operations Research                $  117084.88
Economics                          $  109940.97
Electrical Engineering             $  109173.61
Chemical Engineering               $  107650.53
Statistics                         $   99210.87
Mechanical Engineering             $   98533.83
Other Engineering                  $   96287.14
Physics and Astronomy              $   93267.10
Geology                            $   92384.25
Political Science and Government   $   92069.04


Press enter to continue...
```
**Step 3**: Once the user presses enter to continue, show the menu again to the user. The program only exits when the user selects the correct menu to exit.


## Implementation Requirements
- [ ] You **MUST** use data from `graduates2015.csv`, thus part of your program will be loading data from this csv file.
    - [ ] Before you even start writing the code, view the information inside `graduates2015.csv`. Real world data is not perfect and can be messy. Additionally, you also have to consider how you are reading the data from the file. Thus, you will have to [scrub the data](https://www.simplilearn.com/what-is-data-scrubbing-article) to ensure you can load the data properly.
    - [ ] You will load the data from this file into an **array of structs** or **vector of structs**. I will leave this choice to you.

```cpp
struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};
``` 
- [ ] **Menu options 1 to 8** will REQUIRE you to use a sorting algorithm in descending or ascending order. You may use **any of the sorting algorithms** presented in the book.
- [ ] **Menu options 9 and 10** will depend on what information you want to present to the user
- [ ] **Menu option 11** will REQUIRE you to **sort by educationMajor** using **insertion sort** and do a **binary search** depending on the user input. If the user asks for information for Economics, you will display all of the data related to that major. 
- [ ] Your program MUST use the three file structure.

## Challenge Yourself Beyond The Scope of the PA (Not Required)
* Implement using struct and classes. The array/vector of structs will be a member variable of a class and you will create appropriate member functions.
* When prompting the user to enter the name of the education major, allow the user to enter a value not sensitive to the case


## Submitting Assignments
1. Ensure that you `push` your local copy of this PA's repo to GitHub. Verify that the code in GitHub is the same code you have on your local computer.
2. You may continue to update and push your code into this repo as long as it is before the deadline.
3. It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this programming assignment in Canvas. This allows the instructor to be notified of your final submission and that you are ready for grading.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
