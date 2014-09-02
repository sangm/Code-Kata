// chop.js returns a function

var assert = require('assert');
var chop = require('../chop.js');

describe('ChopTest', function() {
    describe('.chop()', function() {
        it('should return -1 for empty list', function() {
            assert.equal(-1, chop(3, []));
        });
        it('should return -1 if not in the list', function() {
            assert.equal(-1, chop(3, [1]));
        });
        it('should return index of an item in a single list', function() {
            assert.equal(0, chop(1, [1]));
        });
        it('should return index of an item in a list longer than 1', function() {
            assert.equal(0, chop(1, [1, 3, 5]));
        });   
        it('should return item that is not first in the list', function() {
            assert.equal(1,  chop(2, [1, 2, 3]));
            assert.equal(0,  chop(1, [1, 3, 5]))
            assert.equal(1,  chop(3, [1, 3, 5]))
            assert.equal(2,  chop(5, [1, 3, 5]))
            assert.equal(-1, chop(0, [1, 3, 5]))
            assert.equal(-1, chop(2, [1, 3, 5]))
            assert.equal(-1, chop(4, [1, 3, 5]))
            assert.equal(-1, chop(6, [1, 3, 5])) 
            assert.equal(0,  chop(1, [1, 3, 5, 7]))
            assert.equal(1,  chop(3, [1, 3, 5, 7]))
            assert.equal(2,  chop(5, [1, 3, 5, 7]))
            assert.equal(3,  chop(7, [1, 3, 5, 7]))
            assert.equal(-1, chop(0, [1, 3, 5, 7]))
            assert.equal(-1, chop(2, [1, 3, 5, 7]))
            assert.equal(-1, chop(4, [1, 3, 5, 7]))
            assert.equal(-1, chop(6, [1, 3, 5, 7]))
            assert.equal(-1, chop(8, [1, 3, 5, 7]))
        });
    });
});


