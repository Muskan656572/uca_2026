function* calc(initialValue) {
  let result = initialValue; 
  let output = result;       

  while (true) {
    const input = yield output; 

    if (!input) {
      output = result;
      continue;
    }

    const { operation, value } = input;

    if (typeof value !== "number" || Number.isNaN(value)) {
      output = "Invalid input";
      continue; 
    }
    if (operation === "divide" && value === 0) {
      output = "Invalid input";
      continue;
    }

    if (operation === "add") result += value;
    else if (operation === "subtract") result -= value;
    else if (operation === "multiply") result *= value;
    else if (operation === "divide") result /= value;
    else {
      output = "Invalid input";
      continue;
    }

    output = result; 
  }
}

const cal = calc(50);


cal.next();

console.log(cal.next({ operation: "add", value: 30 }).value);    

console.log(cal.next({ operation: "multiply", value: 2 }).value); 

console.log(cal.next({ operation: "add", value: "30" }).value);    

console.log(cal.next({ operation: "multiply", value: 0 }).value);    