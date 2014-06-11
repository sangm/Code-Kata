class FizzBuzz: 
    def fizzBuzz(self, num):
        if num % 3 == 0 and num % 5 == 0:
            return 'fizzbuzz'
        elif num % 5 == 0:
            return 'buzz'
        elif num % 3 == 0: 
            return 'fizz'
        else:
            return str(num)

