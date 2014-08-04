var assert = require('assert');
var StringCalculator = require('../StringCalculator.js')
var calc = new StringCalculator();

describe('StringCalculator', function() {
    describe('.add()', function() {
        it('should return 0 given empty string', function() {
            assert.equal(0, calc.add(""));
        });
        it('should return number given a single length string', function() {
            assert.equal(0, calc.add("0"));
            assert.equal(1, calc.add("1"));
            assert.equal(2, calc.add("2"));
            assert.equal(3, calc.add("3"));
        });
        it('should return sum of two strings', function() {
            assert.equal(0, calc.add("0,0"));
            assert.equal(4, calc.add("2,2"));
            assert.equal(8, calc.add("4,4"));
        });
        it('should return sum of arbituary length string', function() {
            assert.equal(0, calc.add('0,0,0,0,0,0'));
            assert.equal(2, calc.add('0,1,0,1'));
            assert.equal(4, calc.add('3,1,0'));
            assert.equal(8, calc.add('2,4,1,1'));
        });
        it('should handle newline character', function() {
            assert.equal(4, calc.add('1\n2,1'));
        });
        it('should be able to change delimiter', function() {
            assert.equal(2, calc.add('//;\n1;1'));
            assert.equal(4, calc.add('//;\n2;2'));
            assert.equal(8, calc.add('//;\n4;2;2'));
        });
        it('should throw an error given a negative number', function() {
            assert.throws(function() {
                throw new Error('Negatives not allowed');   
            }, Error);
        });
    });
});
