const convertBtn = document.getElementById('convert-btn');
const input = document.getElementById('number');
const output = document.getElementById('output');

convertBtn.addEventListener("click", () => {
  const romanNumerals = [
    [1000, "M"],
    [900, "CM"],
    [500, "D"],
    [400, "CD"],
    [100, "C"],
    [90, "XC"],
    [50, "L"],
    [40, "XL"],
    [10, "X"],
    [9, "IX"],
    [5, "V"],
    [4, "IV"],
    [1, "I"]
  ];

  if (input.value === "") {
    output.innerText = "Please enter a valid number";
  } else if (input.value < 1) {
    output.innerText = "Please enter a number greater than or equal to 1";
  } else if (input.value >= 4000) {
    output.innerText = "Please enter a number less than or equal to 3999";
  } else {
    let newOutput = "";
    
    for (let [value, numeral] of romanNumerals) {
      while (input.value >= value) {
        newOutput += numeral;
        input.value -= value;
      }
    }
    output.innerText = newOutput;
  }
})