N = int(input())
students = []

for _ in range(N):
    name, math, science, english = input().split()
    students.append({
        "name": name,
        "math": int(math),
        "science": int(science),
        "english": int(english)
    })

order, subject = input().split()

reverse = True if order == "desc" else False

students_sorted = sorted(students, key=lambda x: x[subject], reverse=reverse)

for student in students_sorted:
    print(student["name"])