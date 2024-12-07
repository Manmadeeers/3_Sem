//TASK 1
const set = new Set([1,1,2,3,4]);
console.group("First task");
console.log(set);
console.groupEnd();

//TASK3
const name  = "Lydia";
age = 21;
console.group("Third task");
console.log(delete name);
console.log(delete age);
console.groupEnd();

//TASK4
const numbers = [1,2,3,4,5];
const[y,,,,x] = numbers;
console.group("Fourth task");
console.log(y);
console.log(x);
console.groupEnd();

//TASK5

const user = {name:"Lydia",age:21};
const admin = {admin:true,...user};
console.group("Fivth task");
console.log(admin);
console.groupEnd();

//TASK6

const person = {name:"Lydia"};
Object.defineProperty(person,"age",{
    value:21,
    enumerable:true
});
console.group("Sixth task");
console.log(person);
console.log(Object.keys(person));
console.groupEnd();

//TASK7

const a = {};
const b = {key:"b"};
const c = {key:"c"};
a[b] = 123;
a[c] = 456;
console.group("Seventh task");
console.log(a[b]);
console.groupEnd();

//TASK8
let num = 10;
const increaseNumber = ()=>num++;
const increasePassedNumber = number=>number++;

const num1 = increaseNumber();
const num2 = increasePassedNumber(num1);
console.group("Eighth task")
console.log(num1);
console.log(num2);
console.groupEnd();

//TASK9

const value = {number:10};
const multiply = (x = {...value})=>{
    console.log((x.number*=2));
};
console.group("Nineth task");
multiply();
multiply();
multiply(value);
multiply(value);
console.groupEnd();

//TASK 10
console.group("Tenth task");
[1,2,3,4].reduce((x,y)=>{console.log(x,y);return y});
console.groupEnd();