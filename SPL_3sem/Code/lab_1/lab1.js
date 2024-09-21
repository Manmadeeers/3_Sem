//determine variables types TASK 1
let a = 5;
console.log("5", typeof a)
let namee = "Name";
console.log("name", typeof namee);
let i = 0;
console.log("0", typeof i);
let double = 0.23;
console.log("0.23", typeof double);
let result = 1 / 0;
console.log("1/0", typeof result);
let answer = true;
console.log("true", typeof answer);
let no = null;
console.log("null", typeof no);
//TASK 2 find out how many 5x5 millimeter squares can fut into 45x21 millimeter figure
let B_square = 5 * 5;
let A_square = 45 * 21;
let B_counter = 0;
let Taken_square = 0;
do {
    B_counter++;
    Taken_square += B_square;
} while ((A_square - Taken_square) >= B_square);

console.log("It will fit", B_counter, " times");
//TASK 3 Comparison 
let ii = 2;
let a_inc = ++ii;
let b_inc = ii++
console.log("Task 3", a_inc > b_inc, a_inc < b_inc, a_inc == b_inc);
//TASK 4 Comparison 2
console.log("Task 4");
let Cat = "Котик";
let cat = "котик";
if (Cat > cat) {
    console.log("Котик>котик");
}
else if (Cat < cat) {
    console.log("Котик<котик");
}
else {
    console.log("Котик=котик");
}
//console.log(Cat>cat,Cat<cat,Cat===cat);
let Cot = "Котик";
let kit = "китик";
if (Cot > kit) {
    console.log("Котик>китик");
}
else if (Cot < kit) {
    console.log("Котик<китик");
}
else {
    console.log("Котик=китик");
}
//console.log(Cot>kit,Cot<kit,Cot===kit);
let KOT = "Кот";
if (KOT > cat) {
    console.log("Кот>котик");
}
else if (KOT < cat) {
    console.log("Кот<котик");
}
else {
    console.log("Кот=котик");
}
//console.log(KOT>cat,KOT<cat,KOT===cat);
let Hi = "Привет";
let Bye = "Пока";
console.log(Hi < Bye, Hi > Bye, Hi === Bye);
let num_73 = 73;
let str_53 = "53";
console.log(num_73 > str_53, num_73 < str_53, num_73 == str_53);
let nope = false;
let flt = 0.54;
console.log(nope > flt, nope < flt, nope == flt);
console.log(123 > false, 123 < false, 123 == false);
console.log(true > '3', true < '3', true == '3');
console.log(3 < "5mm", 3 > "5mm", 3 == "5mm");//cannot compare
console.log(8 < '-2', 8 > '-2', 8 == '-2');
console.log(34 < "34", 34 > "34", 34 == "34");
console.log(null < undefined, null > undefined, null === undefined);
//TASK 5 
let UserName = prompt("Enter your name: ");
let AdminName = "Шиман Дмитрий Васильевич";
let buff_user = UserName.toLowerCase();
let buff_Admin = AdminName.toLowerCase();
if(buff_user===buff_Admin||buff_Admin.includes(buff_user)){
    alert("Acsess granted!");
}
else{
    alert("Acsess denied!");
    self.close();
}
//TASK 6
function check_exams(rus_grade, math_grade, eng_grade) {
    let Pass_grade = 60;
    let exam_grades = [rus_grade, math_grade, eng_grade];
    let fail_counter = 0;
    for (let i = 0; i < 3; i++) {
        if (exam_grades[i] < Pass_grade) {
            fail_counter++;
        }
    }
    if (fail_counter === 0) {
        return "Passed";
    }
    else if (fail_counter === 1) {
        return "One more try";
    }
    else {
        return "Fail";
    }

}
console.log("Exam");
console.log(check_exams(100, 100, 100));
console.log(check_exams(100, 50, 60));
console.log(check_exams(30, 20, 40));

//TASK 7 calculations
console.log("Calcualtions");
console.log(true + true);
console.log(0 + "5");
console.log(5 + "mm");
console.log(8 / Infinity);
console.log(9 * "\n9");//expl
console.log(null - 1);
console.log("5" - 2);
console.log("5px" - 3);
console.log(true - 3);
console.log(7 || 0);//bit by bit

//TASK 8 
function Is_chet(num) {
    if (num % 2 === 0) {
        return true;
    }
    else {
        return false;
    }
}
let array = new Array(10);
for (let i = 1; i <= 10; i++) {
    if(Is_chet(i)){
        array[i-1] = (i+2)+"";
    }
    else{
        array[i-1] = i+""+"mm";
    }
}
console.group("Array");
for (let i = 0; i < 10; i++) {
    console.log(array[i]);
}
console.groupEnd();
//TASK 9
