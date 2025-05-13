const checkBtn = document.getElementById("check-btn");
const textInput = document.getElementById("text-input");
const result = document.getElementById("result");

checkBtn.addEventListener("click", function () {
  const input = textInput.value.trim();

  if (input === "") {
    alert("Please input a value.");
    return;
  }

  const cleaned = input.replace(/[^a-zA-Z0-9]/g, "").toUpperCase();
  const reversed = cleaned.split("").reverse().join("");

  if (cleaned === reversed) {
    result.innerText = `${input} is a palindrome`;
  } else {
    result.innerText = `${input} is not a palindrome`;
  }

  result.style.display = "block";
});
