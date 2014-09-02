(function () {
    var chop = function(num, list) {
        var len = list.length;
        if (len === 0) return -1;

        var left = 0
        var right = len - 1
        var mid;
        var midElement; 

        while (left <= right) {
            mid = (left + right) / 2 | 0;
            midElement = list[mid];
            if (midElement === num) return mid;
            else if (midElement < num) left = mid + 1;
            else if (midElement > num) right = mid - 1;
        }
        return -1;
    };
    module.exports = chop;
})();
