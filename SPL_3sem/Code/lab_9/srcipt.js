//TASK 1
let square = {
    width:100,
    height:100,
    color:"yellow",
    getSquare(){
        return this.width*this.height;
    },
    getInfo(){
        return `This is a square with height ${this.height} and width ${this.width}. Square's color is ${this.color}`;
    }
};
let small_square = {
    __proto__:square,
    width:50,
    height:50
};

let circle = {
    radius:100,
    color:"white",
    getSquare(){
        return Math.PI*Math.pow(this.radius,2);
    },
    getInfo(){
        `This is a circle with radius ${this.radius} and it's color is ${this.color}`;
    }
};

let another_circle = {
    __proto__:circle,
    color:"green"
};

let triangle_with_lines = {
    base:20,
    height:40,
    lines:1,
    color:"white",
    getSquare(){
        return (this.base/2)*this.height;
    },
    getInfo(){
        return `This is a triangle with ${this.lines} lines and it's color is ${this.color} `;
    }
};

let another_triangle = {
    __proto__:triangle_with_lines,
    lines:3
};
console.group("Figures");
console.log(square.getInfo());
console.log(small_square.getInfo());
console.log(circle.getInfo());
console.log(another_circle.getInfo());
console.log(triangle_with_lines.getInfo());
console.log(another_triangle.getInfo());
console.groupEnd();

//TASK 2
console.group("Inherited human");
class Human{
    constructor(name, surname, birthYear, address) {
        if(!(typeof name==="string"&&typeof surname==="string")){
            throw new Error("Constructor type exception");
        }
        this.name = name;
        this.surname = surname;
        if(!(typeof birthYear==="number")){
            throw new Error("Constructor type exception");
        }
        this.birthYear = birthYear;
        if(!(typeof address==="string")){
            throw new Error("Constructor type exception");
        }
        this.address = address;
    }
    setAge(NewAge){
        if(!typeof NewAge==="number"){
            throw new Error("Invalid age data type");
        }
        this.birthYear= NewAge;
    }
    get age(){
        let current_year = new Date().getFullYear();
        return current_year - this.birthYear;
    }
    setAddress(NewAddress){
        if(!typeof NewAddress==="string"){
            throw new Error("Invalid address data type");
        }
        this.address = NewAddress;
    }
};

let human = new Human("Vaclov","Kachinskas",2006,"Skripnikova 14");
console.log(human.age);
human.setAge(2000);
console.log(human.age);

class Student extends Human{
    constructor(name, surname, birthYear, address, faculty, course, group,id) {
        super(name, surname, birthYear, address);
        this.faculty = faculty;
        this.course = course;
        this.group = group;
        this.id=id;
    };

    setCourse(NewCourse){
        if(!(typeof NewCourse==="number")){
            throw new Error("SetCource data tyoe Exceprion");
        }
        this.course = NewCourse;
    }
    setGroup(NewGroup){
        if(!(typeof NewGroup==="number")){
            throw new Error("setGroup data type exception");
        }
        this.group = NewGroup;
    }
    getFullName(){
        return `Full name: ${this.name} ${this.surname}`;
    }
}

console.log(human);


class Faculty{
    constructor(name,group_count,students_count){
        if(!(typeof name=="string")){
            throw new Error("Faculty constructor type exception");
        }
        this.name = name;
        if(!(typeof group_count==="number"||typeof students_count==="number")){
            throw new Error("Faculty constructor type exception");
        }
        this.group_count = group_count;
        this.students_count = students_count;
        this.students = [];
    }
    setGroups(NewGroups){
        if(!(typeof NewGroups==="number")){
            throw new Error("Group set type exceptiion");
        }
        this.group_count = NewGroups;
    }
    setStudents(NewStudents){
        if(!(typeof NewStudents==="number")){
            throw new Error("Students set type exception");
        }
        this.students_count = NewStudents;
    }
    getDev(){
        let dev_count = 0;
        this.students.forEach(element => {
            let str_id = element.id.toString();
            if(str_id[1]==3){
                dev_count++;
            }
        });
        return dev_count;
    }
    getGroup(num){
        if(!(typeof num ==="number")){
            throw new Error("getGroup type exception");
        }
        let gruop_list = [];
        this.students.forEach(element => {
            if(element.group==num){
                gruop_list.push(element);
            }
        });
        return gruop_list;
    }

}
let student = new Student("Egor","korobov",2006,"Umanskaya 25","FIT",2,6,71232723);
console.log(student.getFullName());
let student1 = new Student("Ilia","Filipiuk",2006,"Miastrovskaya 31","FIT",2,6,7123125);
let student2 = new Student("Vaclovas","Kachinskas",2006,"Skripnikova 14","FIT",2,6,71233226);
let student3 = new Student("Ilia","Vishnevsky",2005,"Ezhi Gedroitsa 20","FIT",2,4,7323127);

let FIT = new Faculty("FIT",10,1000);
FIT.students.push(student);
FIT.students.push(student1);
FIT.students.push(student2);
FIT.students.push(student3);
console.log(FIT.getDev());
console.log(FIT.getGroup(6));
console.groupEnd();