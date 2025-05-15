const checkBtn = document.getElementById("check-btn");
const resultName = document.getElementById("result-name");
const resultHex = document.getElementById("result-hex");

checkBtn.addEventListener("click", function() {
    const newColor = randomColor();
    document.querySelector(".center-container").style.backgroundColor = newColor;
    resultName.textContent = newColor;
});