from random import randint

answer = randint(1, 100)

userNum = input('Guess a number between 1 and 100: ')

num = int(userNum)
print(num)

while (num != answer):
    if (num < 1 or num > 100):
        print('Invalid input! Guess again!')
    elif (num < answer):
        print('Too low! Guess again!')
    else:
        print('Too high! Guess again!')
    userNum = input('Guess a number between 1 and 100: ')
    num = int(userNum)
    print(num)

if (num == answer):
    print('YAY you got it!')
