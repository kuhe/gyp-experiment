#!/usr/bin/env node
var assert = require('assert');

/**
 * @type {{main: Function, sub: Function}}
 */
var binding = require('./build/Release/binding');

console.log('binding.main() =', binding.main());
console.log('binding.sub(8, 7) =', binding.sub(8, 7));