import re

class StringCalculator:
    
    def add(self, num):
        if len(num) == 0: return 0
        regex = re.compile(r'(//?).+\\n').search(num)
        delim = ','
        if regex:
            delim = regex.group().replace('//','').replace(r'\n','')
            num = num[regex.end():]
            regex = re.compile(r'\[(.+?)\]')
            search = regex.match(delim)
            delimList = []
            while search:
                delimList.append(search.group(1))
                delim = delim[search.end():]
                search = regex.match(delim)
            if len(delimList) > 0:
                num = re.sub('[%s]' % ''.join(delimList), delimList[0], num)
                delim = delimList[0]
        num = num.replace(r'\n', delim)
        num = [int(n) for n in num.split(delim) if int(n) < 1000]
        if len([n for n in num if n < 0]):
            raise Exception('Negative Numbers Not Allowed')
        return sum(num)
