//TASK 1
function volume(length){
    return (width,height)=>{
        return length*width*height;
    }
}
const len_const = 120;
console.group("Volume");
console.log(volume(len_const)(130,140));
console.log(volume(len_const)(50,10));
console.log(volume(len_const)(110,15));
console.groupEnd();
//TASK 2

var X = 0;
var Y = 0;
const steps = 10;

function makeStep(direction){
    switch(direction){
        case "up":
            Y+=steps;
            break;
        case "down":
            Y-=steps;
            break;
        case "left":
            X-=steps;
            break;
        case "right":
            X+=steps;
            break;
        case "exit":
            return "exit";
    }
    return {X,Y};
}

function* generateMovement(){
    let direction = prompt();

    while(direction!==null){
        let result = makeStep(direction.toLowerCase());
        if(result==="exit"){
            return;
        }
        yield(`X=${result.X}, Y= ${result.Y}`);
        direction = prompt();
    }
}

console.group("Generator");
let generated  = generateMovement();
for(var value of generated){
    console.log(value);
}
console.groupEnd();

//TASK 3
if(!window.Promise){
    alert("Your browser is extremely old! Get something new idk");
}
window.X = "new X";
window.Y = "new Y";
console.group("Global objects");
console.log(window);
console.groupEnd();

//TASK 6
let currentCount = 1;
function makeCounter(){
    
    return function(){
        return currentCount++;
    };
}

let counter = makeCounter();
let counter2 = makeCounter();
console.group("Counter");
console.log(counter());
console.log(counter());
console.log(counter());
console.log(counter2());
console.log(counter2());
console.groupEnd();