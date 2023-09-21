fin=open("nested list input.txt","r")
stdin=fin.read()
fin.close()
stdin=stdin.split("\n")
records=[]
for i in range(1,int(stdin[0])*2+1,2):
    name=stdin[i]
    score=float(stdin[i+1])
    records.append([name,score])

#records.sort(key=lambda a:a[1])
value=list(sorted(set(b for a,b in records)))[1]
names=[]

for i in range(len(records)):
    if records[i][1]==value:
        names.append(records[i][0])

print('\n'.join(sorted(names)))

"""
last=["",0]
scdLast=["",0]

for i in range(len(records)):
    if i==0:
        last=records[i]
    elif scdLast[0]=="":
        if records[i][1]<last[1]:
            scdLast=last
            last=records[i]
        elif records[i][1]==last[1]:
            last[0]=[last[0],records[i][0]]
        else:
            scdLast=records[i]
    else:
        if records[i][1]<last[1]:
            scdLast=last
            last=records[i]
        elif records[i][1]==last[1]:
            last[0]=[last[0],records[i][0]]
        elif last[1]<records[i][1]<scdLast[1]:
            scdLast=records[i]
        elif records[i][1]==scdLast[1]:
            scdLast[0]=[scdLast[0],records[i][0]]

if type(scdLast[0])==list:
    scdLast[0].sort()
    print('\n'.join(scdLast[0]))
else:
    print(scdLast[0])
"""
