//TASK 9
//Object
const Days_obj = {
    1:"Monday",
    2:"Tuesday",
    3:"Wednesday",
    4:"Thursday",
    5:"Friday",
    6:"Saturday",
    7:"Sunday"
}
let number_of_day = parseInt(prompt("Enter the number of the day(1-7):"));
if(number_of_day>=1&&number_of_day<=7){
    alert(`Day number ${number_of_day} is ${Days_obj[number_of_day]}`)
}
else{
    alert("Error! Day's number entered incorrectly!");
}
//array
let Days_str = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"];
let day_number = parseInt(prompt("Enter it once again:"));
if(day_number>=1&&day_number<=7){
    alert(`Day number ${day_number} is ${Days_str[day_number-1]}`);
}
else{
    alert("Error! Day's number entered incorrectly!");
}
//TASK 10
function form_string( second, third,first="I love ")
{
    return first+" "+second+" "+third+"";
}
let number = Math.random();
console.log(number);
let sec_parm;
if(number<0.5){
    sec_parm = "doing ";
}
else{
    sec_parm = "eating ";
}
let third_parm = prompt("Enter the third parametr: ");
console.log(form_string(undefined,sec_parm,third_parm));
console.log(params(4,4));   
//TASK 11
console.log("Params functions");
function params(a,b){
    if(a<=0||b<=0){
        return "Such a square cannot exist";
    }
    if(a===b){
        return (a+b)*2;
    }
    else{
        return a*b;
    }
}

console.log(params(4,4));
console.log(params(4,5));
console.log(params(0,1));
//console.log(params_exp(8,8));
const params_exp = function(a,b){
    if(a<=0||b<=0){
        return "Such a square cannot exist";
    }
    if(a===b){
        return (a+b)*2;
    }
    else{
        return a*b;
    }
};
console.log("Using function expression: ");
console.log(params_exp(4,16));
//arrow function
const parms_arrow = (ax,b)=>{
    if(a<=0||b<=0){
        return "Such a square cannot exist";
    }
    if(a===b){
        return (a+b)*2;
    }
    else{
        return a*b;
    }
};
console.log("Arrow function: ",parms_arrow(8,8));