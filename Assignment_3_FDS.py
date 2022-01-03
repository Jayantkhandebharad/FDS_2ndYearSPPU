class Matrix:
    def __init__(self,rows,cols):
        self.rows=rows
        self.cols=cols
        self.list=[]

    def add(self,i):
        self.list.append(i)

    def display(self):
        if (self.rows != 0 and self.cols != 0):
            for i in range(self.rows):
                # for j in range(self.cols):
                print(self.list[i])
            # print()
        else:
            print("Not Possible")

    def addelement(self):
        print("Elements to be added in matrix:")
        for i in range(self.rows):
            c=[]
            for j in range(self.cols):
                c.append(float(input()))
            self.list.append(c)

    def addmatrix(self,m2):
        a=Matrix(0,0)
        if((self.rows==m2.rows) and (self.cols==m2.cols)):
            for i in range(self.rows):
                c=[]
                for j in range(self.cols):
                    c.append(self.list[i][j]+m2.list[i][j])

                a.add(c)
                a.rows=self.rows
                a.cols = self.cols
        return a

    def difference(self,m2):
        a=Matrix(0,0)

        if((self.rows==m2.rows) and (self.cols==m2.cols)):
            for i in range(self.rows):
                c=[]
                for j in range(self.cols):
                    c.append(self.list[i][j]-m2.list[i][j])
                a.add(c)
                a.rows = self.rows
                a.cols = self.cols
        return a

    def transpose(self):
        a=Matrix(0,0)
        for i in range(self.cols):
            b =[]
            for j in range(self.rows):
                b.append(self.list[j][i])
            a.add(b)
        a.rows=self.cols
        a.cols=self.rows
        return a

    def product(self,m2):
        a = Matrix(0,0)
        if(self.cols==m2.rows):

            for i in range(self.rows):
                b=[]
                for j in range(m2.cols):
                    sum=0
                    for k in range(m2.rows):
                        sum=sum+self.list[i][k]*m2.list[k][j]
                    b.append(sum)

                a.add(b)
            a.rows =self.rows
            a.cols =m2.cols
        return a

rows1 = int(input("Enter number of rows in Matrix1:"))
cols1 = int(input("Enter number of columns in Matrix1:"))
m1 = Matrix(rows1,cols1)
m1.addelement()

rows2 = int(input("Enter number of rows in Matrix2:"))
cols2 = int(input("Enter number of columns in Matrix2:"))
m2 = Matrix(rows2,cols2)
m2.addelement()


print("--------------------------------------------------------------------")
print("Choices:\n1-Modify the Matrix\n2-Display the Matrix\n3-Addition of Matrices \n4-Difference of Matrices\n5-Product of Matrices\n6-Transpose of Matrix 1\n7-Transpose of Matrix 2")
print("--------------------------------------------------------------------\n")

while(True):
    choice = int(input("Enter your choice:\n"))
    if choice ==1:
        while(True):
            c=0
            print("Which matrix do you want to modify?\n1-m1\n2-m2")
            ch=int(input())
            if(ch==1):
                rows1 = int(input("Enter number of rows in Matrix1:"))
                cols1 = int(input("Enter number of columns in Matrix1:"))
                m1 = Matrix(rows1,cols1)
                m1.addelement()
            elif(ch==2):
                rows2 = int(input("Enter number of rows in Matrix2:"))
                cols2 = int(input("Enter number of columns in Matrix2:"))
                m2 = Matrix(rows2,cols2)
                m2.addelement()
            else:
                print("Please enter proper choice")
            while (True):
                print("-------------------------------------------------------------------")
                w = input("Do you wish to continue modification? Y/N")
                if (w.upper() == "N"):
                    c=1
                    break
                elif (w.upper() == "Y"):
                    break
                else:
                    print("Please give correct input")
                    print("-------------------------------------------------------------------")
                    continue
            if(c==1):
                break
            else:
                continue
    elif choice==2:
        print("Matrix 1:")
        m1.display()
        print("\nMatrix 2:")
        m2.display()
    elif choice==3:
        print("Addition of Matrices:")
        (m1.addmatrix(m2)).display()

    elif choice==4:
        print("Difference of Matrices i.e. (m1-m2):")
        (m1.difference(m2)).display()

    elif choice==5:
        print("Product of Matrices i.e. (m1*m2):")
        (m1.product(m2)).display()

    elif choice==6:
        print("Transpose of Matrix 1:")
        (m1.transpose()).display()

    elif choice==7:
        print("Transpose of matrix2:")
        (m2.transpose()).display()

    elif(choice<1 or choice>7):
        print("Please enter proper choice")

    print("-------------------------------------------------------------------")
    while(True):
        wish=input("Do you wish to continue further operations? Y/N")
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



# print("Addition of matrices:")
# (m1.addmatrix(m2)).display()
# print("Product of matrices:")
# (m1.difference(m2)).display()
# print("Transpose of matrix1:")
# (m1.transpose()).display()
# print("Transpose of matrix2:")
# (m2.transpose()).display()
# print("Product of two matrix:")
# (m1.product(m2)).display()
