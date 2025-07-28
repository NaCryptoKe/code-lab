def collatz(number:int) -> int:
    if number % 2 == 0:
        return number // 2
    else:
        return 3 * number + 1

validNumber = False

while not validNumber:
    userInput = input("Enter a number to try out the collatz function")
    try:
        userInput = int(userInput)
        validNumber = True
    except ValueError:
        print("Enter a valid number\n")

print(userInput)

while userInput != 1:
    userInput = collatz(userInput)
    print(userInput)
