l=int(input())
w=l*5+l-1
for i in range(l):
    s=" "*(l-i-1)+"H"*(i*2+1)
    print(s)
for i in range(l+1):
    s="H"*l+" "*l*3+"H"*l
    print(s.rjust(int(w-(l-1)/2)," "))
for i in range(int((l+1)/2)):
    s="H"*l*5
    print(s.rjust(int(w-(l-1)/2)," "))
for i in range(l+1):
    s="H"*l+" "*l*3+"H"*l
    print(s.rjust(int(w-(l-1)/2)," "))
for i in range(l):
    s="H"*((l-i-1)*2+1)+" "*(i)
    print(s.rjust(w," "))
