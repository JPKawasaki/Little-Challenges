document.addEventListener('DOMContentLoaded', () => {
    const result = document.getElementById('result');
    const input = document.getElementById('input');
    const operatorBtn = document.querySelectorAll('.operator');
    const equals = document.getElementById("equal");
    const numbers = document.querySelectorAll(".number");
    

    input.addEventListener("input", function() {
        this.value = this.value.replace(/[^0-9()+-/*%]/g, "");
    });
    
    numbers.forEach( function(number) {
        number.addEventListener("click", function() {
            input.value += number.textContent;
        });
    });

    operatorBtn.forEach( function(operator) {
        operator.addEventListener("click", function () {
            const value = operator.textContent;

            const sanitized = value === "×" ? "*" :
                              value === "÷" ? "/" :
                              value === "ac" ? "" :
                              value;

            if (value === "ac") {
                input.value = "";
                result.textContent = "0";
            } else if (value !== "=") {
                const lastChar = input.value[input.value.length - 1];
                const isOperator = /[+\-*/%]/;
                if (!(isOperator.test(sanitized) && isOperator.test(lastChar))) {
                    input.value += sanitized;
                }
            }
            
        })
    });

    equals.addEventListener("click", function() {
        const finalResult = eval(input.value)
        result.textContent = finalResult
    })
})