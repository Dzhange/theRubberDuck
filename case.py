import random
import sys


city = int(sys.argv[1])

# city = random.randint(number/2,number)
road = random.randint(0,city*2)
threhold = random.randint(0,10*city)

output = ""

output += str(city) + '\n'
output += str(road) + '\n'
output += str(threhold) + '\n'

for i in range(road):
    src = random.randint(0,city-1)
    tar = random.randint(0,city-1)
    while (src == tar ):
        tar = random.randint(0,city-1)
    weight = random.randint(0,city*city)
    output += str(src)+ ' ' + str(tar) + ' ' + str(weight)+'\n'

print output