import math

fin=open("finding the percentage input.txt","r")
stdin=fin.read()
fin.close()

stdin=stdin.split("\n")
student_marks={}
for i in range(1,int(stdin[0])+1):
    name,*marks=stdin[i].split()
    score=list(map(float,marks))
    student_marks[name]=score
query_name=stdin[-1]

avg=sum(student_marks[query_name])/len(student_marks[query_name])
print("{0:.2f}".format(avg))
