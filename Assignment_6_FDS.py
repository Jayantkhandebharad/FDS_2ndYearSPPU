class Sort:
    def __init__(self,num):
        self.marks=[]
        self.length=num

    def read(self):
        print("Enter the marks of students")
        for i in range(self.length):
            score=int(input())
            self.marks.append(score)

    def partition(self,low,high):
        key = self.marks[low]
        i = low
        j = high
        while (i < j):
            while (i < high and self.marks[i] <= key):
                i += 1
            while (j >= low and self.marks[j] > key):
                j -= 1
            if (i < j):
                temp1 = self.marks[i]
                self.marks[i] = self.marks[j]
                self.marks[j] = temp1
        temp2 = self.marks[low]
        self.marks[low] = self.marks[j]
        self.marks[j] = temp2

        return j


    def QuickSort(self,low,high):
        if (low < high):
            p = self.partition(low,high)
            self.QuickSort(p + 1,high)
            self.QuickSort(low,p - 1)


while (True):
    num = int(input("Enter total number of students:"))
    scores = Sort(num)
    scores.read()
    print("The array given is:")
    print(scores.marks)
    scores.QuickSort(0,num - 1)
    print("The sorted array is:")
    print(scores.marks)
    print("********************************************************************")
    wish = input("Do you wish to continue further? Y/N\n")
    if (wish.upper() == "N"):
        print("Exit Successful\nThank You")
        exit()
    elif (wish.upper() == "Y"):
        continue
    else:
        print("Please give correct input\n")
        print("********************************************************************")
        continue
print("********************************************************************")
