#day 4 in python again because c++ bad
import hashlib

key = "ckczppom"

#part 1
number = 0
input = ""
while(True):
    input = key + str(number)
    result = hashlib.md5(input.encode())
    count = 0

    for char in result.hexdigest():
        if char != '0':
            break
        if (count := count + 1) == 5: #6 for part 2
            break
    
    if count == 5: #6 for part 2
        break
        
    number += 1

print(input)




