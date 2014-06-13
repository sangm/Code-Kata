import string
import re

class StringCalculator:
    
    def add(self, numbers):
        if len(numbers) == 0: return 0
        regex = re.compile(r'(//?).+\\n').search(numbers)
        delim = ','
        if regex:
            delim = regex.group().replace('//','').replace(r'\n','')
            numbers = numbers[regex.end():]
        regex = re.compile(r'\[(.+?)\]')
        search = regex.match(delim)
        if search: 
            delimList = []
            while search:
                delimList.append(search.group(1))
                delim = delim[search.end():]
                search = regex.match(delim)
            numbers = re.sub('[%s]' % ''.join(delimList), delimList[0], numbers)
            delim = delimList[0]
        numbers = numbers.replace(r'\n', delim)
        numbers = numbers.split(delim)
        numbers = [int(n) for n in numbers if int(n) < 1000]
        if any(n < 0 for n in numbers):
            raise Exception('Negative Numbers Not Allowed')
        return sum(numbers)
