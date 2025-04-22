const addon = require('./build/Release/addon');

const a = 7;
const b = 5;
const result = addon.add(a, b);
console.log(`The sum of ${a} and ${b} is ${result}`);