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
        this.age = NewAge;
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

class Student{
    constructor(name, surname, birthYear, address, faculty, course, group, enrollmentNumber) {
        super(name, surname, birthYear, address);
        this.faculty = faculty;
        this.course = course;
        this.group = group;
        this.enrollmentNumber = enrollmentNumber;
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
}

console.groupEnd();