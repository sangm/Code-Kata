(function () {
    var privateFunctions = {
        splitProblem: function(problem) {
            var regex = /(\/\/(.)\n)(.+)/;
            var match = regex.exec(problem);
            var delim = ',';
            if (match) {
                delim = match[2];
                problem = match[3];
            }
            var splitRegex = new RegExp('\n|' + delim);
            return problem.split(splitRegex);
        },

        sumNumbers: function(numbers) {
            return numbers.reduce(function(prev, curr) {
                if (Number(curr) < 0) 
                    throw new Error('Negatives not allowed');
                return Number(prev) + Number(curr);
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
