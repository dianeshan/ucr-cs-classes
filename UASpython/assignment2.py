
story = "There once was a [noun] named [name]. They enjoyed [verb] on a [adjective] day."
words = story.split()
count = 0

for i in words:
    if i[0] == '[':
        if i[len(i) - 1] == ']':
            res = input("Please type in a " + i[1:len(i) - 1] + ": ")
            words[count] = res
        else:
            res = input("Please type in a " + i[1:len(i) - 2] + ": ")
            res = res + i[len(i) - 1]
            words[count] = res

    count += 1

final = ' '.join(words)

print(final)
