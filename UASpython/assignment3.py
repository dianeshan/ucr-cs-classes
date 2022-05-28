
def isPalindrome(word):
    w = word.lower()
    if w == w[::-1]:
        return True
    else:
        return False


word = input("Enter a word: ")
pali = isPalindrome(word)
if pali == True:
    print("This is a palindrome")
else:
    print("This is not a palindrome")


def fibFunc(n):
    for i in range(1, n + 1):
        if (i == 1 or i == 2):
            prev = 1
            prev2 = 1
            print('Count ' + str(i) + ': 1')
        else:
            res = prev + prev2
            print('Count ' + str(i) + ': ' + str(res))
            if (prev > prev2):
                prev2 = res
            else:
                prev = res


num = int(input("How many terms: "))
while num <= 0:
    num = int(input("How many terms: "))
fibFunc(num)
