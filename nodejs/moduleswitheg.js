const fs = require("fs");
const text = fs.readFileSync("ted.txt", "utf-8");
console.log(text);