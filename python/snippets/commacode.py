def commaCode(passedList:list) -> list:
    result = "'"
    for value in passedList:
        result += value + ", "
    return result + "'"

spam = ['apples', 'bananas', 'tofu', 'cats']
print(commaCode(spam))
