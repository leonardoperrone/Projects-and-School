def calculation(numerator, totHours):
    return numerator / totHours


gradeMapping = {'A+': 4, 'A': 4, 'A-': 3.70, 'B+': 3.30, 'B': 3,'B-': 2.70, 'C+': 2.30, 'C': 2, 'C': 1.70, 'D': 1, 'F': 0};

grades = []
num = 0.00
totalHours = 0.00

classes = input("Number of courses taken: ")

for i in range(0, classes):
    grade = str(raw_input("Grade: ")).upper()
    creditHours = input("Credit Hours: ")
    if grade in gradeMapping:
        num += gradeMapping[grade] * creditHours
    totalHours += creditHours

print('Your GPA is ' + str(round(calculation(num, totalHours), 2)))
