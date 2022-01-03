class String:
    def __init__(self,arr):
        self.length = 0
        self.list = []
        for i in arr:
            self.list.append(i)
            self.length = self.length + 1

    def add(self,val):
        self.list.append(val)

    def remove(self,val):
        self.list.remove(val)
        self.length-=1

    def list_strings(self):
        l=String([])
        a = []
        for i in range(self.length):
            if (self.list[i] != ' '):
                a.append(self.list[i])
            else:
                l.add(a)
                a = []
                l.length+=1
        l.add(a)
        l.length += 1
        return l

    def longest(self):
        max=0
        c=0
        d=0
        a=[]
        for i in range(self.length):
            if(self.list[i]!=" "):
                c=c+1
                a.append(self.list[i])
                if (i == self.length-1):
                    if (c > max):
                        d=d+1
                        max = c
                        g = a
            else:
                if(d==0):
                    if(c>max):
                        max=c
                        g=a
                    c=0
                    a=[]
        return g,max

    def frequency(self,i):
        count = 0
        for j in self.list:
            if (j == i):
                count += 1
        return count

    def palindrome(self):
        c=0
        for i in range(self.length):
            if (self.list[i] == self.list[self.length - 1 - i]):
                c=c+1
        if(c==self.length):
            return True
        else:
            return False

    def exists(self,val):
        for i in self.list:
            if(i==val):
                return True
        return False

    def remove_duplicates(self):
        unique=String([])
        for i in range(self.list_strings().length):
            if(unique.exists(self.list_strings().list[i])==False):
                unique.add(self.list_strings().list[i])
                unique.length+=1
        for i in range(unique.length):
                if (unique.list[i] == [] ):
                    unique.remove(unique.list[i])
        return unique

    def word_freq(self):
        for i in range(self.remove_duplicates().length):
            count=0
            for j in range(self.list_strings().length):
                if(self.remove_duplicates().list[i]==self.list_strings().list[j]):
                    count+=1

            print("Frequency of '",end="")
            for j in self.remove_duplicates().list[i]:
                print(j,end="")
            print("' =======>",count)

    def index(self,s2):
            c=0
            for i in range(self.length):
                d = 0
                for j in range(s2.length):
                    if(i+j<self.length):
                        if (self.list[i + j] == s2.list[j]):
                            d = d + 1
                        if d == s2.length:
                            break
                if (d == s2.length):
                    c = c + 1
                    return i
            if(c==0):
                return -1


a = input("Enter the string\n")
l=[]
for i in a:
    l.append(i)
s = String(l)

print("--------------------------------------------------------------------\n")
print("Choices:\n1-To display word with the longest length \n2-To determines the frequency of occurrence of particular character in the string\n3-To check whether given string is palindrome or not\n4-To display index of first appearance of the substring\n5-To count the occurrences of each word in a given string")
print("--------------------------------------------------------------------\n")
while(True):
    choice = int(input("Enter your choice:\n"))
    if choice==1:
        print("Longest word is '",end="")
        for i in range(s.longest()[1]):
            print(s.longest()[0][i],end="")
        print("' and its length is",s.longest()[1])

    elif choice==2:
        a=input("Enter the character for which you want to find frequency:\n")
        print("Frequency of '",a,"' is",s.frequency(a))

    elif choice==3:
        if(s.palindrome()==True):
            print("Given string is Palindrome")
        else:
            print("Given string is not a Palindrome")

    elif choice==4:
        a=input("Enter the substring you want to find out:\n")
        l=[]
        b=0
        for i in a:
            l.append(i)
            b+=1
        s2=String(l)
        print("Index of '",end="")
        for j in range(b):
            print(l[j],end="")
        print("' is",s.index(s2))

    elif choice ==5:
        print("Frequency of each word:\n")
        s.word_freq()

    elif(choice<1 or choice>5 or choice!=0):
        print("Please enter proper choice")

    print("-------------------------------------------------------------------")
    while(True):
        wish=input("Do you wish to continue further? Y/N\n")
        if (wish.upper() == "N"):
            print("Exit Successful\nThank You")
            exit()
        elif(wish.upper()=="Y"):
            break
        else:
            print("Please give correct input\n")
            continue
    print("-------------------------------------------------------------------")



# print("Output: ")
#
# s.longest()
#
# print("Palindrome condition:")
# s.palindrome()
#
# print("Freq of each word is\n")
# s.word_freq()
# b=list(input())
# s2=String(b)
# s.index(s2)
#
# # def substr(self,b):
# #         sub=True
# #         for i in self.list:
# #             if(b.exists(i)==False):
# #                 sub=False
# #                 break
# #         return sub





    # def longest(self):
    #     max = 0
    #     for i in range(self.list_strings().length):
    #         c = 0
    #         for j in self.list_strings().list[i]:
    #             c += 1
    #         if (max < c):
    #             max = c
    #             g = self.list_strings().list[i]
    #     print("Longest Word is '",end="")
    #     for i in range(max):
    #         print(g[i],end="")
    #     print("' and its length is",max)
