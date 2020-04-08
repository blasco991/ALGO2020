const fs = require('fs');

const Inputs = [... (fs.readFileSync('input2.txt', 'UTF8')).split(" ").slice(1)];
const N = Inputs.length;

function rec(inputs) {
    if(inputs.length==1)
        return;

    console.log(`"${Inputs}" -> "${inputs[1]}: ${inputs.slice(1).filter(el => el < inputs[1])}"`)
    console.log(inputs.slice(1).filter(el => el < inputs[1]))
    
    rec(inputs.slice(1))
}

console.log({N, Inputs});
rec(Inputs)

