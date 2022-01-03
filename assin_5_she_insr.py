class Sort:
    def __init__(self,num):
        self.marks=[]
        self.length=num

    def read(self):
        print("Enter the marks of students")
        for i in range(self.length):
            score=int(input())
            self.marks.append(score)

    def BubbleSort(self):
        r=self.marks.copy()
        for i in range(self.length):
            for j in range(self.length-i-1):
                if(r[j+1]<r[j]):
                    temp=r[j+1]
                    r[j+1]=r[j]
                    r[j]=temp
        return r

    def SelectionSort(self):
        r=[]
        for i in range(self.length):
            r.append(self.marks[i])
        for i in range(self.length):
            min=i
            for j in range(i+1,self.length):
                if(r[j]<r[min]):
                    min=j
            temp = r[min]
            r[min] = r[i]
            r[i] = temp
        return r

    def InsertionSort(self):
        r=self.marks.copy()
        for i in range(1,self.length):
            temp=r[i]
            j=i-1
            while(j>=0 and r[j]>temp):
                r[j+1]=r[j]
                j-=1
            r[j+1]=temp
        return r

    def ShellSort(self):
        r=self.marks.copy()
        gap=self.length//2
        while(gap>0):
            for i in range(self.length):
                temp=r[i]
                j=i
                while(j>=gap and r[j-gap]>temp):
                    r[j]=r[j-gap]
                    j=j-gap
                r[j]=temp
            gap=gap//2
        return r

num=int(input("Enter total number of students:"))
scores=Sort(num)
scores.read()
d=0
print("_______")
print("Choices:\n1-Bubble Sort\n2-Selection Sort\n3-Insertion Sort\n4-Shell Sort")
print("_______")
while(True):
    choice = int(input("Enter your choice:\n"))
    print("_______")
    if choice==1:
        if(d==0):
            d=1
            print("Your Entered array is",scores.marks)
            print("The sorted array is",end=" ")
            if num > 5:
                for i in range(5):
                    print(scores.BubbleSort()[num - i - 1],end=" ")
                print()
            else:
                print(scores.BubbleSort())
        else:
            print("Do you want to continue with the previously accepted array i.e",scores.marks,"? Y/N")
            while (True):
                ch = input()
                if (ch == "Y" or ch == "y"):
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num>5:
                        for i in range(5):
                            print(scores.BubbleSort()[num-i-1],end=" ")
                        print()
                    else:
                        print(scores.BubbleSort())
                    break
                elif (ch == "N" or ch == "n"):
                    num = int(input("Enter total number of students:"))
                    scores = Sort(num)
                    scores.read()
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num>5:
                        for i in range(5):
                            print(scores.BubbleSort()[num-i-1],end=" ")
                        print()
                    else:
                        print(scores.BubbleSort())
                    break
                else:
                    print("Please enter proper choice")
                    continue
    elif choice==2:
        if (d == 0):
            d=1
            print("Your Entered array is",scores.marks)
            print("The sorted array is",end=" ")
            if num > 5:
                for i in range(5):
                    print(scores.SelectionSort()[num - i - 1],end=" ")
                print()
            else:
                print(scores.SelectionSort())
        else:
            print("Do you want to continue with the previously accepted array i.e",scores.marks,"? Y/N")
            while(True):
                ch=input()
                if(ch=="Y" or ch=="y"):
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num > 5:
                        for i in range(5):
                            print(scores.SelectionSort()[num - i - 1],end=" ")
                        print()
                    else:
                        print(scores.SelectionSort())
                    break
                elif(ch=="N" or ch=="n"):
                    num = int(input("Enter total number of students:"))
                    scores = Sort(num)
                    scores.read()
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num > 5:
                        for i in range(5):
                            print(scores.SelectionSort()[num - i - 1],end=" ")
                        print()
                    else:
                        print(scores.SelectionSort())
                    break
                else:
                    print("Please enter proper choice")
                    continue
    elif(choice==3):
            if (d == 0):
                d = 1
                print("Your Entered array is",scores.marks)
                print("The sorted array is",end=" ")
                if num > 5:
                    for i in range(5):
                        print(scores.InsertionSort()[num - i - 1],end=" ")
                    print()
                else:
                    print(scores.InsertionSort())
                break
            else:
                print("Do you want to continue with the previously accepted array i.e",scores.marks,"? Y/N")
                while (True):
                    ch = input()
                    if (ch == "Y" or ch == "y"):
                        print("Your Entered array is",scores.marks)
                        print("The sorted array is",end=" ")
                        if num > 5:
                            for i in range(5):
                                print(scores.InsertionSort()[num - i - 1],end=" ")
                            print()
                        else:
                            print(scores.InsertionSort())
                        break
                    elif (ch == "N" or ch == "n"):
                        num = int(input("Enter total number of students:"))
                        scores = Sort(num)
                        scores.read()
                        print("Your Entered array is",scores.marks)
                        print("The sorted array is",end=" ")
                        if num > 5:
                            for i in range(5):
                                print(scores.InsertionSort()[num - i - 1],end=" ")
                            print()
                        else:
                            print(scores.InsertionSort())
                        break
                    else:
                        print("Please enter proper choice")
                        continue
    elif(choice == 4):
        if (d == 0):
            d = 1
            print("Your Entered array is",scores.marks)
            print("The sorted array is",end=" ")
            if num > 5:
                for i in range(5):
                    print(scores.InsertionSort()[num - i - 1],end=" ")
                print()
            else:
                print(scores.InsertionSort())
        else:
            print("Do you want to continue with the previously accepted array i.e",scores.marks,"? Y/N")
            while (True):
                ch = input()
                if (ch == "Y" or ch == "y"):
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num > 5:
                        for i in range(5):
                            print(scores.ShellSort()[num - i - 1],end=" ")
                        print()
                    else:
                        print(scores.ShellSort())
                    break

                elif (ch == "N" or ch == "n"):
                    num = int(input("Enter total number of students:"))
                    scores = Sort(num)
                    scores.read()
                    print("Your Entered array is",scores.marks)
                    print("The sorted array is",end=" ")
                    if num > 5:
                        for i in range(5):
                            print(scores.ShellSort()[num - i - 1],end=" ")
                        print()
                    else:
                        print(scores.ShellSort())
                    break
                else:
                    print("Please enter proper choice")
                    continue

    else:
        print("Enter Proper Choice")
    print("_______")
    while (True):
        wish = input("Do you wish to continue further? Y/N\n")
        if (wish.upper() == "N"):
            print("Exit Successful\nThank You")
            exit()
        elif (wish.upper() == "Y"):
            break
        else:
            print("Please give correct input\n")
            print("_______")
            continue
    print("_______")
