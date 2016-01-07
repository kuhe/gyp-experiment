'use strict';
var assert = require('assert');

/**
 * @type {{main: Function}}
 */
var binding = require('./build/Release/binding');

console.log('binding.main() =', binding.main());