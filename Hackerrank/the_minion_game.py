def minion_game(string):
    # your code goes here
    
    vowels=["A","E","I","O","U"]

    #find the number of time the word occurs in the string
    def findOccur(string,word):
        occur=0
        for i in range(len(string)-len(word)+1):
            if string[i:i+len(word)]==word:
                occur+=1
        return occur

    #get Stuart's words and number of occurrences
    def stuartFind(string):
        dic={}
        for i in range(len(string)):
            if not string[i] in vowels:
                for f in range(len(string)-i):
                    word=string[i:i+f+1]
                    wordOccur=findOccur(string,word)
                    dic[word]=wordOccur
        return dic

    #get Kevin's words and number of occurrences
    def kevinFind(string):
        dic={}
        for i in range(len(string)):
            if string[i] in vowels:
                for f in range(len(string)-i):
                    word=string[i:i+f+1]
                    wordOccur=findOccur(string,word)
                    dic[word]=wordOccur
        return dic

    #use two functions
    stuart=stuartFind(string)
    kevin=kevinFind(string)

    #find scores of two
    stuartScore=0
    kevinScore=0
    for i in stuart.values():
        stuartScore+=i
    for i in kevin.values():
        kevinScore+=i

    #compare and give result
    if stuartScore>kevinScore:
        print("Stuart "+str(stuartScore))
    elif stuartScore<kevinScore:
        print("Kevin "+str(kevinScore))
    elif stuartScore==kevinScore:
        print("Draw")

s = input()
minion_game(s)
