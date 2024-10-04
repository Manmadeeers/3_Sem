//TASK 1
let NestedArray = [1,[1,2,[3,4]],[2,4]];

function FlattenArray(InputArray){
    return InputArray.reduce((Accumulator,Current)=>{
        if(Array.isArray(Current)){
            return Accumulator.concat(FlattenArray(Current));
        }
        else{
            return Accumulator.concat([Current]);
        }
    },[]);
}

let Result = FlattenArray(NestedArray);
console.group("Flatten array");
console.log(Result);
console.groupEnd();

//TASK 2

let NestedArrayS = [1,[1,2,[3,4,[5,6]]],7,[8,9]];

function CountNestedSum(InputArray){
    if(Array.isArray(InputArray)){
        return InputArray.reduce((Accumulator,Current)=>Accumulator+CountNestedSum(Current));
    }
    else{
        return InputArray;
    }
}

let NestedSum = CountNestedSum(NestedArrayS);
console.group("Sum of all the elements in a nested array");
console.log(NestedSum);
console.groupEnd();

//TASK 3
let Students = [
    {name:"Vaclov",age:18,groupId:6},
    {name:"Ilya",age:18,groupId:6},
    {name:"Polina",age:17,groupId:10},
    {name:"Kirill",age:17,groupId:8},
    {name:"Dima",age:20,groupId:4}
];

function sortStudents(InputArray){
    let Result = {};
    InputArray.forEach(student=> {
        if(student.age>17){
            if(!Result[student.groupId]){
                Result[student.groupId] = [];
            }
            Result[student.groupId].push(student);
        }
    });
    return Result;
}
let Above17 = sortStudents(Students);

console.group("Sort students");
console.log(Above17);
console.groupEnd();

//TASK 4
console.group("Character's codes");
let SomeLine = "ABCDEFG";
let SrcStrofCodes = "";
for(let char of SomeLine){
    SrcStrofCodes +=char.charCodeAt(0);
}
console.log(`SrcStrofCodes: ${SrcStrofCodes}`);
let NewStrofCodes = ""
for(let char of SrcStrofCodes){
    if(char=="7"){
        NewStrofCodes+="1";
    }
    else{
        NewStrofCodes+=char;
    }
}
console.log(`NewstrofCodes: ${NewStrofCodes}`);

let LinesSubstraction = SrcStrofCodes-NewStrofCodes;
console.log(`Result: ${LinesSubstraction}`);
console.groupEnd();

//TASK 5
function formObject(){
    let ObjectToReturn = {};
    for(let object of arguments){
        Object.assign(ObjectToReturn,object);
    }
    return ObjectToReturn;
}
console.group("From a new object from many");
console.log(formObject({name:"Alex",age:"18"},{sex:"Male",CanDrive:true},{Married:false,HasKids:true}));
console.groupEnd();

//TASK 6
function drawPiramid(floors){
    let pyramid = "";
    for(let row=1;row<=floors;row++){
        let stars = '*'.repeat((row*2)-1);
        let spaces = ' '.repeat(floors-row);
        pyramid+=`${spaces}${stars}\n`; 
    }
    return pyramid;
}
console.group("Pyramid");
console.log(drawPiramid(7));
console.log(drawPiramid(3));
console.groupEnd();