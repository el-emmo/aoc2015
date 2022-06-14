#day 6 in python again because c++ bad (absolutely awful solution edition)

#part 1 
matrix = [[0 for x in range(1000)] for y in range(1000)]
count = 0

with open("input.txt") as file:
    for line in file:
        split_line = line.strip().split()

        if split_line[0] == "toggle":
            numbers = (split_line[1].split(","), split_line[3].split(","))

            for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                    if matrix[x][y] == 1:
                        matrix[x][y] = 0
                        count -= 1
                    else:
                        matrix[x][y] = 1
                        count += 1
        else:
            if split_line[1] == "on":
                numbers = (split_line[2].split(","), split_line[4].split(","))

                for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                    for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                        if matrix[x][y] == 0:
                            count += 1
                        matrix[x][y] = 1
            else:
                numbers = (split_line[2].split(","), split_line[4].split(","))

                for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                    for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                        if matrix[x][y] == 1:
                            count -= 1
                        matrix[x][y] = 0
print(count)

#part 2
matrix = [[0 for x in range(1000)] for y in range(1000)]
brightness = 0

with open("input.txt") as file:
    for line in file:
        split_line = line.strip().split()

        if split_line[0] == "toggle":
            numbers = (split_line[1].split(","), split_line[3].split(","))

            for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                    matrix[x][y] += 2
                    brightness += 2
        else:
            if split_line[1] == "on":
                numbers = (split_line[2].split(","), split_line[4].split(","))

                for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                    for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                        matrix[x][y] += 1
                        brightness += 1
            else:
                numbers = (split_line[2].split(","), split_line[4].split(","))

                for x in range(int(numbers[0][0]), int(numbers[1][0]) + 1):
                    for y in range(int(numbers[0][1]), int(numbers[1][1]) + 1):
                        if matrix[x][y] > 0:
                            matrix[x][y] -= 1
                            brightness -= 1
print(brightness)









