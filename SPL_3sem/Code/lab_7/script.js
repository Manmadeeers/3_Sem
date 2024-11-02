//TASK 1
let person = {
    name:"Vacloveass",
    age:4,

    greet: function(){
        return `Hi,${this.name}`;
    },
    ageAfterYears:function(years){
        return `In ${years} years ${this.name} will be ${this.age+years}`;
    }    
};

console.group("Object methods using this");
console.log(person.greet());
console.log(person.ageAfterYears(20));
console.groupEnd();

//TASK 2
let car = {
    manufacturer:"Ferrari",
    model:"SF90",
    year:2018,

    getInfo:function(){
        return `Model ${this.model} was produced by ${this.manufacturer} in ${this.year}`;
    }
}

console.group("Car object");
console.log(car.getInfo());
console.groupEnd();

//TASK 3
function Book(title,author){
    this.title = title;
    this.author = author;

    this.getTitle = function(){
        return `This book is called "${this.title}"`;
    };
    this.getAuthor = function(){
        return `This book was written by ${this.author}`;
    }
}

let B1 = new Book("The Lord of The Rings","J.W.Tolkien");
console.group("Create an object using a constructor function");
console.log(B1.getTitle());
console.log(B1.getAuthor());
console.groupEnd();

//TASK 4
let team = {
    players:[{name:"DeadP47",level:47,ingame_number:47},{name:"Manmade",level:8,ingame_number:88},{name:"Litvinas",level:11,ingame_number:13}],

    getPlayersInfo:function(number){
       for(let player of this.players){
            if(player.ingame_number===number){
                return `${player.name} plays under the number ${player.ingame_number} and has level ${player.level}`;
            }
       }
       return "There's no such a player";
    }
}
console.group("Players");
console.log(team.getPlayersInfo(47));
console.log(team.getPlayersInfo(15));
console.groupEnd();

//TASK 5
const counter = (function(){
    let count = 0;
    return{
        increment:function(){count++},
        decrement:function(){count--},
        getCount:function(){return count}
    };
})();

console.group("Module count");
counter.increment();
counter.decrement();
counter.increment();
console.log(counter.getCount());    
console.groupEnd();

//TASK 6
console.group("Descriptors");
let item = {
    price:"30$",
    name:"Arch Linux"
};
item.name = "Windows 11";
console.log(item.name);
Object.defineProperty(item,"name",{
    value:"Windows 10",
    writable:false,
    configurable:false
});
console.log(item.name);
Object.defineProperty(item,"price",{
    value:"20$",
    writable:false,
    configurable:false
});
item.price = "50$";
console.log(item.price);
console.groupEnd();

//TASK 7
let circle = {
    radius:30,
    get getSquare(){
        return `The circle's square is ${ Math.pow(this.radius,2)*3.14}`;
    },
    get getRadius(){
        return `Radius of the circle is ${this.radius}`;
    },
    set setRadius(value){
        this.radius = value;
    }   
};
console.group("Getters and setters");
console.log(circle.getRadius);
console.log(circle.getSquare);
circle.setRadius = 40;
console.log(circle.getRadius);
console.log(circle.getSquare);
console.groupEnd();

//TASK 8

console.group("Descriptors once again");
let automobile = {
    make:"Renault",
    model:"Kaptur",
    year:2016,

    getInfo:function(){
        return `${this.make} ${this.model} was made in ${this.year}`;
    }
};

console.log(automobile.getInfo());
Object.defineProperties(automobile,{
    make:{
        value:"Toyota",
        writable:false,
        configurable:false
    },
    model:{
        value:"Rav4",
        writable:false,
        configurable:false
    },
    year:{
        value:2008,
        writable:false,
        configurable:false
    }

});
console.log(automobile.getInfo());
console.groupEnd();

//TASK 9
let numbers = [1,2,3];
let Summarize = {
    numbers:numbers,
    get sum(){
        return this.numbers.reduce((acc,curr)=>acc+curr,0);
    }
};
console.group("Summarize all the elements of array");
console.log(Summarize.sum);
console.groupEnd();

//TASK 10
let rectangle = {
    width:400,
    height:500,
    get getHeight(){
        return this.height;
    },
    get getWidth(){
        return this.width;
    },
    get getSquare(){
        return this.width*this.height;
    }
};
console.group("Rectangle");
console.log(rectangle.getHeight);
console.log(rectangle.getWidth);
console.log(rectangle.getSquare);
console.groupEnd();

//TASK 11
let user = {
    firstName:"Dmitry",
    lastName:"Shiman",
    get getFullName(){
        return `Full name is ${this.firstName+" "+this.lastName}`;
    },
    set setFullName(value){
        let devide = value.split(" ");
        this.firstName = devide[0];
        this.lastName = devide[1]; 
    }
};
console.group("User");
console.log(user.getFullName);
user.setFullName = "Alina Scherbakova";
console.log(user.firstName);
console.log(user.lastName);
console.log(user.getFullName);
console.groupEnd();
