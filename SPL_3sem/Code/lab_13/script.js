var adder = document.getElementById('adder');
var add_but = document.getElementById('submit');
var sh_all_but = document.getElementById('show-all');
var sh_comp_but = document.getElementById('show-completed');
var sh_incomp_but = document.getElementById('show-incompleted');
var task_container = document.getElementsByClassName('tasks');
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

sh_all_but.addEventListener('click',()=>{
    currentList.printList();
    if(!all_showed){
        currentList.ToDoList.forEach(element => {
            var newTask = document.createElement('div');
            newTask.className = "NTask";
            var tskName = document.createElement('h1');
            tskName.textContent = element.name;
            newTask.appendChild(tskName);
            var statusbar = document.createElement('h3');
            statusbar.textContent = "Status";
            document.getElementById('tsk').appendChild(newTask);
            document.getElementById('tsk').appendChild(statusbar);
        });
        all_showed = true;
    }
   
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
        this.ToDoList.push(current_task);
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

    
    changeTaskState(task,state){
        for(let i=0;i<this.ToDoList.length;i++){
            if(this.ToDoList[i].name.toLowerCase===task.toLowerCase){
                this.ToDoList[i].state = state;
                break;
            }
        }
    }
};

const currentList = new ToDoList(1234567890,"Current List");
currentList.addTask(1,"taska");