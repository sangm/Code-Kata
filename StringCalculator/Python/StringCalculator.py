import re

class StringCalculator:
    def add(self, numbers):
        if len(numbers) == 0: return 0
        regex = re.compile(r'^(//?).\\n')
        search = regex.search(numbers)

        delim = ','
        if search:
            index = search.end()
            numbers = numbers[index:]
            delim = search.group().replace(r'\n','').replace(r'//','')

        numbers = numbers.replace('\n', ',').split(delim)
        sumNum = sum([int(num) for num in numbers])
        return sumNum

