//TASK 1
function basicOperations(value1,operations,value2){
    switch(operations){
        case '+':return value1+value2; break;
        case '-':return value1-value2;break;
        case '*':return value1*value2;break;
        case '/':return value1/value2;break;
        default:return"Cannot proceed such operation!";
    }
}
console.group("Operations");
console.log(basicOperations(1,'+',2));
console.log(basicOperations(1,'/',0));
console.log(basicOperations(10,'-',6));
console.log(basicOperations(15,'*',18));
console.log(basicOperations(1,'f',6));
console.groupEnd();

//TASK 2

function cubicSum(number){
    let CubicSUM = 0;
    for(let i = 0;i<number;i++){
        let CurrentNumber = i+1;
        CubicSUM+=Math.pow(CurrentNumber,3);
    }
    return CubicSUM;
}
console.group("Cubic sum");
console.log(cubicSum(10));
console.log(cubicSum(5));
console.log(cubicSum(2));
console.groupEnd();

//TASK 3
function midArythm(InputArray){
    let ArrayLength = InputArray.length;
    let SUM = 0;
    for(let i=0;i<ArrayLength;i++){
        SUM+=InputArray[i];
    }
    return SUM/ArrayLength;
}
console.group("Mid Arythm");
console.log(midArythm([1,2,3,4,5,6,7,8,9,10]));
console.log(midArythm([123,234,345,456]));
console.groupEnd();


//TASK 4

function invertSting(InputString){
    let RevercedString = "";
    for(let i=InputString.length-1;i>=0;i--){
        if(!(InputString[i]>='А'&&InputString[i]<='я')){
            RevercedString+=InputString[i];
        }
        
    }
    if(RevercedString.length===2){
        RevercedString =  "The whole string is in russian";
    }
    return RevercedString;
}
console.group("Reverced string");
console.log(invertSting("String in English"));
console.log(invertSting("Sting на English"));
console.log(invertSting("lop lop lop"));
console.log(invertSting("строка на русском"));
console.groupEnd();

//TASK 5

function MultiplyString(InputString,InputMultilier){
    let StrToReturn = "";
    for(let i=0;i<InputMultilier;i++){
        StrToReturn+=InputString;
    }
    return StrToReturn;
}

console.group("Multiplied string");
console.log(MultiplyString("String",2));
console.log(MultiplyString("febef",10));
console.groupEnd();


//TASK 6
function ProcessArrays(Array1,Array2){
    let ResultArray = [];
    let ResultPosition = 0;
    for(let i=0;i<Array1.length;i++){
        if(!(Array2.includes(Array1[i]))){
            ResultArray[ResultPosition] = Array1[i];
            ResultPosition++;
        }
    }
    return ResultArray;
}

let Arr1 = ["Element","String","Something"];
let Arr2 = ["Element","Line","JavaScript"];
console.group("Process two arrays");
console.log(ProcessArrays(Arr1,Arr2));
console.groupEnd();