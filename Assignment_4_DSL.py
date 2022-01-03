class Client:
    def __init__(self, tel, name, flag):
        self.tel = tel
        self.name = name
        self.flag = flag

class Hashtable:
    def __init__(self):
        self.size=10
        self.ht=[Client(-1,"",False) for i in range(self.size)]

    def hashfun(self,no):
        return no%self.size

    def insert(self,key,n):    #without replacement
        i = self.hashfun(key)
        index = self.hashfun(key)
        if self.ht[index].tel == -1:
            self.ht[index].tel = key
            self.ht[index].name = n
        else:
            while self.ht[index].tel != -1:
                if self.ht[index].tel == key:
                    print("\n Duplicate Entry!!!")
                    return
                index = (index + 1) % self.size
                if index == i:
                    print("\n Overflow!!!")
                    return
            self.ht[index].tel = key
            self.ht[index].name = n

    def insertR(self,key,n):   #with replacement
        i = self.hashfun(key)
        index = self.hashfun(key)
        tmpt = 0
        tmpn = ""
        if self.ht[index].tel == -1:
            self.ht[index].tel=key
            self.ht[index].name=n
            self.ht[index].flag=True
        else:
            if self.ht[index].flag == False:
                tmpt = self.ht[index].tel
                tmpn = self.ht[index].name
                self.ht[index].tel=key
                self.ht[index].name=n
                key = tmpt
                n = tmpn
            while self.ht[index].tel != -1:
                if self.ht[index].tel == key:
                    print("\n Duplicate Entry")
                    return
                index = (index + 1) % self.size
                if index == i:
                    print("\n Overflow!!!")
                    return
            self.ht[index].tel = key
            self.ht[index].name = n


    def display(self):
        print("\n\tINDEX \tNAME \tMOBILE NO ")
        for i in range(0, self.size,1):
            if self.ht[i].tel != -1:
                print("\n\t",i," \t",self.ht[i].name," \t",self.ht[i].tel)

    def search(self,key):
        ind = self.hashfun(key)
        for i in range(self.size):
            if self.ht[ind].tel == key:
                return ind
            else:
                ind = (ind+1) % self.size
        return -1


    def delete(self, key):
        s = self.search(key)
        if s == -1:
            print("Element does not exist")
            return
        else:
            ind = self.hashfun(key)
            if self.ht[ind].tel == key:
                self.ht[ind].tel = -1
                self.ht[ind].name = ""
                self.ht[ind].flag = False
                print("\nKey deleted!!")
            else:
                while (self.ht[ind].tel != key):
                    ind = (ind + 1) % self.size
                self.ht[ind].tel = -1
                self.ht[ind].name = ""
                self.ht[ind].flag = False
                print("\nKey deleted!!")


obj = Hashtable()

while 1:
    print("---------------------<< MENU >>------------------------")
    print("1.Insert without replacement\n2.Insert with replacement\n3.Display\n4.Search\n5.Delete\n6.Exit")
    ch=int(input("Enter choice:"))
    if ch==1:
        n=int(input("Enter the number of entries you want to enter: "))
        for i in range(0,n):
            tn = int(input("Enter telephone no: "))
            nm = input("Enter name: ")
            obj.insert(tn, nm)
    elif ch==2:
        n = int(input("Enter the number of entries you want to enter: "))
        for i in range(0, n):
            tn = int(input("Enter tel no:"))
            nm = input("Enter name:")
            obj.insertR(tn, nm)
    elif ch == 3:
        obj.display()
    elif ch == 4:
        s = obj.search(int(input("Enter key to search:")))
        if s == -1:
            print("Not found")
        else:
            print("Found at ",s)
    elif ch==5:
        d=int(input("Enter key to delete: "))
        obj.delete(d)
    elif ch==6:
        break
    else:
        print("Enter valid choice!!")
