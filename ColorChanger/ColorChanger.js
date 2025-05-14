var randomColor = require('randomcolor'); 

const checkBtn = document.getElementById("check-btn");
const resultName = document.getElementById("result-name");
const resultHex = document.getElementById("result-hex");

checkBtn.addEventListener("click", colorChanger())