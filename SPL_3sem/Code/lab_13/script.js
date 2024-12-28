var adder = document.getElementById('adder');
var add_but = document.getElementById('submit');
var sh_all_but = document.getElementById('show-all');
var sh_comp_but = document.getElementById('show-completed');
var sh_incomp_but = document.getElementById('show-incompleted');
var task_container = document.getElementsByClassName('tasks');
// var cmp_but = document.getElementById('cmp');
var all_showed = false;

var task_counter = 0;
add_but.addEventListener('click',()=>{
    if(adder.value!=''){
        currentList.addTask(task_counter,adder.value);
        console.clear();
        currentList.printList();
    }   
    adder.value = '';
});



class Task{
    constructor(id,name){
        this.id = id;
        this.name = name;
        this.state = "Incomplete";
    }

    changeName(value){
        this.name = value;
    }
    changeState(value){
        if(!(typeof value==="string")||!(value.toLowerCase==="done")||!(value.toLowerCase==="not done")){
            throw new Error("State error");
        }
        this.done = value;
    }
};

class ToDoList{
    constructor(id,name){
        this.ToDoList = [];
        this.id = id;
        this.name = name;
    }

    changeName(value){
        this.name = value;
    }

    addTask(){
        let current_task = new Task(arguments[0],arguments[1]);
        if(this.checkIfExists(current_task.name)==false){
            this.ToDoList.push(current_task);
           createDiv(current_task.name,current_task.state,current_task.id);
        }
    }
    checkIfExists(name){
        this.ToDoList.forEach(element => {
            if(element.name===name){
                return true;
            }
        });
        return false;
    }
    filterTask(state){
        let filteredTasks = [];
        this.ToDoList.forEach(element => {
            if(element.state==state){
                filteredTasks.push(element);
            }
        });
        return filteredTasks;
    }

    printList(){
        console.group(this.name);
        this.ToDoList.forEach(task => {
            console.log(task);
        });
        console.groupEnd();
    }

    delByName(name){
        this.ToDoList.forEach(element => {
            if(element.name===name){
                this.ToDoList.pop(element);
            }
        });
    }
    
    changeTaskState(name,state){
       this.ToDoList.forEach(element => {
            if(element.name===name){
                element.state = state;
            }
       });
    }
};

const currentList = new ToDoList(1234567890,"Current List");

//event listeners
sh_all_but.addEventListener('click',()=>{
    console.clear();
    currentList.printList();
    clearContainer();
    currentList.ToDoList.forEach(element => {
        createDiv(element.name,element.state,element.id);
    });

});

sh_incomp_but.addEventListener('click',()=>{
    console.clear();
    currentList.printList();
    clearContainer();
    currentList.ToDoList.forEach(element => {
        if(element.state==="Incomplete"){
            createDiv(element.name,element.state,element.id);
        }
    });
})
sh_comp_but.addEventListener('click',()=>{
    console.clear();
    currentList.printList();
    clearContainer();
    currentList.ToDoList.forEach(element => {
        if(element.state==="Complete"){
            createDiv(element.name,element.state,element.id);
        }
    });
})



//functions
function createDiv(name,status,id){
    var newTask = document.createElement('div');
    newTask.className = "NTask";
    var tskName = document.createElement('h1');
    tskName.textContent = name;
    newTask.appendChild(tskName);
    var tskStatus = document.createElement('p');
    tskStatus.textContent = status;
    if(status=="Incomplete"){
        tskStatus.style.color = "red";
    }
    else if(status=="Complete"){
        tskStatus.style.color = "green";
    }
    newTask.appendChild(tskStatus);

    var complete = document.createElement('button');
    complete.textContent = "Complete task";
    complete.id = `cmp`;
    newTask.appendChild(complete);

    complete.addEventListener('click',()=>{
        tskStatus.textContent = "Complete";
        tskStatus.style.color = "green";
        currentList.changeTaskState(name,"Complete");
    })
   

    var del = document.createElement('button');
    del.textContent = "Delete task";
    del.id = "del";
    newTask.appendChild(del);

    del.addEventListener('click',()=>{
        currentList.ToDoList = currentList.ToDoList.filter(t=>t!==newTask);
        newTask.parentElement.removeChild(newTask);
        currentList.delByName(name);
    })

    // var change = document.createElement('button');
    // change.textContent = "Incomplete task";
    // change.id = "chn";

    // change.addEventListener('click',()=>{
    //     tskStatus = "Incomplete";
    //     tskStatus.style.color = "red";
    //     currentList.changeTaskState(name,"Incomplete");
    // })
    // newTask.appendChild(change);
    document.getElementById('tsk').appendChild(newTask);
}

function clearContainer(){
    document.getElementById('tsk').innerHTML = '';
}