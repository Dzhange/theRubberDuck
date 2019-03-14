import random
import sys


size = int(sys.argv[1])

arr = []
f = open("./in.txt",'w')
items = 0
for i in range(size):
    operation = random.randint(1,3)
    if operation == 1: #insert
        data = random.randint(1,20)       
        loc = random.randint(0,items+5)
        items += 1
    if operation == 2:
        data = 0
        loc = random.randint(0,items+5)
        if items >= 1:
            items -= 1
    if operation == 3:
        data = 0
        loc = 0
    if operation == 4:
        data = 0
        loc = 0
    f.write(str(operation) + ' ' + str(data) + ' ' + str(loc) + '\n')



# for i in range(0,size):
#     temp = random.randint(0,100)
    
#     f.write(str(temp) + '\n')
#     arr.append(temp)


# arr.sort()
# fo = open("./std.txt",'w')
# for i in range(0,size):
#     te = arr[i]
#     fo.write(str(te) + '\n')
    


