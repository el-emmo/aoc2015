#day 2 in python because c++ bad

numbers = []
with open("input.txt") as file:
    for line in file:
        numbers.append([int(n) for n in line.strip().split('x')])

#part 1
sum = 0
for pairs in numbers:
    lw = pairs[0] * pairs[1]
    wh = pairs[1] * pairs[2]
    lh = pairs[0] * pairs[2]
    sum += 2*lw + 2*wh + 2*lh + min(lw, wh, lh)
print(sum)

#part 2
sum = 0
for pairs in numbers:
    pairs.sort()
    side = 2 * pairs[0] + 2 * pairs[1]
    bow = pairs[0] * pairs[1] * pairs[2]
    sum += side + bow
print(sum)
