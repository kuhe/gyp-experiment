#!/usr/bin/env node
var assert = require('assert');

/**
 * @type {{main: Function, sub: Function}}
 */
var binding = require('./build/Release/binding');

console.log('binding.main(\'hello world\') =', binding.main('hello world'));
console.log('binding.add(8, 7) =', binding.add(8, 7));