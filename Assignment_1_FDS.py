class Set:
    def __init__(self,length):
        self.list=[]
        self.length=length

    def exists(self,val):
        for i in self.list:
            if(i==val):
                return True
        return False

    def addelement(self):
        print("Enter the id's of student:")
        a=0
        for i in range(self.length):
            val=int(input())
            if(self.exists(val)==False and isinstance(val,int)):
                self.list.append(val)
                a=a+1
        self.length=a

    def add(self,val):
        self.list.append(val)

    def remove(self,val):
        self.list.remove(val)
        self.length -= 1

    def union(self,b):
        l3Uni=Set(0)
        for i in range(self.length):
            l3Uni.add(self.list[i])
            l3Uni.length +=1
        for i in range(b.length):
            if(self.exists(b.list[i])==False):
                l3Uni.add(b.list[i])
                l3Uni.length += 1
        return l3Uni

    def intersection(self,b):
        l3int=Set(0)
        for i in range(b.length):
            if(self.exists(b.list[i])):
                l3int.add(b.list[i])
                l3int.length += 1
        return l3int

    def subset(self,b):
        sub=True
        for i in range(self.length):
            if(b.exists(self.list[i])==False):
                sub=False
                break
        return sub

    def difference(self,b):
        l3diff=Set(0)
        for i in range(self.length):
                    l3diff.add(self.list[i])
                    l3diff.length += 1
        for i in range(self.intersection(b).length):
                    if(l3diff.exists(self.intersection(b).list[i])):
                        l3diff.remove(self.intersection(b).list[i])
        return l3diff

    def symmetric_difference(self,b):
        x=self.union(b)
        y=self.intersection(b)
        for j in range(y.length):
            if(x.exists(y.list[j])):
                x.remove(y.list[j])
        return x

    def display(self):
        return (self.list)

c=int(input("Enter the number of students who play cricket:\n"))
Cricket=Set(c)
Cricket.addelement()
print("-------------------------------------------------------------------")
f=int(input("Enter the number of students who play football:\n"))
Football=Set(f)
Football.addelement()
print("-------------------------------------------------------------------")
b=int(input("Enter the number of students who play badminton:\n"))
Badminton=Set(b)
Badminton.addelement()
print("-------------------------------------------------------------------")
print("Cricket:",Cricket.display())
print("Football:",Football.display())
print("Badminton:",Badminton.display())
print("\n--------------------------------------------------------------------\n")
print("Choices:\n1-List of students who play both cricket and badminton \n2-List of students who play either cricket or badminton but not both\n3-Number of students who play neither cricket nor badminton\n4-Number of students who play cricket and football but not badminton")
print("\n--------------------------------------------------------------------\n")

while(True):
    choice = int(input("Enter your choice:\n"))
    if choice==1:
        print("List of students who play both cricket and badminton:")
        print(Badminton.intersection(Cricket).display())

    elif choice==2:
        print("List of students who play either cricket or badminton but not both:")
        print(Badminton.symmetric_difference(Cricket).display())

    elif choice==3:
        print("List of students who play neither cricket nor badminton:")
        print(Football.difference((Cricket.union(Badminton))).display())
        print("Number of students who play neither cricket nor badminton are",(Football.difference(Cricket.union(Badminton)).length))

    elif choice==4:
        print("List of students who play cricket and football but not badminton:")
        print((Cricket.intersection(Football)).difference(Badminton).display())
        print("Number of students who play cricket and football but not badminton:",((Cricket.intersection(Football)).difference(Badminton)).length)

    elif(choice<1 or choice>4 or choice!=0):
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
            print("-------------------------------------------------------------------")
            continue
    print("\n-------------------------------------------------------------------")

