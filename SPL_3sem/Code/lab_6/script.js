//TASK 1
let numbers = [1,2,3,4,5,6];
const[y] = numbers;
const[,,third,,fiv] = numbers
console.group("Array destructuring:");
console.log(y);
console.log(third);
console.log(fiv);
console.groupEnd();

//TASK 2
let user = {name:"Valera",age:43};
let Admin = {admin:true,...user};
console.group("Spread operator with objects");
console.log(user);
console.log(Admin);
console.groupEnd();

//TASK 3
let store = {
    state:{//1st level
        profilePage:{//2nd level
            posts:[//3rd level
                {id:1,message:"Hi",likeCounter:12},
                {id:2,message:"Bye",likeCounter:1},
            ],
            newPostText:"About me",
        },
        dialogPage:{
            dialogs:[
                {id:1,name:"Valera"},
                {id:2,name:"Andrey"},
                {id:3,name:"Sasha"},
                {id:4,name:"Viktor"},
            ],
            messages:[
                {id:1,message:"Hi"},
                {id:2,message:"hi Hi"},
                {id:3,message:"hi hi hi"},
            ],
        },
        sidebar:[],
    },
}
function getThird(obj){
    const{profilePage:{posts},
          dialogPage:{dialogs},
          dialogPage:{messages}} = obj.state;
    return {posts,dialogs,messages};

}
let destr = getThird(store);

console.group("Complex object destructuring");
console.log(getThird(store));
console.log(destr.messages[2].id);
console.groupEnd();

//TASK 4
let tasks = [
    {id:1,title:"HTML&CSS",isDone:true},
    {id:2,title:"JS",isDone:true},
    {id:3,title:"ReactJS",isDone:false},
    {id:4,title:"Rest API",isDone:false},
    {id:5,title:"GraphQL",isDone:false},
];
let NewTask = {id:6,title:"Find a job",isDone:false};
tasks = [...tasks,NewTask];
console.group("Add to an array using spread operator");
console.log(tasks);
console.groupEnd();

//TASK 5
let arrTOfunc = [1,2,3];
function sumValues(x,y,z){
    return x+y+z;
}
console.group("PArametres transmition using spread operator");
console.log(sumValues(...arrTOfunc))
console.groupEnd();
