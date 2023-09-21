def delOccurance(a,b):
    while b in a:
        
def merge_the_tools(string, k):
    # your code goes here
    n=len(string)
    u=[]
    q=int(n/k)
    for i in range(q):
        a=string[i*k:(i+1)*k]
        o=0
        while o<=len(a)-1:
            while a[o] in a[:o]:
                if o>len(a)-1:
                    a=a[:o]+a[o+1:]
                elif o==len(a)-1:
                    a=a[:o]+a[-1:]
                if o>len(a)-1:
                    break
            o+=1
        u.append(a)
    for i in u:
        print(i)
        
string, k = input(), int(input())
merge_the_tools(string, k)
