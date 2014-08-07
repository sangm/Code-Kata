(function () {
    var privateFunctions = {
        splitProblem: function(problem) {
            var regex = /(\/\/(.+)\n)(.+)/;
            var match = regex.exec(problem);
            var delim = ',';
            if (match) {
                delim = match[2];
                problem = match[3];
            }
            delim = delim.split('').map(function(ch) {
                return '\\' + ch;  
            }).join('');
            var splitRegex = new RegExp('\n|' + delim);
            return problem.split(splitRegex);
        },

        sumNumbers: function(numbers) {
            return numbers.reduce(function(prev, curr) {
                var previous = Number(prev);
                var current = Number(curr);
                if (current < 0) 
                    throw new Error('Negatives not allowed');
                if (current > 1000)
                    return previous;
                return previous + current;
            }, 0);
        }
    };

    function StringCalculator() {
        StringCalculator.prototype.add = function(problem) {
            if (problem.length === 0) return 0;
            var numbers = privateFunctions.splitProblem(problem);
            return privateFunctions.sumNumbers(numbers);
        };
    }
    module.exports = StringCalculator;
})()
